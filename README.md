# Credentials
Credentials manager for Arduino based projects using EEPROM (also works with esp8266 and esp32). This tool will help you to store "permanently" different credentials that could be needed in your project.

The credentials currently supported to be stored are: **WiFi** (SSID and password), **Account** (email, password and an optional user id) and **Deveice Id**.

## Usage
### Initialization
```cpp
#include <Credentials.h>

Credentials credentials;
credentials.begin();
```

### WiFi
Store WiFi SSID and password crendetials:
```cpp
bool setWiFiCredentials((char* ssid, char* password);
```
Get WiFi SSID and password:
```cpp
char* getSSID(void);
char* getSSIDPassword(void);
```
### Account
Store an account email and password:
```cpp
bool setAccountCredentials(char* email, char* password);
```
Store an account email, password and user id:
```cpp
bool setAccountCredentials(char* email, char* password, char* userId);
```
Get email, password and user id (if is set):
```cpp
char* getEmail(void);
char* getEmailPassword(void);
char* getUserId(void);
```
### Device Id
Store a device id for the microcontroller:
```cpp
bool setDeviceId(char* deviceId);
```
Get device id:
```cpp
char* getDeviceId(void);
```
### Other
Clear WiFi and Account credentials
```cpp
bool clear(void);
```
Clear everything (use carefully, normally you won't want to delete de Device Id)
```cpp
bool clearAll(void);
```

## Dev using Platformio

### Init project
```bash
pio project init --board nodemcuv2
```
### Link the example main.cpp to src (this is optional)
```bash
cd src/
ln -s ../examples/main.cpp main.cpp
```

## TODO
- [x] Add example
- [ ] Improve example and add comments
- [ ] Make the library Arduino IDE friendly
- [x] Add development instructions
