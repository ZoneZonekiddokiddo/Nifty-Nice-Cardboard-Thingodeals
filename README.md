Test code for our thingos 

#include <Servo.h>


const int buttonPin = [insert switch here];
const int switchPin = 13;
Servo myservo;
int servoAngle = 0;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  myservo.attach(switchPin);
  myservo.write(servoAngle);
}

void loop() {
  if (digitalRead(buttonPin) == HIGH) {
    if (servoAngle < 180) {
      servoAngle += servoSpeed;
    }
  } else {
    servoAngle = 0;
  }

  Serial.println(servoAngle);

}
