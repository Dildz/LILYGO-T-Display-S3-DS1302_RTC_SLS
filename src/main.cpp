/*************************************************************
******************* INCLUDES & DEFINITIONS *******************
**************************************************************/

#include <Arduino.h>
#include <TFT_eSPI.h>
#include <ThreeWire.h>
#include <RtcDS1302.h>
#include <WiFiManager.h>

#include "LV_Helper.h"
#include "ui.h"
#include "pins.h"

// Built-in buttons
#define bootBTN  PIN_BUTTON_1
#define keyBTN   PIN_BUTTON_2

// RTC Module connections
#define RST  PIN_GPIO_3
#define DAT  PIN_GPIO_13
#define CLK  PIN_GPIO_12


// Startup flag
bool firstStart = true;

// NTP settings
const char* ntpServer = "pool.ntp.org";
//#################### EDIT THIS SECTION ###################
const long gmtOffset = 2; // adjust for your timezone
const int dstOffset = 0;  // adjust for daylight saving
//##########################################################

// Initialize RtcDS1302
ThreeWire myWire(DAT, CLK, RST); // IO, SCLK, CE
RtcDS1302<ThreeWire> Rtc(myWire);

// Initialize TFT display
TFT_eSPI lcd = TFT_eSPI();

// Brightness control variables
const int brightnessLevels[] = {80, 120, 160, 200, 240}; // brightness levels array
int currentBrightnessIndex = 2; // start in the middle (160)
int currentBrightness = brightnessLevels[currentBrightnessIndex]; // initial brightness

// Button states
bool lastBootBtnState = HIGH;
bool lastKeyBtnState = HIGH;
byte debounceDelay = 20;

// Wi-Fi related variables
bool wifiConnected = false;
unsigned long wifiReconnectAttempt = 3; // 3 retries
const unsigned long wifiReconnectInterval = 10; // 10 seconds

// IP address as a string
String ipString = "";

// NTP sync variables
unsigned long lastNTPSync = 0;
const unsigned long ntpSyncInterval = 3600000; // 1 hour
bool ntpSyncSuccess = false;

// NTP sync states
enum SyncState {
  SYNC_FAILED,
  SYNC_SUCCESS
};
SyncState rtcSyncState = SYNC_FAILED; // start in failed state until first successful sync
String lastResponseTime = "NEVER";    // store the last response string


/*************************************************************
********************** HELPER FUNCTIONS **********************
**************************************************************/

// Function to sync RTC with NTP server
bool syncRTCWithNTP() {
  configTime(gmtOffset * 3600, dstOffset * 3600, ntpServer);
  
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo, 10000)) { // Increased timeout to 10s
    Serial.println("NTP sync failed - couldn't get local time");
    return false;
  }

  // Validate received time
  if (timeinfo.tm_year < 120) { // Year 2020 or later
    Serial.println("NTP sync failed - invalid year received");
    return false;
  }

  RtcDateTime ntpTime(
    timeinfo.tm_year + 1900,
    timeinfo.tm_mon + 1,
    timeinfo.tm_mday,
    timeinfo.tm_hour,
    timeinfo.tm_min,
    timeinfo.tm_sec
  );
  
  // SetDateTime doesn't return a value, so we'll assume success if we get here
  Rtc.SetDateTime(ntpTime);
  
  char syncTimeStr[9];
  snprintf(syncTimeStr, sizeof(syncTimeStr), "%02d:%02d:%02d", 
           timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec);
  lastResponseTime = syncTimeStr;
  
  Serial.println("NTP sync successful");
  return true;
}

// Get day of week as 3-letter abbreviation
String getDayOfWeekString() {
  RtcDateTime now = Rtc.GetDateTime();
  const char* daysOfWeek[] = {"SUN.", "MON.", "TUE.", "WED.", "THU.", "FRI.", "SAT."};
  return daysOfWeek[now.DayOfWeek()];
}

// Get date as a string
String getDateString() {
  RtcDateTime now = Rtc.GetDateTime();
  char buf[11];
  snprintf(buf, sizeof(buf), "%02d/%02d/%04d",
           now.Day(), now.Month(), now.Year());
  return String(buf);
}

// Get seperate time components
void getTimeComponents(int &hours, int &minutes, int &seconds) {
  RtcDateTime now = Rtc.GetDateTime();
  hours = now.Hour();
  minutes = now.Minute();
  seconds = now.Second();
}

// Function to update time with flashing colon
void updateTime() {
  static unsigned long lastUpdate = 0;
  static bool colonVisible = true;
  const unsigned long updateInterval = 500; // colon blink period
  
  if (millis() - lastUpdate >= updateInterval) {
    if (Rtc.IsDateTimeValid()) {
      int hours, minutes, seconds;
      getTimeComponents(hours, minutes, seconds);
      
      // Update hour label (always visible)
      char hourStr[3];
      snprintf(hourStr, sizeof(hourStr), "%02d", hours);
      lv_label_set_text(ui_timeH, hourStr);
      
      // Update minute label (always visible)
      char minStr[3];
      snprintf(minStr, sizeof(minStr), "%02d", minutes);
      lv_label_set_text(ui_timeM, minStr);
      
      // Update second label (always visible)
      char secStr[3];
      snprintf(secStr, sizeof(secStr), "%02d", seconds);
      lv_label_set_text(ui_timeS, secStr);
      
      // Toggle colon visibility
      colonVisible = !colonVisible;
      lv_obj_set_style_opa(ui_timeColon, colonVisible ? LV_OPA_100 : LV_OPA_0, LV_PART_MAIN);
    }
    else {
      // If RTC isn't valid, show default values
      lv_label_set_text(ui_timeH, "00");
      lv_label_set_text(ui_timeM, "00");
      lv_label_set_text(ui_timeS, "00");
      lv_obj_set_style_opa(ui_timeColon, LV_OPA_100, LV_PART_MAIN);
    }
    lastUpdate = millis();
  }
}

// Function to update date labels
void updateDate() {
  static unsigned long lastDateUpdate = 0;
  const unsigned long dateUpdateInterval = 1000; // update date once per sec

  // Upadate immediatly on startup
  if (firstStart) {
    if (Rtc.IsDateTimeValid()) {
      RtcDateTime now = Rtc.GetDateTime();
      
      // Update day of week label
      lv_label_set_text(ui_day, getDayOfWeekString().c_str());
      
      // Update date label (format: dd mm yyyy)
      char dateStr[11];
      snprintf(dateStr, sizeof(dateStr), "%02d-%02d-%04d", now.Day(), now.Month(), now.Year());
      lv_label_set_text(ui_date, dateStr);
    }
    else {
      lv_label_set_text(ui_day, "DAY.");
      lv_label_set_text(ui_date, "DD-MM-YYYY");
    }
    lastDateUpdate = millis();
    firstStart = false;
  }
  
  // Update every 1min
  if (millis() - lastDateUpdate >= dateUpdateInterval) {
    if (Rtc.IsDateTimeValid()) {
      RtcDateTime now = Rtc.GetDateTime();
      
      // Update day of week label
      lv_label_set_text(ui_day, getDayOfWeekString().c_str());
      
      // Update date label (format: dd mm yyyy)
      char dateStr[11];
      snprintf(dateStr, sizeof(dateStr), "%02d-%02d-%04d", now.Day(), now.Month(), now.Year());
      lv_label_set_text(ui_date, dateStr);
    }
    else {
      lv_label_set_text(ui_day, "DAY.");
      lv_label_set_text(ui_date, "DD-MM-YYYY");
    }
    lastDateUpdate = millis();
  }
}

// Function to check and maintain Wi-Fi connection
void checkWiFiStatus() {
  static unsigned long lastWiFiUpdate = 0;
  const unsigned long wifiUpdateInterval = 1000; // update every second
  
  if (millis() - lastWiFiUpdate >= wifiUpdateInterval) {
    if (WiFi.status() == WL_CONNECTED) {
      // Get RSSI value
      int rssi = WiFi.RSSI();
      
      // Update RSSI label with dBm value
      char rssiStr[10];
      snprintf(rssiStr, sizeof(rssiStr), "%d dBm", rssi);
      lv_label_set_text(ui_RSSI, rssiStr);
      
      // Determine WiFi icon color based on signal strength
      lv_color_t wifiColor;
      if (rssi >= -50) {
        wifiColor = lv_color_hex(0x00FF00); // Green - Excellent (>-50dBm)
      } 
      else if (rssi >= -60) {
        wifiColor = lv_color_hex(0x7CFC00); // Green-Yellow - Very good (-50 to -60dBm)
      }
      else if (rssi >= -70) {
        wifiColor = lv_color_hex(0xFFFF00); // Yellow - Okay (-60 to -70dBm)
      }
      else if (rssi >= -80) {
        wifiColor = lv_color_hex(0xFFA500); // Orange - Weak (-70 to -80dBm)
      }
      else {
        wifiColor = lv_color_hex(0xFF0000); // Red - Very weak (<-80dBm)
      }
      
      // Set the icon color
      lv_obj_set_style_img_recolor(ui_wifiImage, wifiColor, LV_PART_MAIN);
      lv_obj_set_style_img_recolor_opa(ui_wifiImage, LV_OPA_COVER, LV_PART_MAIN);

      // Only attempt NTP sync if WiFi is connected
      if (millis() - lastNTPSync >= ntpSyncInterval) {
        if (syncRTCWithNTP()) {
          lastNTPSync = millis();
          rtcSyncState = SYNC_SUCCESS;
          
          // Update UI after successful sync
          lv_label_set_text(ui_lastSyncTime, lastResponseTime.c_str());
          lv_obj_clear_flag(ui_rtcSynced, LV_OBJ_FLAG_HIDDEN);
          lv_obj_add_flag(ui_rtcFailed, LV_OBJ_FLAG_HIDDEN);
        }
        else {
          rtcSyncState = SYNC_FAILED;
          lv_obj_add_flag(ui_rtcSynced, LV_OBJ_FLAG_HIDDEN);
          lv_obj_clear_flag(ui_rtcFailed, LV_OBJ_FLAG_HIDDEN);
        }
      }
    } 
    else {
      // WiFi disconnected - set icon to black and show "Disconnected"
      lv_obj_set_style_img_recolor(ui_wifiImage, lv_color_hex(0x000000), LV_PART_MAIN);
      lv_obj_set_style_img_recolor_opa(ui_wifiImage, LV_OPA_COVER, LV_PART_MAIN);
      lv_label_set_text(ui_RSSI, "Disconnected");
      
      // Attempt to reconnect periodically
      static unsigned long lastReconnectAttempt = 0;
      if (millis() - lastReconnectAttempt >= 10000) { // Try every 10 seconds
        lastReconnectAttempt = millis();
        WiFi.reconnect();
      }
    }
    lastWiFiUpdate = millis();
  }
}

// Function to check for button presses
void checkButtons() {
  static bool lastBootBtnState = HIGH;
  static bool lastKeyBtnState = HIGH;
  static unsigned long lastDebounceTime = 0;
  
  bool bootBtnState = digitalRead(bootBTN);
  bool keyBtnState = digitalRead(keyBTN);

  // Check for button press (falling edge detection)
  if ((bootBtnState == LOW && lastBootBtnState == HIGH) || 
      (keyBtnState == LOW && lastKeyBtnState == HIGH)) {
    if (millis() - lastDebounceTime > debounceDelay) {
      // Boot button pressed - decrease brightness
      if (bootBtnState == LOW) {
        if (currentBrightnessIndex > 0) { // only decrease if not at minimum
          currentBrightnessIndex--;
          currentBrightness = brightnessLevels[currentBrightnessIndex];
          analogWrite(PIN_LCD_BL, currentBrightness);
        }
      }
      
      // Key button pressed - increase brightness
      if (keyBtnState == LOW) {
        if (currentBrightnessIndex < (sizeof(brightnessLevels)/sizeof(brightnessLevels[0]) - 1)) { // only increase if not at maximum
          currentBrightnessIndex++;
          currentBrightness = brightnessLevels[currentBrightnessIndex];
          analogWrite(PIN_LCD_BL, currentBrightness);
        }
      }
      lastDebounceTime = millis();
    }
  }

  // Update last button states
  lastBootBtnState = bootBtnState;
  lastKeyBtnState = keyBtnState;

  // Update brighness bar value
  lv_bar_set_value(ui_brightnessBar, currentBrightness, LV_ANIM_ON);
}


/*************************************************************
*********************** MAIN FUNCTIONS ***********************
**************************************************************/

// SETUP
void setup() {
  // Initialize buttons pins
  pinMode(bootBTN, INPUT_PULLUP);
  pinMode(keyBTN, INPUT_PULLUP);

  // Initialize display pins
  pinMode(PIN_POWER_ON, OUTPUT);
  digitalWrite(PIN_POWER_ON, HIGH);

  // Initialize display
  lcd.init();
  lcd.setRotation(1);                  // landscape
  ledcSetup(0, 10000, 8);              // 10kHz PWM frequency
  analogWrite(PIN_LCD_BL, 100);        // display brightness (100/255)
  lcd.fillScreen(TFT_BLACK);           // clear screen
  lcd.setTextColor(0x7BCF, TFT_BLACK); // converted from #787878

  // Display initial message
  lcd.println("\nConnecting to Wi-Fi - please wait...\n");

  // Create an instance of WiFiManager
  WiFiManager wifiManager;
  wifiManager.setConnectTimeout(10);
  wifiManager.setConnectRetries(3);
  wifiManager.setConfigPortalTimeout(0);
  
  // Callback for config portal
  wifiManager.setAPCallback([](WiFiManager *wm) {
    lcd.println("AP unreachable or not yet configured.\n\n");
    lcd.println("A Wi-Fi network has been created:\n");
    lcd.println("SSID:     T-Display-S3\n");
    lcd.println("Password: 123456789\n\n");
    lcd.println("Connect and navigate to: 192.168.4.1\n");
    lcd.println("in a browser to setup your Wi-Fi.\n\n");
  });

  // Callback for a saved config
  wifiManager.setSaveConfigCallback([]() {
    lcd.println("Configuration saved, rebooting...");
    delay(2000);
    ESP.restart();
  });

  // This will block until connected to saved network or after config
  wifiManager.autoConnect("T-Display-S3", "123456789");

  // Wi-Fi connected :)
  lcd.println("WiFi Connected! :)\n");
  lcd.print("SSID: ");
  lcd.println(WiFi.SSID());
  lcd.print("IP: ");
  lcd.println(WiFi.localIP());
  ipString = (WiFi.localIP().toString()); // update IP address string
  delay(2000);

  // Initialize RTC
  Rtc.Begin();

  // RTC message
  lcd.println("\nValidating RTC module...\n");
  delay(1000);

  // Validate RTC module date/time
  RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);

  if (!Rtc.IsDateTimeValid()) {
    lcd.println("RTC lost confidence in the DateTime!\nUsing compiled time\n");
    Rtc.SetDateTime(compiled);
  }
  else {
    lcd.println("RTC DateTime is valid\n");
  }

  if (Rtc.GetIsWriteProtected()) {
    lcd.println("RTC was write protected, enabling writing now\n");
    Rtc.SetIsWriteProtected(false);
  }

  if (!Rtc.GetIsRunning()) {
    lcd.println("RTC was not actively running, starting now\n");
    Rtc.SetIsRunning(true);
  }

  // Attempt to sync RTC with NTP server
  lcd.println("Attempting initial NTP sync...\n");

  bool syncSuccess = false;
  int retryCount = 0;
  const int maxRetries = 3;

  while (!syncSuccess && retryCount < maxRetries) {
    lcd.printf("Attempt %d of %d\n", retryCount + 1, maxRetries);
    syncSuccess = syncRTCWithNTP();
    
    if (syncSuccess) {
      rtcSyncState = SYNC_SUCCESS;
      lcd.println("NTP sync successful!\n");
      lastNTPSync = millis();
    } else {
      retryCount++;
      delay(5000); // Increased delay between retries
    }
  }

  if (!syncSuccess) {
    rtcSyncState = SYNC_FAILED;
    lastResponseTime = "compiled";
    lcd.println("Failed to sync with NTP server\n");
    lcd.println("Using compiled time\n");
    
    // Set RTC to compiled time
    RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
    Rtc.SetDateTime(compiled);
  }
  delay(2000);

  lcd.println("Starting main display...");
  delay(2000);
  lcd.fillScreen(TFT_BLACK);

  // Initialize hardware
  lv_helper();
  ui_init();

  // Update IP address label
  lv_label_set_text(ui_IPadd, ipString.c_str());

  // Update sync status labels
  if (rtcSyncState == SYNC_SUCCESS) {
    lv_obj_clear_flag(ui_rtcSynced, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_rtcFailed, LV_OBJ_FLAG_HIDDEN);
  }
  else {
    lv_obj_add_flag(ui_rtcSynced, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui_rtcFailed, LV_OBJ_FLAG_HIDDEN);
  }
  lv_label_set_text(ui_lastSyncTime, lastResponseTime.c_str());
}

// MAIN LOOP
void loop() {
  lv_task_handler();

  checkButtons();
  checkWiFiStatus();
  
  updateTime();
  updateDate();
  
  lv_refr_now(NULL); // force refresh
}
