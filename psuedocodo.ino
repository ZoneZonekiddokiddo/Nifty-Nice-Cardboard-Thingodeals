#include <Servo.h>
const int switchPinA = 2;
const int switchPinB = 3;
const int switchPinC = 4;
const int switchPinD = 5;
int switchValA = 0;
int prevswitchValA = 0;
Servo myservoA;
Servo myservoB;
Servo myservoC;
Servo myservoD;

void setup() 
{
  // put your setup code here, to run once:
  pinMode(switchPinA, INPUT);
  pinMode(switchPinB, INPUT);
  pinMode(switchPinC, INPUT);
  pinMode(switchPinD, INPUT);
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
   switchValA = digitalRead(switchPinA);

  if(switchValA != prevswitchValA)     // servos will only run if switch is clicked 
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


  

  switchValB = digitalRead(switchPinB);

  if(switchValB != prevswitchValB)     // servos will only run if switch is clicked 
  {
    if (switchValB == HIGH)
    {
      myservoB.write(180);
    }
    
  }
  else 
  {
    myservoB.write(0);
  }
  prevswitchValB = switchValB;




switchValC = digitalRead(switchPinC);

  if(switchValC != prevswitchValC)     // servos will only run if switch is clicked 
  {
    if (switchValC == HIGH)
    {
      myservoC.write(180);
    }
    
  }
  else 
  {
    servoC.write(0);
  }
  prevswitchValC = switchValC;






switchValD = digitalRead(switchPinD);

  if(switchValD != prevswitchValD)     // servos will only run if switch is clicked 
  {
    if (switchValD == HIGH)
    {
      myservoD.write(180);
    }
    
  }
  else 
  {
    servoD.write(0);
  }
  prevswitchValD = switchValD;




