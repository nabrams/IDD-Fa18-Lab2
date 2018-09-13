/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld

*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int buttonPin = 7; //whatever pin your button is plugged into
int run=0;
int greenLED= 8;
int yellowLED=10;
int blueLED= 9;
int redLED= 6;
int rgb1=A2;
int rgb2=A3;
int rgb3=A4;
int end_time;
int total_time;
unsigned long time;


void setup() {
   pinMode(buttonPin, INPUT_PULLUP);
   pinMode(greenLED, OUTPUT);
   pinMode(yellowLED, OUTPUT);
   pinMode(blueLED, OUTPUT);
   pinMode(redLED, OUTPUT);
   pinMode(rgb1, OUTPUT);
   pinMode(rgb2, OUTPUT);
   pinMode(rgb3, OUTPUT);
   digitalWrite(rgb1, HIGH);
   digitalWrite(rgb2, HIGH);
   digitalWrite(rgb3, HIGH);
  // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
  // Print a message to the LCD.
    lcd.print("Hit the Button");
    lcd.setCursor(0, 1);
    lcd.print("to begin!");
}

void loop() {
 
  //code you always run here; you can leave this section blank if you want the entire program to stop and start, or add code here if you want it to always run

  //check button press here and if it is pressed then toggle run variable between 0 and 255; REQUIRED!
  if(digitalRead(buttonPin) == LOW) //funcitons based off of button pulling input pin LOW
  {
     if(run == 0)
     {
         run = 255;
         total_time=12;
         end_time=millis()/1000+total_time;
     }
     else
     {
         run = 0;
     }
  }

  if(run > 0)
  {
     unsigned long remaining_time=end_time -(millis()/1000);
     lcd.setCursor(0,0);
     lcd.print("                  ");
     lcd.setCursor(0,1);
     if((millis()/1000) < end_time){
        lcd.print("        ");
        lcd.print(remaining_time);
        lcd.print("    ");
        if ((remaining_time <=  total_time) and (remaining_time > (total_time/4 *3))){
          digitalWrite(greenLED, HIGH);
        }
        else{
          digitalWrite(greenLED, LOW);
        }
        if(remaining_time <= (total_time/4 *3) and remaining_time > total_time/2){
          digitalWrite(yellowLED,HIGH);
        }
        else{
          digitalWrite(yellowLED,LOW);
        }
        if(remaining_time <= (total_time/2) and remaining_time > total_time/4){
          digitalWrite(blueLED,HIGH);
        }
        else{
          digitalWrite(blueLED,LOW);
        }
        if(remaining_time <= (total_time/4) and remaining_time > 0){
          digitalWrite(redLED,HIGH);
        }
        
      }
      else {
          digitalWrite(redLED,LOW);
          analogWrite(rgb3, 170);
          analogWrite(rgb1, 255);
    }
    time=millis();    
    while(millis() < time+200) {
      lcd.setCursor(3, 1);
      lcd.print("WOOO DONE!");
    }
     
    }
  }
}
