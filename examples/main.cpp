#include <Credentials.h>

Credentials credentials;

constexpr int delayTime{5000};
long int pastTime = 0;

void setupCredencials();
char* readSerial(const char* label);

int option = 2;

void setup() {
    credentials.begin();
    Serial.begin(115200);
    delay(5000);
    Serial.println();
    pinMode(D3, INPUT_PULLUP);
    pastTime = millis();
}

void loop() {
    if (option == 2) {
        Serial.print(F(("Update Credentials: ")));
        while(Serial.available() == 0) {
        }
        option = Serial.parseInt();
        Serial.println(option);
        if (option == 1) {
            setupCredencials();
        }    
    }
    if (millis() - pastTime > delayTime) {
        pastTime = millis();
        Serial.print(F("SSID: "));
        Serial.println(credentials.getSSID());
        Serial.print(F("SSID Password: "));
        Serial.println(credentials.getSSIDPassword());
        Serial.print(F("Email: "));
        Serial.println(credentials.getEmail());
        Serial.print(F("Email Passowrd: "));
        Serial.println(credentials.getEmailPassword());
        Serial.print(F("User Id: "));
        if (strlen(credentials.getUserId()) == 0) {
            Serial.println(F("*Not Set*"));
        } else {
            Serial.println(credentials.getUserId());
        }
        Serial.print(F("Device Id: "));
        if (strlen(credentials.getDeviceId()) == 0) {
            Serial.println(F("*Not Set*"));
        } else {
            Serial.println(credentials.getDeviceId());
        }
    }
    if (!digitalRead(D3)) {
        Serial.println(F("Credentials Cleared"));
        credentials.clear();
        while (true) {
            Serial.println(F("Waiting for Restart..."));
            delay(1000);
        }
    }
}

void setupCredencials() {
    char ssid[WORD_MAX_SIZE];
    char ssidPassword[WORD_MAX_SIZE];
    char email[WORD_MAX_SIZE];
    char emailPassword[WORD_MAX_SIZE];
    char userId[WORD_MAX_SIZE];
    // char deviceId[WORD_MAX_SIZE];
    strcpy(ssid, readSerial("SSID:"));
    strcpy(ssidPassword, readSerial("SSID Password:"));
    strcpy(email, readSerial("Email:"));
    strcpy(emailPassword, readSerial("Email Password:"));
    strcpy(userId, readSerial("User Id:"));
    if (strcmp(userId, "no") == 0) {
        Serial.println("UserId not Available");
        credentials.setWiFiCredentials(ssid, ssidPassword);
        credentials.setAccountCredentials(email, emailPassword);
    } else {
        Serial.println("UserId Available");
        credentials.setWiFiCredentials(ssid, ssidPassword);
        credentials.setAccountCredentials(email, emailPassword, userId);
    }
    // strcpy(deviceId, readSerial("Device Id:"));
    // if (strcmp(deviceId, "no") != 0) {
    //     credentials.setDeviceId(deviceId);
    // }
}

char* readSerial(const char* label) {
    Serial.print(label);
    Serial.print(" ");
    bool readData = false;
    char* data = new char[WORD_MAX_SIZE];
    while (!readData) {
        if (Serial.available() > 0) {
            strcpy(data, Serial.readString().c_str());
            readData = true;
        }
    }
    Serial.println(data);
    return data;
}
