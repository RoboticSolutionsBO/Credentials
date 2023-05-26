#ifndef Credentials_h
#define Credentials_h

#include <Arduino.h>
#include <EEPROM.h>
#define EEPROM_SIZE 256
#define WORD_MAX_SIZE 32
#define ADDRESS_SSID 0
#define ADDRESS_SSID_PASSWORD 32
#define ADDRESS_EMAIL 64
#define ADDRESS_EMAIL_PASSWORD 128
#define ADDRESS_USER_ID 160
#define ADDRESS_DEVICE_ID 192

class Credentials {
    private:
        bool _setSSID(char* ssid);
        bool _setSSIDPassword(char* password);
        bool _setEmail(char* email);
        bool _setEmailPassword(char* password);
        bool _setUserId(char* userId);
        bool _clearSSID();
        bool _clearSSIDPassword();
        bool _clearEmail();
        bool _clearEmailPassword();
        bool _clearUserId();
    public:
        Credentials();
        void begin();
        char* getSSID();
        char* getSSIDPassword();
        char* getEmail();
        char* getEmailPassword();
        char* getUserId();
        char* getDeviceId();
        bool setDeviceId(char* deviceId);
        bool setWiFiCredentials(char* ssid, char* password);
        bool setAccountCredentials(char* email, char* password);
        bool setAccountCredentials(char* email, char* password, char* userId);
        bool clear();
        bool clearAll();
};

#endif
