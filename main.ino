// include the Servo library
#include <Servo.h>

Servo myServo1;  // create a servo object upper left
Servo myServo2;  // create a servo object upper right
Servo myServo3;  // create a servo object lower left
Servo myServo4;  // create a servo object lower right

int pos= 2500;
int maxPosUpper=1100;
int minPosUpper=1900;

int maxPosLower=1100;
int minPosLower=1900;

int time2Open = 4; // seconds to open the thing

void setup() {
  Serial.begin(9600); // open a serial connection to your computer
  Serial.println("Im starting");

  myServo1.attach(9); // attaches the servo on pin 9 to the servo object
  myServo2.attach(8); // attaches the servo on pin 9 to the servo object


  myServo3.attach(6); // attaches the servo on pin 9 to the servo object
  myServo4.attach(5); // attaches the servo on pin 9 to the servo object


  Serial.println("Go to neutral");
  neutralAll();
 
 )



void loop() {

 
 
  openUpper();
  delay(1000);
  //eject();
  delay(2000);
  neutralAll();
  delay(1000); //add mix
  closeUpper();
  delay(6000); // bake it


}


void moveServoUpper(int pos) {
  myServo1.writeMicroseconds(pos);
  myServo2.writeMicroseconds(map(pos, 700, 2300, 2300, 700));
}

void moveServoLower(int pos) {
  myServo3.writeMicroseconds(pos);
  myServo4.writeMicroseconds(map(pos, 700, 2300, 2300, 700));
}

void neutralAll() {
  Serial.println("Go to Neutral");
  moveServoUpper(1500);
  moveServoLower(1500);
}

void closeUpper() {
  Serial.println("Close Upper");
  for (pos = maxPosUpper; pos >= minPosUpper; pos -= 1) // goes from 180 degrees to 0 degrees
  {
    Serial.print("Angle: ");
    Serial.println(pos);
    moveServoUpper(pos);
    delay(30);                       // waits 15ms for the servo to reach the position
  }
}

void openUpper() {
  Serial.println("Open Upper");
  for (pos = minPosUpper; pos <= maxPosUpper; pos += 1) // goes from 0 degrees to 180 degrees
  { // in steps of 1 degree
    Serial.print("Angle: ");
    Serial.println(pos);
    moveServoUpper(pos);
    delay(30);                       // waits 15ms for the servo to reach the position
  }
}



void eject() {
  for (pos = 0; pos <= maxPosLower; pos += 1) // goes from 0 degrees to 180 degrees
  { // in steps of 1 degree

  }
  
void closeLower() {
  for (pos = 0; pos <= maxPosLower; pos += 1) // goes from 0 degrees to 180 degrees
  { // in steps of 1 degree

  }  
  
}
