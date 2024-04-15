/*
  Journey 
  by the StoryCrafters- Annika Quinn and Montana Roper
*/
#include <Servo.h>

//---------------------------------------------------interaction 1 set up------------------
const int switchPinA = 8;
Servo myservoA;  
int pos = 90;   
unsigned long previousMillis = 0;  
const long interval = 50;  
int increment = -1;  
//----------------------------------------------------------------------------------------


//---------------------------------------------------interaction 2 set up------------------
const int switchPinB = 8;
int switchValB = 0;
int prevSwitchValB = 0;
Servo myservoB;
//------------------------------------------------------------------------------------------



//---------------------------------------------------interaction 4 set up------------------
const int switchPinC = 8;
Servo myservoA;  
int pos = 90;   
unsigned long previousMillis = 0;  
const long interval = 50;  
int increment = -1;  
//------------------------------------------------------------------------------------------


//---------------------------------------------------interaction 5 set up------------------
const int switchPinE = 12;
const int ledPin = 2;
//------------------------------------------------------------------------------------------


void setup() {

//---------------------------------------------- interaction 1-------------------------------------------
  pinMode(switchPinA, INPUT);
  myservoA.attach(4);  

//--------------------------------------------------------------------------------------------------------

//---------------------------------------------- interaction 2-------------------------------------------
  pinMode(switchPinB, INPUT);
  myservoB.attach(6);  
  myservoB.write(0);
//--------------------------------------------------------------------------------------------------------

//---------------------------------------------- interaction 4-------------------------------------------
   pinMode(switchPinA, INPUT);
  myservoA.attach(7);  
//--------------------------------------------------------------------------------------------------------

//---------------------------------------------- interaction 5-------------------------------------------
  Serial.begin(9600);
  pinMode(switchPinE, INPUT);
 pinMode(ledPin, OUTPUT);
//--------------------------------------------------------------------------------------------------------


}

void loop() {

//--------------------------------------------Interaction 1--------------------------------------------------------
// when the switch is pressed down the servo will "wiggle" back and forth from 180 to 0 degrees and when the switch is not being pressed the servo will be at 0 degrees
unsigned long currentMillis = millis();  

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis; 
    if (digitalRead(switchPinA) == HIGH) {
      myservoA.write(pos);  // tell servo to go to position in variable 'pos'
      pos += increment;  // increment or decrement position based on the direction

      // If the position reaches 0 or 180, change the direction of movement
      if (pos <= 0 || pos >= 180) {
        increment = -increment;  // reverse the direction
      }
    } else {
      myservoA.write(0);
    }
  }
  
//------------------------------------------------------------------------------------------------------------------------



 //-------------------------------------------- Interaction 2----------------------------------------------------------- 
 //when the switch is pressed down the servo rotates to 180 degrees and when the switch is not being pressed the servo is at 0 degrees
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


unsigned long currentMillis = millis();  

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis; 
    if (digitalRead(switchPinA) == HIGH) {
      myservoC.write(pos);  // tell servo to go to position in variable 'pos'
      pos += increment;  // increment or decrement position based on the direction

      // If the position reaches 0 or 180, change the direction of movement
      if (pos <= 0 || pos >= 180) {
        increment = -increment;  // reverse the direction
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
