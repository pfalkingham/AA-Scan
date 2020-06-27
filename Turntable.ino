// AAScan: Open source, minimalist, fully automated 3D scanner based on Arduino and Android!

// Arduino program - To be uploaded to Arduino

// Copyright (C) 2020 redditNewUser2017
// Check out my page https://www.reddit.com/user/redditNewUser2017 and my subreddit https://www.reddit.com/r/Simulations/

//     This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU Affero General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU Affero General Public License
//    along with this program.  If not, see <https://www.gnu.org/licenses/agpl-3.0.en.html>. 


#include <Stepper.h>
#include <Servo.h>


const int motorPin1=2;
const int motorPin2=3;
const int motorPin3=4;
const int motorPin4=5;
const int stepsScale = 2400;
Stepper stepper1(stepsScale,motorPin1,motorPin3,motorPin2,motorPin4);

// Peter's Sony Nex controller - from https://www.panotwins.de/technical/nex-remote-trigger-with-arduino/
const int servoPin = 11;
const int minimumAngle = 0;
const int maximumAngle = 179;
const int zeroAngle = 0;
const int wakeUpAngle = 7;
const int shootAngle = 30;
const int pinIRLED = 8;
Servo myservo;
//end new params

int noSteps=180;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  stepper1.setSpeed(10);
  //new bit
  myservo.attach(servoPin);
  myservo.write(zeroAngle);
  //pin mode - not sure what this is for
  pinMode(pinIRLED, OUTPUT);
  
}

//All of the below is from http://www.l8ter.com/?p=333

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available() > 0 ){
    String str = Serial.readString();
    if(str==""){
      myservo.write(zeroAngle);
    }
    else if(str == "go\n"){
      stepper1.step(4.4*stepsScale/noSteps);  //the 4.4 is ratio between stepper and turntable
      delay(((60/(10/4.4))/noSteps)+500);
      IRtrigger();
      //delay(500);
      //add new bits from panotwins.de
//Uncomment this stuff if you want to use physical servo to trigger camera    
      //myservo.write(wakeUpAngle);
      //delay(500);
      //myservo.write(shootAngle);
      //delay(1000);
      //myservo.write(zeroAngle);
      //delay(500);
      //end new bits
      //delay(500);
    }
    else {
      noSteps=(str.substring(0,str.length()-1)).toInt();
    }
  }
}

void pulseON(int pulseTime) {
  unsigned long endPulse = micros() + pulseTime;        // create the microseconds to pulse for
  while( micros() < endPulse) {
    digitalWrite(pinIRLED, HIGH);                       // turn IR on
    delayMicroseconds(13);                              // half the clock cycle for 38Khz (26.32×10-6s) - e.g. the 'on' part of our wave
    digitalWrite(pinIRLED, LOW);                        // turn IR off
    delayMicroseconds(13);                              // delay for the other half of the cycle to generate wave/ oscillation
  }
}

void pulseOFF(unsigned long startDelay) {
  unsigned long endDelay = micros() + startDelay;       // create the microseconds to delay for
  while(micros() < endDelay);
}

void IRtrigger(){
  for (int i=0; i < 2; i++) {
    pulseON(2336);
    pulseOFF(646);
    pulseON(1168);
    pulseOFF(621);
    pulseON(572);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(572);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(572);
    pulseOFF(646);
    pulseON(572);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(572);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(572);
    pulseOFF(621);
    pulseON(572);
    pulseOFF(646);
    pulseON(572);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(11008);
    pulseON(2336);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(572);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(572);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(572);
    pulseOFF(646);
    pulseON(572);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(572);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(572);
    pulseOFF(621);
    pulseON(572);
    pulseOFF(646);
    pulseON(572);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(11008);
    pulseON(2336);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(572);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(572);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(572);
    pulseOFF(646);
    pulseON(572);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(572);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(1093);
    pulseOFF(696);
    pulseON(572);
    pulseOFF(621);
    pulseON(572);
    pulseOFF(621);
    pulseON(572);
    pulseOFF(621);
    pulseON(572);
    pulseOFF(1218);
    pulseON(497);
    pulseOFF(1292);
    pulseON(422);
    pulseOFF(1367);
    pulseON(373);
    pulseOFF(11803);
    pulseON(298);
    pulseOFF(2659);
    pulseON(199);
    pulseOFF(1590);
    pulseON(174);
    pulseOFF(1019);
    pulseON(174);
    pulseOFF(1615);
    pulseON(174);
    pulseOFF(1615);
    pulseON(149);
    pulseOFF(1044);
    pulseON(149);
    pulseOFF(1640);
    pulseON(124);
    pulseOFF(1093);
    pulseON(149);
    pulseOFF(1044);
    pulseON(124);
    pulseOFF(1665);
    pulseON(124);
    pulseOFF(1068);
    pulseON(124);
    pulseOFF(1665);
    pulseON(99);
    pulseOFF(1690);
    pulseON(99);
    pulseOFF(1690);
    pulseON(99);
    pulseOFF(1093);
    pulseON(99);
    pulseOFF(1118);
    pulseON(99);
    pulseOFF(1093);
    pulseON(99);
    pulseOFF(1690);
    pulseON(99);
    pulseOFF(1690);
    pulseON(75);
    pulseOFF(1715);
    pulseON(75);
    pulseOFF(12101);
    pulseON(149);
    pulseOFF(2833);
    pulseON(75);
    pulseOFF(1715);
    pulseON(75);
    pulseOFF(1118);
    pulseON(75);
    pulseOFF(1715);
    pulseON(75);
    pulseOFF(1715);
    pulseON(75);
    pulseOFF(1118);
    pulseON(75);
    pulseOFF(1715);
    pulseON(75);
    pulseOFF(1118);
    pulseON(99);
    pulseOFF(1093);
    pulseON(99);
    pulseOFF(1690);
    pulseON(99);
    pulseOFF(1093);
    pulseON(99);
    pulseOFF(1690);
    pulseON(99);
    pulseOFF(1690);
    pulseON(99);
    pulseOFF(1690);
    pulseON(99);
    pulseOFF(1093);
    pulseON(99);
    pulseOFF(1118);
    pulseON(99);
    pulseOFF(1093);
    pulseON(99);
    pulseOFF(1690);
    pulseON(99);
    pulseOFF(1690);
    pulseON(99);
    pulseOFF(1690);
    pulseON(99);
    pulseOFF(646);
  }                                                     // loop the signal twice.
}
