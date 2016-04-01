/*
    _____ _____ _____   _     _            ___ 
   |     |   __|   __|_| |_ _|_|___ ___   | | |
   |   --|__   |   __| . | | | |   | . |  |_  |
   |_____|_____|_____|___|___|_|_|_|___|    |_|

  Buzzer1.ino

  Created by Joao Alves on 2016-Apr-1.
  Copyright 2016 - Under creative commons license 3.0:
          Attribution-ShareAlike CC BY-SA
  This software is provided "as is", without technical support, and with no 
  warranty, express or implied, as to its usefulness for any purpose.

  Description:
	Plays tones in the Buzzer

	The circuit:
	* Buzzer - Pin 5

  Notes: 
  -
      
  Links:
  * CSEduino: http://jpralves.net/cseduino
  * Sources: https://github.com/jpralves/cseduino/workshop

	Created on 2016-Apr-1
	By Joao Alves <jpralves@gmail.com>

  ----------------------------------------------------------------------- */

#include "pitches.h"

const int buzzerPin = 5;

int melody[] = {
  NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4};

int noteDurations[] = { 4, 8, 8, 4, 4, 4, 4, 4 };

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration = 1000/noteDurations[thisNote];
    tone(buzzerPin, melody[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(buzzerPin);
  }
}

