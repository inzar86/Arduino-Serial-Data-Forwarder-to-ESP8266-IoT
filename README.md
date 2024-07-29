# Arduino-Serial-Data-Forwarder-to-ESP8266-IoT
Sending data from Arduino via serial communication to be forwarded by ESP IoT

ESP8266 has 1 Analog Input, so.. I forward Multiple sensor data from arduino (Ex. Arduino Uno) over serial communication to ESP8266 and push it to Firebase

Arduino Side :
1. Collect sensor data from analog port or other pin,
2. Print it using Serial using this format `data1,data2,data3,X`, data1 is sensor 1, data2 is sensor 2, data3 is sensor 3 then after comma separator print `"X"` then (enter) in arduino use `Serial.println("X");`.
3. example implementation bellow.
   ``` C
   Serial.print(data1);
   Serial.print(",");
   Serial.print(data2);
   Serial.print(",");
   Serial.print(data3);
   Serial.print(",");
   Serial.println("X");
   ```
4. Done.

Esp8266 Side :
1. Read incoming serial data from arduino. use array for data stream.
2. send it to Firebase
``` C

int data[3];

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
           for(int i=0;i<3;i++)
           {
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
```
3. done

Enjoy All your arduino pin to IoT.
