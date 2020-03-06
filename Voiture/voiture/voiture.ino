int ENA = D4;
int IN1 = D3;
int IN2 = D2;

int ENB = D6;
int IN3 = D5;
int IN4 = D0;

bool carStop = false;

void setup() {

  // set all the motor control pins to outputs
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

}

void drive() {

  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

}

void stopCar() {
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

}

void loop() {
  int ir = digitalRead(D1);
  if (ir == 0) {
    if(!carStop) {
      carStop = !carStop;
      stopCar();
    }
  } else {
    if(carStop) {
      carStop = !carStop;
      drive();
    }
  }
}
