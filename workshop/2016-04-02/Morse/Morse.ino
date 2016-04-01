/*
    _____ _____ _____   _     _            ___ 
   |     |   __|   __|_| |_ _|_|___ ___   | | |
   |   --|__   |   __| . | | | |   | . |  |_  |
   |_____|_____|_____|___|___|_|_|_|___|    |_|

  Morse.ino

  Created by Joao Alves on 2016-Apr-1.
  Copyright 2016 - Under creative commons license 3.0:
          Attribution-ShareAlike CC BY-SA
  This software is provided "as is", without technical support, and with no 
  warranty, express or implied, as to its usefulness for any purpose.

  Description:
	Translates text to Morse Code - Sound and Light

	The circuit:
	* Buzzer - Pin 5
	* Led - Pin 13
	 	
  Notes: 
  -
      
  Links:
  * CSEduino: http://jpralves.net/cseduino
  * Sources: https://github.com/jpralves/cseduino/workshop

	Created on 2016-Apr-1
	By Joao Alves <jpralves@gmail.com>

  ----------------------------------------------------------------------- */

#define DOT 1
#define DASH 2

#define note 1200

const int buzzerPin = 5;
const int ledPin =  13;

int dotLen = 100;                 
int dashLen = dotLen * 3;
int betweenChars = dotLen * 2;

char characters[] = { 
'a', 'b', 'c', 'd', 'e', 'f', 
'g', 'h', 'i', 'j', 'k', 'l',
'm', 'n', 'o', 'p', 'q', 'r', 
's', 't', 'u', 'v', 'w', 'x', 
'y', 'z', '0', '1', '2', '3', 
'4', '5', '6', '7', '8', '9'};

long morseCode[] = {
 DOT  + (DASH << 2),
 DASH + (DOT  << 2) + (DOT  << 4) + (DOT  << 6),
 DASH + (DOT  << 2) + (DASH << 4) + (DOT  << 6),
 DASH + (DOT  << 2) + (DOT  << 4),
 DOT,
 DOT  + (DOT  << 2) + (DASH << 4) + (DOT  << 6),
 DASH + (DASH << 2) + (DOT  << 4),
 DOT  + (DOT  << 2) + (DOT  << 4) + (DOT  << 6),
 DOT  + (DOT  << 2),
 DOT  + (DASH << 2) + (DASH << 4) + (DASH << 6),
 DASH + (DOT  << 2) + (DASH << 4),
 DOT  + (DASH << 2) + (DOT  << 4) + (DOT  << 6),
 DASH + (DASH << 2),
 DASH + (DOT  << 2),
 DASH + (DASH << 2) + (DASH << 4),
 DOT  + (DASH << 2) + (DASH << 4) + (DOT  << 6),
 DASH + (DASH << 2) + (DOT  << 4) + (DASH << 6),
 DOT  + (DASH << 2) + (DOT  << 4),
 DOT  + (DOT  << 2) + (DOT  << 4),
 DASH,
 DOT  + (DOT  << 2) + (DASH << 4),
 DOT  + (DOT  << 2) + (DOT  << 4) + (DASH << 6),
 DOT  + (DASH << 2) + (DASH << 4),
 DASH + (DOT  << 2) + (DOT  << 4) + (DASH << 6),
 DASH + (DOT  << 2) + (DASH << 4) + (DASH << 6),
 DASH + (DASH << 2) + (DOT  << 4) + (DOT  << 6),
 DASH + (DASH << 2) + (DASH << 4) + (DASH << 6) + (DASH << 8),
 DOT  + (DASH << 2) + (DASH << 4) + (DASH << 6) + (DASH << 8),
 DOT  + (DOT  << 2) + (DASH << 4) + (DASH << 6) + (DASH << 8),
 DOT  + (DOT  << 2) + (DOT  << 4) + (DASH << 6) + (DASH << 8),
 DOT  + (DOT  << 2) + (DOT  << 4) + (DOT  << 6) + (DASH << 8),
 DOT  + (DOT  << 2) + (DOT  << 4) + (DOT  << 6) + (DOT  << 8),
 DASH + (DOT  << 2) + (DOT  << 4) + (DOT  << 6) + (DOT  << 8),
 DASH + (DASH << 2) + (DOT  << 4) + (DOT  << 6) + (DOT  << 8),
 DASH + (DASH << 2) + (DASH << 4) + (DOT  << 6) + (DOT  << 8),
 DASH + (DASH << 2) + (DASH << 4) + (DASH << 6) + (DOT  << 8)
};

void playMorse(char c) {
  int i;
  for(i=0; i<sizeof(characters)/sizeof(char);i++) {
    if (c == characters[i])
      break;
  }
  if (i<sizeof(characters)/sizeof(char)) {
    long code = morseCode[i];
    while (code>0) {
      if ((code & 3) == DOT)
        morseDot();
      else
        morseDash();
      code>>=2; 
      morseStop(betweenChars);   
    }
    morseStop(betweenChars);
  } else {
    morseStop(betweenChars);
  }
}

void upSignal(int timeLen) {
  digitalWrite(ledPin, HIGH);
  tone(buzzerPin, note, timeLen);
  delay(timeLen);             
}

// DOT
void morseDot() {
  upSignal(dotLen);
  Serial.print(".");
}

// DASH
void morseDash() {
  upSignal(dashLen);  
  Serial.print("-");
}

void morseStop(int delayTime) {
  digitalWrite(ledPin, LOW);   
  noTone(buzzerPin);	    
  delay(delayTime);        
}

void setup() {                
  pinMode(ledPin, OUTPUT); 
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

int enter = 0;

void loop() { 
  if (Serial.available() > 0) { 
    byte incomingByte = Serial.read();
    byte tmp = toLowerCase(incomingByte);
    playMorse(tmp);
    enter = 1;
  } else {
    if (enter == 1) {
      Serial.println();
      enter = 0;
    }
  }
}

