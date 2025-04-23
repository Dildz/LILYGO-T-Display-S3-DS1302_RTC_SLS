# LILYGO T-Display-S3 DS1302 RTC Module Project with SquareLine Studio UI

## Description:
This code implements a NTP-synchronized real-time clock with a modern UI created in SquareLine Studio, displaying time, date, and system information on the LilyGO T-Display-S3's built-in screen.

## How it works:
- **Modern UI Interface**:
  - Designed with SquareLine Studio
  - Animated 7 segment time display
  - Visual indicators for sync status and Wi-Fi strength

- **Core Functionality**:
  - Wi-Fi connection management using WiFiManager
  - NTP time synchronization (every hour)
  - Local timekeeping with DS1302 RTC module
  - Brightness control with physical buttons
  - Configuration portal mode via 5sec press of both buttons

- **Displayed Information**:
  - Selected GMT & DST offsets
  - Current time (HH:MM ss) with blinking colon
  - Date (DD-MM-YYYY) and day of week
  - Last NTP sync time and status indicator
  - Wi-Fi signal (RSSI) strength (dBm) with colour-changing Wi-Fi icon
  - Device IP address
  - FPS (locked at 30)
  - CPU temperature

## Pin Connections:
- VCC -> 5V
- GND -> GND
- RST -> GPIO3
- DAT -> GPIO13
- CLK -> GPIO12

## DS1302 Specifications:
- **Type**: RTC (Real-Time Clock)
- **Protocol**: 3-wire serial interface
- **Timekeeping Range**: Seconds to Year (up to 2100)
- **Accuracy**: ±2ppm (with quality 32.768kHz crystal)
- **Operating Voltage**: 2.0V to 5.5V
- **Temperature Range**: -40°C to 85°C

## Notes:
1. **LVGL config**:
  - PlatformIO will automatically download the libraries listed in the **platformio.ini** file when the project is opened for the 1st time
  - In the **'.pio\libdeps\lilygo-t-display-s3\lvgl'** folder - find & copy **'lv_conf_template.h'** to **'.pio\libdeps\lilygo-t-display-s3'**
  - Rename **'.pio\libdeps\lilygo-t-display-s3\lv_conf_template.h'** to **'.pio\libdeps\lilygo-t-display-s3\lv_conf.h'**
  - Open **'.pio\libdeps\lilygo-t-display-s3\lv_conf.h'** and modify these lines:
    - Line 15: **#if 0 /*Set it to "1" to enable content*/** >> as the comment says - **set it to 1**
    - Line 30: **#define LV_COLOR_16_SWAP 0** >> **set to 1**
    - Line 364, 365, 366: **#define LV_FONT_MONTSERRAT_8  0** >> **set font sizes 8, 10 & 12 to 1**
    - If any additional MONTSERRAT font sizes are used if you modify the SLS project then you will need to set them to 1 as well

2. **TFT_eSPI config**:
  - In the **'.pio\libdeps\lilygo-t-display-s3\TFT_eSPI'** folder - find **'User_Setup_Select.h'** and modify these lines:
    - Line 27: **#include <User_Setup.h>** >> comment out this line (**//#include <User_Setup.h>** )
    - Line 133: **//#include <User_Setups/Setup206_LilyGo_T_Display_S3.h>** >> uncomment this line (**#include <User_Setups/Setup206_LilyGo_T_Display_S3.h>** )
  
2. **First Run**:
  - Device will start Wi-Fi configuration portal if no known networks are available
  - Connect to **"T-Display-S3"** AP with password: **123456789**
  - Configure Wi-Fi through web interface at **192.168.4.1**
    - Enter your Wi-Fi AP & password,
    - GMT Offset (-12 to +14)
    - DST Offset (0 or 1)

3. **Normal Operation**:
  - Time will automatically sync with NTP server on connection
  - RTC maintains time between syncs
  - Use buttons to adjust screen brightness:
    - Left (BOOT) button: Decrease brightness
    - Right (KEY) button: Increase brightness
  - To change a Wi-Fi access point / GMT or DST offsets, start the configuration portal by:
    - pressing both left & right buttons together for 5seconds
    - connect to **"T-Display-S3"** AP with password: **123456789**
    - renter your Wi-Fi AP / GMT / DST info and save to reboot.

4. **SLS Project Files**:
  - This repository includes the SquareLine Studio project files in: **'.\LILYGO-T-Display-S3-DS1302_RTC_SLS\sls_files'**
  - In the **'sls_files'** folder, there are 2 subfolders: **'export'** & **'project'**
  - Open SquareLine_Project in the **'project'** folder with Squareline Studio to make changes to the UI.
  - You may need to update the SLS project settings **Project Export Root** and **UI Files Export Path** locations to reflect where you have saved the PlaformIO project **before exporting**.
  - Export project files to the **'export'** folder and copy all, then replace all files in the **'src'** folder.
  - **Do not export into the 'src' folder as SLS will erase the folder contents before exporting!**
  - Clean the PlatformIO project (PlatfomIO: Clean).
  - Build to check for errors & upload (TFT_eSPI warnings about TOUCH_CS pin etc can be ignored - this is a non-touch display).
  - **NB!!** Every time a change is made in SLS, and the UI files have been replaced in PlatformIO **'src'** folder - you **must first clean the project before building/uploading** otherwise your changes will not take effect.

## Issues:
  - Noticed a bug with screen brightness. Start value is 160 (range 80 to 240) with inc/dec step values of 40.
    - on 1st press of inc, brightness will decrease by what seems like a single step (40),
    - on 1st press of dec, brightness will decrease by what seems like 2 steps (80),
    - subsequent inc/dec presses behave as expected.
  - I've spent too much time already troubleshooting this, and while it is annoying - it works, so I'll leave it as is for now.