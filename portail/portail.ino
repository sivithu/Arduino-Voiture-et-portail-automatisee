// === Détecteur de distance à infrarouge MC0005 =======
// tiptopboards.com   18 08 2013
// ======================================================
// Exemple d'utilisation
// Régler le seuil du capteur avec la vis du potentiomètre
// visser pour seuil plus éloigné
// La LED rouge arrière s'allume si un obstacle dans la portée
// est détecté

#include <Servo.h>
  Servo myServo;
  int degree = 140;
  bool bareer = false;
  int val = 0;

void setup() {
  Serial.begin(9600);
  myServo.attach(D5);  // Servo motor // PIN
  Serial.print("essai de capteur IR");
  pinMode(D0,INPUT);  //Capteur IR sur pin-11 numérique
  myServo.write(degree);
  
}


void loop() {
  int ir = digitalRead(D0);
  val = analogRead(D0);  // read the input pin
  Serial.println(val);
  Serial.println(ir);  //0 si obstacle proche (sous le seuil)
  if (ir == 0) {
    //Faire le code pour le portail (moteur qui tourne)
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
  //1 si pas d'obstacle
delay(100);
}
