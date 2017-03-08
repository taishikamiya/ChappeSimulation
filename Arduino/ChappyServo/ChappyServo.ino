#include <Servo.h>

Servo myServoCenter;
Servo myServoLeft;
Servo myServoRight;

int const buttonPin = 2;
int const testLed = 13;

int angleCenter=0;
int angleLeft=0;
int angleRight=0;

void setup() {
  myServoCenter.attach(9);
  myServoLeft.attach(10);
  myServoRight.attach(11);
  
  Serial.begin(9600);

  myServoLeft.write(0);  
  myServoRight.write(0);  
  myServoCenter.write(0);  

  pinMode(buttonPin, INPUT);
  pinMode(testLed, OUTPUT);

}

void loop() {

//Monitor
Serial.print(myServoLeft.read());
Serial.print(" / ");
Serial.print(myServoRight.read());
Serial.print(" / ");
Serial.println(myServoCenter.read());

//  // test 'A'
angleWrite('c');
//    angleCenter=90;
//    angleLeft=45;
//    angleRight=135;
    
//  for (angleCenter = 0; angleCenter <= 180; angleCenter += 1) { // goes from 0 degrees to 180 degrees
//    // in steps of 1 degree
//    myServoCenter.write(angleCenter);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15ms for the servo to reach the position
//  }
//  for (angleCenter = 180; angleCenter >= 0; angleCenter -= 1) { // goes from 180 degrees to 0 degrees
//    myServoCenter.write(angleCenter);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15ms for the servo to reach the position
//  }

//      myServoCenter.write(0);
//      delay(150);
//      myServoLeft.write(0);
//      delay(150);

  
//  if(digitalRead(buttonPin)==HIGH){
//    digitalWrite(testLed, HIGH);
//  } else {
//    digitalWrite(testLed, LOW);
//  }

//  Serial.println(digitalRead(buttonPin));
  
  if(digitalRead(buttonPin)==HIGH){
    //reset
      myServoLeft.write(90);
      delay(100);
      myServoRight.write(90);
      delay(100);
    //move center
      myServoCenter.write(angleCenter);
      delay(100);
    //move hands
      myServoLeft.write(angleLeft);
      delay(100);
      myServoRight.write(angleRight);
      delay(100);
  } else{
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
    angleLeft=1;
    angleRight=179;
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
  
}

