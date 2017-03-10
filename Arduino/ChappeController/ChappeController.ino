#include <VarSpeedServo.h> // external lib
//#include <Servo.h>

VarSpeedServo myServoCenter;
VarSpeedServo myServoLeft;
VarSpeedServo myServoRight;

//for Test
int const buttonPin = 2;
int const testLed = 13;

//LEDs
int const ledLeft1 = 6;
int const ledLeft2 = 9;
int const ledRight1 = 10;
int const ledRight2 = 11;

//Potentio Sensor
int const potPin = A0;
int potValue = 0;
int const entButton = 3;
int const sendButton = 4;

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

// Led setting
  pinMode(ledLeft1,OUTPUT);
  pinMode(ledLeft2,OUTPUT);
  pinMode(ledRight1,OUTPUT);
  pinMode(ledRight2,OUTPUT);
  digitalWrite(ledLeft1, LOW);
  digitalWrite(ledLeft2, LOW);
  digitalWrite(ledRight1, LOW);
  digitalWrite(ledRight2, LOW);

// in out
  pinMode(buttonPin, INPUT);
  pinMode(testLed, OUTPUT);
// Button
  pinMode(entButton, INPUT);
  pinMode(sendButton, INPUT);
  
//servo setting 
  myServoCenter.attach(9);
  myServoLeft.attach(10);
  myServoRight.attach(11);  

  myServoLeft.write(90,150,true);  
  myServoRight.write(90,150,true);  
  myServoCenter.write(0,150,true);  

// initial setting
  angleWrite('c');

}

void loop() {
  // Potentio Sensor Input
  // when entButton High
  if(digitalRead(entButton)==LOW){
    potValue = 1023-analogRead(potPin);
    char potChar = readPot(potValue); 
    if(potChar=='\b'){
      inputString.setCharAt(keyCount-1,'\b');
    } else {
      Serial.println(potChar); 
      inputString += potChar;
    }
    keyCount++;
    delay(500);
  }  

  //sedn button
  if(digitalRead(sendButton)==HIGH){
      inputString += '\0';
      keyCount=0;
      Serial.println(inputString);
      textReady=true;
      delay(500); 
  }
  
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
    digitalWrite(ledLeft1, LOW);
    digitalWrite(ledLeft2, LOW);
    digitalWrite(ledRight1, LOW);
    digitalWrite(ledRight2, LOW);   
    return; 
    }

    Serial.println(inputString.charAt(keyCount));
    angleWrite(inputString.charAt(keyCount));
    keyCount++;

    //LED
    digitalWrite(ledLeft1, HIGH);
    digitalWrite(ledLeft2, HIGH);
    digitalWrite(ledRight1, HIGH);
    digitalWrite(ledRight2, HIGH);

//Monitor
//Serial.print(myServoLeft.read());
//Serial.print(" / ");
//Serial.print(myServoRight.read());
//Serial.print(" / ");
//Serial.println(myServoCenter.read());

// movement  
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
      delay(500); // last word

  }
}

char readPot(int val){  // val=0-1024
  char c;

  if(val>=0 && val<30){
    c = 'a';
  } else if(val>=30 && val<60){
    c = 'b';
  } else if(val>=60 && val<90){
    c = 'c';
  } else if(val>=90 && val<120){
    c = 'd';
  } else if(val>=120 && val<150){
    c = 'e';
  } else if(val>=150 && val<180){
    c = 'f';
  } else if(val>=180 && val<210){
    c = 'g';
  } else if(val>=210 && val<240){
    c = 'h';
  } else if(val>=240 && val<270){
    c = 'i';
  } else if(val>=270 && val<300){
    c = 'j';
  } else if(val>=300 && val<330){
    c = 'k';
  } else if(val>=330 && val<360){
    c = 'l';
  } else if(val>=360 && val<390){
    c = 'm';
  } else if(val>=390 && val<420){
    c = 'n';
  } else if(val>=420 && val<450){
    c = 'o';
  } else if(val>=450 && val<480){
    c = 'p';
  } else if(val>=480 && val<510){
    c = 'q';
  } else if(val>=510 && val<540){
    c = 'r';
  } else if(val>=540 && val<570){
    c = 's';
  } else if(val>=570 && val<600){
    c = 't';
  } else if(val>=600 && val<630){
    c = 'u';
  } else if(val>=630 && val<660){
    c = 'v';
  } else if(val>=660 && val<690){
    c = 'w';
  } else if(val>=690 && val<720){
    c = 'x';
  } else if(val>=720 && val<750){
    c = 'y';
  } else if(val>=750 && val<780){
    c = 'z';
  } else {
    c = '\b'; // end
  }
  return c;
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

