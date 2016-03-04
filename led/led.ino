/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */

int brightness=255;
int fadeAmount=10;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
   pinMode(10, OUTPUT);

}

// the loop function runs over and over again forever
void loop() {
  analogWrite(13, brightness);
  analogWrite(10, brightness);
 
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    // sets the value (range from 0 to 255):
    analogWrite(13, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }
   for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    // sets the value (range from 0 to 255):
    analogWrite(10, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }
   
 delay(1000);
  
}
