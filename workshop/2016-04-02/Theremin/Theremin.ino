/*
    _____ _____ _____   _     _            ___ 
   |     |   __|   __|_| |_ _|_|___ ___   | | |
   |   --|__   |   __| . | | | |   | . |  |_  |
   |_____|_____|_____|___|___|_|_|_|___|    |_|

  Mod8.ino

  Created by Joao Alves on 2016-Apr-1.
  Copyright 2016 - Under creative commons license 3.0:
          Attribution-ShareAlike CC BY-SA
  This software is provided "as is", without technical support, and with no 
  warranty, express or implied, as to its usefulness for any purpose.

  Description:
	Simulates a Theremin like device 

	The circuit:
	* Buzzer - Pin 5
	* Photoresistor - Pin A0
	* PushButton - Pin 12
	* Variable Resistor - Cutter - Pin A1
	* Variable Resistor - Cycle - Pin A2
	
	Notes: 
  -
      
  Links:
  * CSEduino: http://jpralves.net/cseduino
  * Sources: https://github.com/jpralves/cseduino/workshop

	Created on 2016-Apr-1
	By Joao Alves <jpralves@gmail.com>

  ----------------------------------------------------------------------- */

const int photosensorPin = A0;
const int cutterpotPin = A1;
const int cyclepotPin = A2;
const int buzzerPin = 5;
const int killswitchPin = 12;

int val = 0;
int cut = 0;
int cycle = 0;
int kill = 0;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(killswitchPin, INPUT);
}

void loop() {
  digitalWrite(buzzerPin, LOW);
  val = analogRead(photosensorPin);
  cut = analogRead(cutterpotPin);
  cycle = analogRead(cyclepotPin);

  kill = digitalRead(killswitchPin);
  
  val = val / map(cut, 0, 1023, 15, 2);
  cycle = map(cycle, 0, 1023, 1, 1000);

 if (!kill) { 
    for(int i=0; i < cycle; i++ ) {
      digitalWrite(buzzerPin, HIGH);
      delayMicroseconds(val);
      digitalWrite(buzzerPin, LOW);
      delayMicroseconds(val);
    }
  }
}

