#include <Servo.h>
  Servo myServo;
  int degree = 140;
  bool bareer = false;

void setup() {
  Serial.begin(9600);
  myServo.attach(D5);
  pinMode(D0, INPUT);
  myServo.write(degree);
}


void loop() {
  int ir = digitalRead(D0);
  if (ir == 0) {
    if(!bareer) {
      bareer = !bareer;
      degree = 30;
      myServo.write(degree);
    }
  } else {
    if(bareer) {
      degree = 140;
      bareer = !bareer;
      delay(10000);
      myServo.write(degree);
    }
  }
delay(100);
}
