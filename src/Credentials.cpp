#include "Credentials.h"

Credentials::Credentials() {};

void Credentials::begin() {
    EEPROM.begin(eepromSize);
}

bool Credentials::_setSSID(char* ssid) {
    for (size_t i = 0; i < strlen(ssid); i++) {
        EEPROM.write(addressSsid + i, ssid[i]);
    }
    return EEPROM.commit();
}

bool Credentials::_setSSIDPassword(char* password) {
    for (size_t i = 0; i < strlen(password); i++) {
        EEPROM.write(addressSsidPassword + i, password[i]);
    }
    return EEPROM.commit();
}

bool Credentials::_setEmail(char* email) {
    for (size_t i = 0; i < strlen(email); i++) {
        EEPROM.write(addressEmail + i, email[i]);
    }
    return EEPROM.commit();
}

bool Credentials::_setEmailPassword(char* password) {
    for (size_t i = 0; i < strlen(password); i++) {
        EEPROM.write(addressEmailPassword + i, password[i]);
    }
    return EEPROM.commit();
}

bool Credentials::_setUserId(char* userId) {
    for (size_t i = 0; i < strlen(userId); i++) {
        EEPROM.write(addressUserId + i, userId[i]);
    }
    return EEPROM.commit();
}

bool Credentials::_clearSSID() {
    for (size_t i = 0; i < wordMaxSize; i++) {
        EEPROM.write(addressSsid + i, 0);
    }
    return EEPROM.commit();
}

bool Credentials::_clearSSIDPassword() {
    for (size_t i = 0; i < wordMaxSize; i++) {
        EEPROM.write(addressSsidPassword + i, 0);
    }
    return EEPROM.commit();
}

bool Credentials::_clearEmail() {
    for (size_t i = 0; i < wordMaxSize; i++) {
        EEPROM.write(addressEmail + i, 0);
    }
    return EEPROM.commit();
}

bool Credentials::_clearEmailPassword() {
    for (size_t i = 0; i < wordMaxSize; i++) {
        EEPROM.write(addressEmailPassword + i, 0);
    }
    return EEPROM.commit();
}

bool Credentials::_clearUserId() {
    for (size_t i = 0; i < wordMaxSize; i++) {
        EEPROM.write(addressUserId + i, 0);
    }
    return EEPROM.commit();
}

char* Credentials::getSSID() {
    char* ssid = new char[wordMaxSize];
    for (uint8_t i = 0; i < wordMaxSize; i++) {
        ssid[i] = char(EEPROM.read(addressSsid + i));
    }
    return ssid;
}

char* Credentials::getSSIDPassword() {
    char* password = new char[wordMaxSize];
    for (uint8_t i = 0; i < wordMaxSize; i++) {
        password[i] = char(EEPROM.read(addressSsidPassword + i));
    }
    return password;
}

char* Credentials::getEmail() {
    char* email = new char[wordMaxSize];
    for (uint8_t i = 0; i < wordMaxSize; i++) {
        email[i] = char(EEPROM.read(addressEmail + i));
    }
    return email;
}

char* Credentials::getEmailPassword() {
    char* password = new char[wordMaxSize];
    for (uint8_t i = 0; i < wordMaxSize; i++) {
        password[i] = char(EEPROM.read(addressEmailPassword + i));
    }
    return password;
}

char* Credentials::getUserId() {
    char* userId = new char[wordMaxSize];
    for (uint8_t i = 0; i < wordMaxSize; i++) {
        userId[i] = char(EEPROM.read(addressUserId + i));
    }
    return userId;
}

char* Credentials::getDeviceId() {
    char* deviceId = new char[wordMaxSize];
    for (uint8_t i = 0; i < wordMaxSize; i++) {
        deviceId[i] = char(EEPROM.read(addressDeviceId + i));
    }
    return deviceId;
}

bool Credentials::setDeviceId(char* deviceId) {
    for (size_t i = 0; i < wordMaxSize; i++) {
        if (i < strlen(deviceId)) {
            EEPROM.write(addressDeviceId + i, deviceId[i]);
        } else {
            EEPROM.write(addressDeviceId + i, 0);
        }
    }
    return EEPROM.commit();
}

bool Credentials::setWiFiCredentials(char* ssid, char* password) {
    if (_clearSSID() && _clearSSIDPassword()) {
        if (_setSSID(ssid) && _setSSIDPassword(password)) {
            return true;
        }
    }
    return false;
}

bool Credentials::setAccountCredentials(char* email, char* password) {
    if (_clearEmail() && _clearEmailPassword() && _clearUserId()) {
        if (_setEmail(email) && _setEmailPassword(password)) {
            return true;
        }
    }
    return false;
}

bool Credentials::setAccountCredentials(char* email, char* password, char* userId) {
    if (_clearEmail() && _clearEmailPassword() && _clearUserId()) {
        if (_setEmail(email) && _setEmailPassword(password) && _setUserId(userId)) {
            return true;
        }
    }
    return false;
}

bool Credentials::clear() {
    if (_clearSSID() && _clearSSIDPassword() && _clearEmail() && _clearEmailPassword() && _clearUserId()) {
        return true;
    }
    return false;
}

bool Credentials::clearAll() {
    for (uint8_t i = 0; i < eepromSize; i++) {
        EEPROM.write(i, 0);
    }
    return EEPROM.commit();
}
