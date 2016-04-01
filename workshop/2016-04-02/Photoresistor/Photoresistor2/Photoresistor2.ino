/*
    _____ _____ _____   _     _            ___ 
   |     |   __|   __|_| |_ _|_|___ ___   | | |
   |   --|__   |   __| . | | | |   | . |  |_  |
   |_____|_____|_____|___|___|_|_|_|___|    |_|

  Photoresistor2.ino

  Created by Joao Alves on 2016-Apr-1.
  Copyright 2016 - Under creative commons license 3.0:
          Attribution-ShareAlike CC BY-SA
  This software is provided "as is", without technical support, and with no 
  warranty, express or implied, as to its usefulness for any purpose.

  Description:
	Lights the led when its dark

	The circuit:
	* Photoresistor - Pin A0
	* Led - Pin 13
	 	
  Notes: 
  -
      
  Links:
  * CSEduino: http://jpralves.net/cseduino
  * Sources: https://github.com/jpralves/cseduino/workshop

	Created on 2016-Apr-1
	By Joao Alves <jpralves@gmail.com>

  ----------------------------------------------------------------------- */

const int sensorPin = A0;
const int ledPin = 13;

int sensorValue = 0;

void setup() {
  pinMode(ledPin, OUTPUT);  
}

void loop() {
  sensorValue = analogRead(sensorPin);    
  if (sensorValue < 512) {
    digitalWrite(ledPin, HIGH);
  } else { 
    digitalWrite(ledPin, LOW);
  }   
  delay(200);                  
}
