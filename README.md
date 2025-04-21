# LILYGO T-Display-S3 DS1302 RTC Module Project with SquareLine Studio UI

## Description:
This code implements a NTP-synchronized real-time clock with a modern UI created in SquareLine Studio, displaying time, date, and system information on the LilyGO T-Display-S3's built-in screen.

## How it works:
- **Modern UI Interface**:
  - Designed with SquareLine Studio
  - Animated 7 segment time display
  - Visual indicators for sync status and WiFi strength

- **Core Functionality**:
  - WiFi connection management using WiFiManager
  - NTP time synchronization (every hour)
  - Local timekeeping with DS1302 RTC module
  - Brightness control with physical buttons

- **Displayed Information**:
  - Current time (HH:MM:SS) with blinking colon
  - Date (DD-MM-YYYY) and day of week
  - Last NTP sync time and status indicator
  - WiFi signal strength (dBm) with colour-changing Wi-Fi icon
  - Device IP address

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
1. **First Run**:
   - Device will start WiFi configuration portal if no known networks are available
   - Connect to "T-Display-S3" AP with password: 123456789
   - Configure WiFi through web interface at 192.168.4.1

2. **Normal Operation**:
   - Time will automatically sync with NTP server on connection
   - RTC maintains time between syncs
   - Use buttons to adjust screen brightness:
     - Left button: Decrease brightness
     - Right button: Increase brightness

3. **SLS Project Files**:
   - This repository includes the SquareLine Studio project files in: '...\LILYGO-T-Display-S3-DS1302_RTC_SLS\sls_files'
   - In the 'sls_files' folder, there are 2 subfolders: 'export' & 'project'
   - Open SquareLine_Project in the 'project' folder with Squareline Studio to make changes to the UI.
   - Export project files to the 'export' folder and copy all, then replace all files in the 'src' folder.
   - **Do not export into the 'src' folder as SLS will erase the folder contents before exporting!**
   - Clean the PlatformIO project (PlatfomIO: Clean).
   - Build to check for errors & upload.
