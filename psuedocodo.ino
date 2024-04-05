#include <Servo.h>
const int switchPin = 3;
int switchValA = 0;
int prevswitchValA = 0;
Servo myservoA;
Servo myservoB;
Servo myservoC;
Servo myservoD;

void setup() 
{
  // put your setup code here, to run once:
  pinMode(switchPin, INPUT);
  myservoA.attach(10);
  myservoB.attach(11);
  myservoC.attach(12);
  myservoD.attach(13);

  myservoA.write(0);
  myservoB.write(0);
  myservoC.write(0);
  myservoD.write(0);
}

void loop()
{
   switchValA = digitalRead(switchPin);

  if(switchValA != prevswitchValA)
  {
    if (switchValA == HIGH)
    {
      myservoA.write(180);
    }
    
  }
  else 
  {
    servoA.write(0);
  }
  prevswitchValA = switchValA;
}
