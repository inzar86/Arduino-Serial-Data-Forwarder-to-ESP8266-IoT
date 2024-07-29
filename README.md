# Arduino-Serial-Data-Forwarder-to-ESP8266-IoT
Sending data from Arduino via serial communication to be forwarded by ESP IoT

ESP8266 has 1 Analog Input, so.. I forward Multiple sensor data from arduino (Ex. Arduino Uno) over serial communication to ESP8266 and push it to Firebase

Arduino Side :
1. Collect sensor data from analog port or other pin,
2. Print it using Serial using this format `data1,data2,data3,X`, data1 is sensor 1, data2 is sensor 2, data3 is sensor 3 then after comma separator print `"X"` then (enter) in arduino use `Serial.println("X");`.
3. example implementation bellow.
   ``` C++
   Serial.print(data1);
   Serial.print(",");
   Serial.print(data2);
   Serial.print(",");
   Serial.print(data3);
   Serial.print(",");
   Serial.println("X");
   ```
