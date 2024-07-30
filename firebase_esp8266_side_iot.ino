#include "FirebaseESP8266.h"  // Install Firebase ESP8266 library
#include <ESP8266WiFi.h>

#define FIREBASE_HOST "Realtime database link here example:project1234-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "Realtime database secret code here example:cKGpr86lq5sLRrEdW6n9djsfhjgdsdhabjjabhbcaj"
#define WIFI_SSID "YourSSID or Accespoint"
#define WIFI_PASSWORD "yourWifiPassword"

//Define FirebaseESP8266 data object
FirebaseData Data;

FirebaseJson json;

String simpandata = "";
String perintah;

int sensor1, sensor2, sensor3;
int num_data=3; // change this for how much variable

String inputString = "";         // a String to hold incoming data
boolean stringComplete = false;  // whether the string is complet

int data[num_data];
int urutan;

void setup() {
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(300);
  }

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
}

void loop() {

  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    if (inChar == ',') {
      data[urutan] = inputString.toFloat();
      inputString = "";
      urutan++;
      inChar = 0;
      goto jump;
    }
    // add it to the inputString:
    inputString += inChar;
jump:

    if (inChar == 'X') {
      for (int i = 0; i < num_data; i++) {
        Serial.print(data[i]);
        Serial.print(",");
      }

      // clear the string:
      urutan = 0;
      inputString = "";

      // For running
      sensor1 = data[0];
      sensor2 = data[1];
      sensor3 = data[2];

      Firebase.setString(Data, "/yourFirebaseProjectBucket/yourFirebaseVariable1", (String)sensor1);
      Firebase.setString(Data, "/yourFirebaseProjectBucket/yourFirebaseVariable2", (String)sensor2);
      Firebase.setString(Data, "/yourFirebaseProjectBucket/yourFirebaseVariable3", (String)sensor3);
      delay(1000);
    }
  }
}
