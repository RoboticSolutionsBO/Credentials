#ifndef Credentials_h
#define Credentials_h

#include <Arduino.h>
#include <EEPROM.h>
constexpr uint8_t eepromSize{255};
constexpr uint8_t wordMaxSize{32};
constexpr uint8_t addressSsid{0};
constexpr uint8_t addressSsidPassword{32};
constexpr uint8_t addressEmail{64};
constexpr uint8_t addressEmailPassword{96};
constexpr uint8_t addressUserId{128};
constexpr uint8_t addressDeviceId{160};

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
