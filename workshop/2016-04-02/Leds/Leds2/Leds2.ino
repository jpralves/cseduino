/*
    _____ _____ _____   _     _            ___ 
   |     |   __|   __|_| |_ _|_|___ ___   | | |
   |   --|__   |   __| . | | | |   | . |  |_  |
   |_____|_____|_____|___|___|_|_|_|___|    |_|

  Leds2.ino

  Created by Joao Alves on 2016-Apr-1.
  Copyright 2016 - Under creative commons license 3.0:
          Attribution-ShareAlike CC BY-SA
  This software is provided "as is", without technical support, and with no 
  warranty, express or implied, as to its usefulness for any purpose.

  Description:
	Blinking Example with 3 LEDs

	The circuit:
	* Led1 - Pin 2
	* Led2 - Pin 3
  * Led3 - Pin 4

  Notes: 
  -

  Links:
  * CSEduino: http://jpralves.net/cseduino
  * Sources: https://github.com/jpralves/cseduino/workshop

	Created on 2016-Apr-1
	By Joao Alves <jpralves@gmail.com>

  ----------------------------------------------------------------------- */

const int led1Pin = 2;
const int led2Pin = 3;
const int led2Pin = 4;
const int delayPeriod = 500;

void setup() {
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
}

void loop() {
  digitalWrite(led1Pin, HIGH);   
  delay(delayPeriod);
  digitalWrite(led1Pin, LOW);
  delay(delayPeriod);
  digitalWrite(led2Pin, HIGH);   
  delay(delayPeriod);
  digitalWrite(led2Pin, LOW);
  delay(delayPeriod);
  digitalWrite(led3Pin, HIGH);   
  delay(delayPeriod);
  digitalWrite(led3Pin, LOW);
  delay(delayPeriod);
}