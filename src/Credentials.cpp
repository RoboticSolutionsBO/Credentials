#include "Credentials.h"

Credentials::Credentials() {};

void Credentials::begin() {
    EEPROM.begin(EEPROM_SIZE);
}

bool Credentials::_setSSID(char* ssid) {
    for (size_t i = 0; i < strlen(ssid); i++) {
        EEPROM.write(ADDRESS_SSID + i, ssid[i]);
    }
    return EEPROM.commit();
}

bool Credentials::_setSSIDPassword(char* password) {
    for (size_t i = 0; i < strlen(password); i++) {
        EEPROM.write(ADDRESS_SSID_PASSWORD + i, password[i]);
    }
    return EEPROM.commit();
}

bool Credentials::_setEmail(char* email) {
    for (size_t i = 0; i < strlen(email); i++) {
        EEPROM.write(ADDRESS_EMAIL + i, email[i]);
    }
    return EEPROM.commit();
}

bool Credentials::_setEmailPassword(char* password) {
    for (size_t i = 0; i < strlen(password); i++) {
        EEPROM.write(ADDRESS_EMAIL_PASSWORD + i, password[i]);
    }
    return EEPROM.commit();
}

bool Credentials::_setUserId(char* userId) {
    for (size_t i = 0; i < strlen(userId); i++) {
        EEPROM.write(ADDRESS_USER_ID + i, userId[i]);
    }
    return EEPROM.commit();
}

bool Credentials::_clearSSID() {
    for (size_t i = 0; i < WORD_MAX_SIZE; i++) {
        EEPROM.write(ADDRESS_SSID + i, 0);
    }
    return EEPROM.commit();
}

bool Credentials::_clearSSIDPassword() {
    for (size_t i = 0; i < WORD_MAX_SIZE; i++) {
        EEPROM.write(ADDRESS_SSID_PASSWORD + i, 0);
    }
    return EEPROM.commit();
}

bool Credentials::_clearEmail() {
    for (size_t i = 0; i < WORD_MAX_SIZE; i++) {
        EEPROM.write(ADDRESS_EMAIL + i, 0);
    }
    return EEPROM.commit();
}

bool Credentials::_clearEmailPassword() {
    for (size_t i = 0; i < WORD_MAX_SIZE; i++) {
        EEPROM.write(ADDRESS_EMAIL_PASSWORD + i, 0);
    }
    return EEPROM.commit();
}

bool Credentials::_clearUserId() {
    for (size_t i = 0; i < WORD_MAX_SIZE; i++) {
        EEPROM.write(ADDRESS_USER_ID + i, 0);
    }
    return EEPROM.commit();
}

char* Credentials::getSSID() {
    char* ssid = new char[WORD_MAX_SIZE];
    for (uint8_t i = 0; i < WORD_MAX_SIZE; i++) {
        ssid[i] = char(EEPROM.read(ADDRESS_SSID + i));
    }
    return ssid;
}

char* Credentials::getSSIDPassword() {
    char* password = new char[WORD_MAX_SIZE];
    for (uint8_t i = 0; i < WORD_MAX_SIZE; i++) {
        password[i] = char(EEPROM.read(ADDRESS_SSID_PASSWORD + i));
    }
    return password;
}

char* Credentials::getEmail() {
    char* email = new char[WORD_MAX_SIZE];
    for (uint8_t i = 0; i < WORD_MAX_SIZE; i++) {
        email[i] = char(EEPROM.read(ADDRESS_EMAIL + i));
    }
    return email;
}

char* Credentials::getEmailPassword() {
    char* password = new char[WORD_MAX_SIZE];
    for (uint8_t i = 0; i < WORD_MAX_SIZE; i++) {
        password[i] = char(EEPROM.read(ADDRESS_EMAIL_PASSWORD + i));
    }
    return password;
}

char* Credentials::getUserId() {
    char* userId = new char[WORD_MAX_SIZE];
    for (uint8_t i = 0; i < WORD_MAX_SIZE; i++) {
        userId[i] = char(EEPROM.read(ADDRESS_USER_ID + i));
    }
    return userId;
}

char* Credentials::getDeviceId() {
    char* deviceId = new char[WORD_MAX_SIZE];
    for (uint8_t i = 0; i < WORD_MAX_SIZE; i++) {
        deviceId[i] = char(EEPROM.read(ADDRESS_DEVICE_ID + i));
    }
    return deviceId;
}

bool Credentials::setDeviceId(char* deviceId) {
    for (size_t i = 0; i < WORD_MAX_SIZE; i++) {
        if (i < strlen(deviceId)) {
            EEPROM.write(ADDRESS_DEVICE_ID + i, deviceId[i]);
        } else {
            EEPROM.write(ADDRESS_DEVICE_ID + i, 0);
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
    for (uint8_t i = 0; i < EEPROM_SIZE; i++) {
        EEPROM.write(i, 0);
    }
    return EEPROM.commit();
}
