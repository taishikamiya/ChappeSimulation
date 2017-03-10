int sw1=2;
int sw2=3;
int sw3=4;

int redLed = 9;           // the PWM pin the LED is attached to
int smdLed = 10;           // the PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

boolean fSw1=false;
boolean fSw2=false;
boolean fSw3=false;

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(redLed, OUTPUT);
  pinMode(smdLed, OUTPUT);

  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  pinMode(sw3, INPUT);

Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  int swState1 = digitalRead(sw1);
  int swState2 = digitalRead(sw2);
  int swState3 = digitalRead(sw3);

Serial.println(swState1);

  if(swState1==HIGH){
    if(fSw1==false){
      digitalWrite(redLed,HIGH);
//     analogWrite(redLed, 255);
     fSw1=true;
  delay(100);
    } else{
      digitalWrite(redLed,LOW);
      fSw1=false;
  delay(100);
    }
  }
  
  if(swState2==HIGH){
    if(fSw2==false){
     analogWrite(smdLed, 255);
     fSw2=true;
  delay(100);
    } else{
     analogWrite(smdLed, 0);
      fSw2=false;
  delay(100);
    }
  }
  
  if(swState3==HIGH){
    if(fSw3==false){
    fSw3=true;
  delay(100);
    } else {
      fSw3==false;
  delay(100);
    }
    }

    if(fSw3==true){
  analogWrite(redLed, brightness);
  analogWrite(smdLed, brightness);

  brightness = brightness + fadeAmount;

  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
    }
  
}
