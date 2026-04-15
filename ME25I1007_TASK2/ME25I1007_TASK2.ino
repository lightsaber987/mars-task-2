int in1 = 3; //digital
int in2 = 5; //digital
int ena = 11;//pwm
int pot = A0;
int butPin = 2;
float scale = 255/1023.;
int potRead;
int speed;
bool in1_state, in2_state;
void setup() {
  // put your setup code here, to run once:
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(butPin,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(butPin), toggle, FALLING);
  Serial.begin(9600);
  in1_state = HIGH;
  in2_state = LOW;
}

void loop() {
  // put your main code here, to run repeatedly:
  //assign direction
  digitalWrite(in1,in1_state);
  digitalWrite(in2,in2_state);

  potRead = analogRead(pot);
  Serial.print("pot read: ");Serial.println(potRead);
  Serial.print("in1_state: ");Serial.println(in1_state);
  Serial.print("in2_state: ");Serial.println(in2_state);
  delay(1000);
  //0-1023 -> 0-255 : change speed
  int speed = potRead*scale;
  analogWrite(ena,speed);
}

void toggle(){
  in1_state = !in1_state;
  in2_state = !in2_state;
}