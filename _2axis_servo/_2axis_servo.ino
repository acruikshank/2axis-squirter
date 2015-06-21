/* Sweep
 by BARRAGAN <http://barraganstudio.com> 
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://arduino.cc/en/Tutorial/Sweep
*/ 

#include <Servo.h> 
 
Servo vertical;
Servo horizontal;
 
int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
  vertical.attach(9);  // attaches the servo on pin 9 to the servo object 
  horizontal.attach(10);  // attaches the servo on pin 9 to the servo object 
} 
 
void loop() 
{
  vertical.write(floor(65 + 45.0*sin(pos * .052389238)));
  horizontal.write(floor(125 + 45.0*sin(pos * .03238239)));
  pos++;
  delay(15);                       // waits 15ms for the servo to reach the position 
} 

