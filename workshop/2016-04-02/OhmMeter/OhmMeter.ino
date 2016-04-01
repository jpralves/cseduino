/*
    _____ _____ _____   _     _            ___ 
   |     |   __|   __|_| |_ _|_|___ ___   | | |
   |   --|__   |   __| . | | | |   | . |  |_  |
   |_____|_____|_____|___|___|_|_|_|___|    |_|

  OhmMeter.ino

  Created by Joao Alves on 2016-Apr-1.
  Copyright 2016 - Under creative commons license 3.0:
          Attribution-ShareAlike CC BY-SA
  This software is provided "as is", without technical support, and with no 
  warranty, express or implied, as to its usefulness for any purpose.

  Description:
	Outputs the Resistor Value 

	The circuit:
	* Resistor Read Pin - Pin A3
	
	5v -- R? -- pinA3 -- 1K Resistor -- GND
	
	Notes: 
  -
      
  Links:
  * CSEduino: http://jpralves.net/cseduino
  * Sources: https://github.com/jpralves/cseduino/workshop

	Created on 2016-Apr-1
	By Joao Alves <jpralves@gmail.com>

  ----------------------------------------------------------------------- */

const int resistorPin = A3;

int raw = 0;
const int Vin = 5;
float Vout = 0;
float R1 = 1000;
float R2 = 0;
float buffer = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  raw = analogRead(resistorPin);
  Vout = (5.0 / 1023.0) * raw;
  buffer = (Vin / Vout) - 1;
  R2 = R1 / buffer;
  Serial.print("Voltage: ");
  Serial.println(Vout);
  Serial.print("R2: ");
  Serial.println(R2);
  delay(1000);
}
