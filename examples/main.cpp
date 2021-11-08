#include <Credentials.h>

Credentials credentials;

const int delayTime = 5000;
long int pastTime = 0;

void setupCredencials(void);
char* readSerial(const char* label);

void setup() {
    credentials.begin();
    Serial.begin(115200);
    setupCredencials();
    pinMode(D5, INPUT);
    pastTime = millis();
}

void loop() {
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
        Serial.println(credentials.getUserId());
    }
    if (digitalRead(D5)) {
        Serial.println(F("Credentials Cleared"));
        credentials.clear();
        Serial.println(F("Now Restarting"));
    }
}

void setupCredencials(void) {
    char ssid[WORD_MAX_SIZE];
    char ssidPassword[WORD_MAX_SIZE];
    char email[WORD_MAX_SIZE];
    char emailPassword[WORD_MAX_SIZE];
    char userId[WORD_MAX_SIZE];
    strcpy(ssid, readSerial("SSID:"));
    strcpy(ssid, readSerial("SSID Password:"));
    strcpy(ssid, readSerial("Email:"));
    strcpy(ssid, readSerial("Email Password:"));
    strcpy(ssid, readSerial("User Id:"));
    credentials.setWiFiCredentials(ssid, ssidPassword);
    credentials.setFirebaseCredentials(email, emailPassword, userId);
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
