/*
    _____ _____ _____   _     _            ___ 
   |     |   __|   __|_| |_ _|_|___ ___   | | |
   |   --|__   |   __| . | | | |   | . |  |_  |
   |_____|_____|_____|___|___|_|_|_|___|    |_|

  Buzzer2.ino

  Created by Joao Alves on 2016-Apr-1.
  Copyright 2016 - Under creative commons license 3.0:
          Attribution-ShareAlike CC BY-SA
  This software is provided "as is", without technical support, and with no 
  warranty, express or implied, as to its usefulness for any purpose.

  Description:
	Plays incremental tone when pushbutton pressed

	The circuit:
	* Buzzer - Pin 5
	* Led - Pin 13
	* PushButton - Pin 12

  Notes: 
  -
      
  Links:
  * CSEduino: http://jpralves.net/cseduino
  * Sources: https://github.com/jpralves/cseduino/workshop

	Created on 2016-Apr-1
	By Joao Alves <jpralves@gmail.com>

  ----------------------------------------------------------------------- */

const int buttonPin = 12;
const int ledPin =  13;
const int buzzerPin = 5;

int buttonState = 0;
int toneValue = 0;
int oldTone = 0;

void setup() {
  pinMode(ledPin, OUTPUT);      
  pinMode(buzzerPin, OUTPUT);    
  pinMode(buttonPin, INPUT);  
}

void loop(){
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {     
    digitalWrite(ledPin, HIGH);  
    tone(buzzerPin, toneValue, 50);
    delay(10);
    toneValue += 10;
  } else {
    digitalWrite(ledPin, LOW); 
    noTone(buzzerPin);
    if (toneValue == oldTone) {
      toneValue = 0;
    } else {
      oldTone = toneValue;
    }
  }
}
