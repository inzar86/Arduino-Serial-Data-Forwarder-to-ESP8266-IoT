#include <MQ7.h>

// here Iam using MQ7 as example (you can use other sensor or dummy data like random)
MQ7 mq7(A0, 5.0);

float data1;
int data2;
int data3


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  //  // put your main code here, to run repeatedly:
  data1 = mq7.getPPM();    //real data from sensor MQ7
  data2 = random(0, 100);  // example random data tobe send to ESP over serial
  data3 = random(200, 300);

  Serial.print(data1);
  Serial.print(",");
  Serial.print(data2);
  Serial.print(",");
  Serial.print(data3);
  Serial.print(",");
  Serial.println("X");

  // give at leat 1 second delay for next sending.
  delay(max_delay);
}
