#include <multiCameraIrControl.h>



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
Servo myservo;
  Sony myCamera(8);
//end new params

int noSteps=180;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  stepper1.setSpeed(10);
  //new bit
  myservo.attach(servoPin);
  myservo.write(zeroAngle);
  //and other new bit from https://www.instructables.com/id/Simple-Arduino-Camera-Trigger/

  //new bit ends
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available() > 0 ){
    String str = Serial.readString();
    if(str==""){
      myservo.write(zeroAngle);
    }
    else if(str == "go\n"){
      stepper1.step(4.4*stepsScale/noSteps);  //the 4.4 is ratio between stepper and turntable
      //add new bits from panotwins.de
      myservo.write(wakeUpAngle);
      delay(500);
      myservo.write(shootAngle);
      delay(1000);
      myservo.write(zeroAngle);
      delay(500);
      myCamera.shotNow();
      //end new bits
      //delay(500);
    }
    else {
      noSteps=(str.substring(0,str.length()-1)).toInt();
    }
  }
}
