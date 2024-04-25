/*
  Journey 
  by the StoryCrafters- Annika Quinn and Montana Roper
*/
#include <Servo.h>

//---------------------------------------------------interaction 1 set up------------------
const int switchPinA = 11;
Servo myservoA;  
int pos = 100;   
unsigned long previousMillis = 0;  
const long interval = 50;  
int increment = -1;  
//----------------------------------------------------------------------------------------


//---------------------------------------------------interaction 2 set up------------------
const int switchPinB = 5;
int switchValB = 0;
int prevSwitchValB = 0;
Servo myservoB;
//------------------------------------------------------------------------------------------



//---------------------------------------------------interaction 4 set up------------------
Servo myservoA;  
const int switchPinC = 2;
int pos = 30;   
unsigned long previousMillis = 0;  
const long interval = 50;  
int incrementB = -1;  
//------------------------------------------------------------------------------------------


//---------------------------------------------------interaction 5 set up------------------
const int switchPinE = 10;
const int ledPin = 13;
//------------------------------------------------------------------------------------------


void setup() {

//---------------------------------------------- interaction 1-------------------------------------------
  pinMode(switchPinA, INPUT);
  myservoA.attach(9);  
  myservoA.write(0);  

//--------------------------------------------------------------------------------------------------------

//---------------------------------------------- interaction 2-------------------------------------------
  pinMode(switchPinB, INPUT);
  myservoB.attach(7);  
  myservoB.write(0);
//--------------------------------------------------------------------------------------------------------

//---------------------------------------------- interaction 4-------------------------------------------
   pinMode(switchPinA, INPUT);
  myservoC.attach(3);  
   myservoC.write(0); 
//--------------------------------------------------------------------------------------------------------

//---------------------------------------------- interaction 5-------------------------------------------
  Serial.begin(9600);
  pinMode(switchPinE, INPUT);
 pinMode(ledPin, OUTPUT);
//--------------------------------------------------------------------------------------------------------


}

void loop() {

//--------------------------------------------Interaction 1--------------------------------------------------------
// when the switch is pressed down the servo will "wiggle" back and forth from 180 to 0 degrees
unsigned long currentMillis = millis();  

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis; 
    if (digitalRead(switchPinA) == HIGH) {
      myservoA.write(pos); 
      pos += increment;  // increment or decrement position based on the direction

      // If the position reaches 60 or 100, change the direction of movement
      if (pos <= 60 || pos >= 100) {
        increment = -increment;  // reverse the direction
      }
    } else {
      myservoA.write(0);
    }
  }
  
//------------------------------------------------------------------------------------------------------------------------



 //-------------------------------------------- Interaction 2----------------------------------------------------------- 
 //when the switch is pressed down the servo rotates to 180 degrees 
 switchValB = digitalRead(switchPinB); 

  if (switchValB != prevSwitchValB)
  {
    if (switchValB == HIGH)
    {
      myservoB.write(180);
      
    }
    else
     {
      myservoB.write(0);
     }
     
    }
   
     prevSwitchValB = switchValB;
     

 
  //----------------------------------------------------------------------------------------------------------------------------






   //------------------------------------------------- Interaction 4--------------------------------------------------------------
  // when the switch is pressed the servo alternates between 0 and 30 degrees and upon reaching one reverses until the other direction is reached

unsigned long currentMillis = millis();  

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis; 
    if (digitalRead(switchPinA) == HIGH) {
      myservoC.write(pos); 
      pos += incrementB;  

      // If the position reaches 0 or 30, change the direction of movement
      if (pos <= 0 || pos >= 30) {
        incrementB = -incrementB; 
      }
    } else {
      myservoC.write(0);
    }
  }

  //---------------------------------------------------------------------------------------------------------------------------------



   //------------------------------------------------- Interaction 5--------------------------------------------------------------
   //when the switch is pressed a led will turn on and when the switch is not pressed the led is off

     if (digitalRead(switchPinE) == HIGH) {
    
     digitalWrite(ledPin, HIGH);
     
    }
    else
     {
        digitalWrite(ledPin, LOW);
      
     }


}
  //---------------------------------------------------------------------------------------------------------------------------------
