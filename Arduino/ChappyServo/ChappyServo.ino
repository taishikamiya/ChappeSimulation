#include <VarSpeedServo.h> // external lib
//#include <Servo.h>

VarSpeedServo myServoCenter;
VarSpeedServo myServoLeft;
VarSpeedServo myServoRight;

int const buttonPin = 2;
int const testLed = 13;

int angleCenter=0;
int angleLeft=0;
int angleRight=0;

String inputString;
char keyIn[60];
int keyCount=0;

boolean textReady = false;

void setup() {
  // serial
    Serial.begin(9600);
    while(!Serial){
    ; // wait for serial port to connect. Needed for native USB port only
    }
  Serial.println("Chappy System");
  Serial.println("Type sentence:");
  Serial.println();

  inputString = String("");

//servo setting 
  myServoCenter.attach(9);
  myServoLeft.attach(10);
  myServoRight.attach(11);  

  myServoLeft.write(90,150,true);  
  myServoRight.write(90,150,true);  
  myServoCenter.write(0,150,true);  

// initial setting
  angleWrite('c');

// in out
  pinMode(buttonPin, INPUT);
  pinMode(testLed, OUTPUT);

}

void loop() {
  // get any incoming bytes:
   if (Serial.available() > 0 && textReady==false) {
    keyIn[keyCount] = Serial.read();
    if(keyIn[keyCount]=='.'){
      keyIn[keyCount] = '\0';
      keyCount=0;
    Serial.println(inputString);
    textReady=true;
   } else {
    inputString += keyIn[keyCount];
    keyCount++;      
   }    
   }

   if(textReady==true){
    
    //Prepare Angle Value
    if(inputString.charAt(keyCount)=='\0'){
    inputString="";
    textReady = false;
    }
    Serial.println(inputString.charAt(keyCount));
    angleWrite(inputString.charAt(keyCount));
    keyCount++;

//Monitor
//Serial.print(myServoLeft.read());
//Serial.print(" / ");
//Serial.print(myServoRight.read());
//Serial.print(" / ");
//Serial.println(myServoCenter.read());

// movement  
//  if(digitalRead(buttonPin)==HIGH){
    //reset
      myServoLeft.write(90,100,true);
      delay(100);
      myServoRight.write(90,100,true);
      delay(100);
    //move center
      myServoCenter.write(angleCenter,100,true);
      delay(100);
    //move hands
      myServoLeft.write(angleLeft,100,true);
      delay(100);
      myServoRight.write(angleRight,100,true);
      delay(100);

//      angleWrite('e');

//  } else{
//  }

  }
}

void angleWrite(char c){
  if(c=='a' || c=='A'){
    angleCenter=0;
    angleLeft=0;
    angleRight=180;
  }
  if(c=='b' || c=='B'){
    angleCenter=45;
    angleLeft=0;
    angleRight=180;
  }
  if(c=='c' || c=='C'){
    angleCenter=90;
    angleLeft=0;
    angleRight=180;
  }
  if(c=='d' || c=='D'){
    angleCenter=135;
    angleLeft=0;
    angleRight=180;
  }
  if(c=='e' || c=='E'){
    angleCenter=0;
    angleLeft=180;
    angleRight=0;
  }
  if(c=='f' || c=='F'){
    angleCenter=45;
    angleLeft=180;
    angleRight=0;
  }
  if(c=='g' || c=='G'){
    angleCenter=90;
    angleLeft=180;
    angleRight=0;
  }
  if(c=='h' || c=='H'){
    angleCenter=135;
    angleLeft=180;
    angleRight=0;
  }
  if(c=='i' || c=='I'){
    angleCenter=0;
    angleLeft=180;
    angleRight=180;
  }
  if(c=='j' || c=='J'){ // missing 'J'
//    angleCenter=45;
//    angleLeft=180;
//    angleRight=180;
  }
  if(c=='k' || c=='K'){
    angleCenter=45;
    angleLeft=180;
    angleRight=180;
  }
  if(c=='l' || c=='L'){
    angleCenter=90;
    angleLeft=180;
    angleRight=180;
  }
  if(c=='m' || c=='M'){
    angleCenter=135;
    angleLeft=180;
    angleRight=180;
  }
  if(c=='n' || c=='N'){
    angleCenter=0;
    angleLeft=0;
    angleRight=0;
  }
 if(c=='o' || c=='O'){
    angleCenter=45;
    angleLeft=0;
    angleRight=0;
  }
 if(c=='p' || c=='P'){
    angleCenter=90;
    angleLeft=0;
    angleRight=0;
  }
 if(c=='q' || c=='Q'){
    angleCenter=135;
    angleLeft=0;
    angleRight=0;
  }
 if(c=='r' || c=='R'){
    angleCenter=0;
    angleLeft=0;
    angleRight=90;
  }
 if(c=='s' || c=='S'){
    angleCenter=45;
    angleLeft=0;
    angleRight=90;
  }
 if(c=='t' || c=='T'){
    angleCenter=90;
    angleLeft=0;
    angleRight=90;
  }
 if(c=='u' || c=='U'){
    angleCenter=135;
    angleLeft=0;
    angleRight=90;
  }
 if(c=='v' || c=='V'){
    angleCenter=0;
    angleLeft=90;
    angleRight=0;
  }
 if(c=='w' || c=='W'){
    angleCenter=45;
    angleLeft=90;
    angleRight=0;
  }
 if(c=='x' || c=='X'){
    angleCenter=90;
    angleLeft=90;
    angleRight=0;
  }
 if(c=='y' || c=='Y'){
    angleCenter=135;
    angleLeft=90;
    angleRight=0;
  }
 if(c=='z' || c=='Z'){
    angleCenter=0;
    angleLeft=90;
    angleRight=180;
  }

  
}

