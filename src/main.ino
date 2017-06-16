#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(val);                  // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
}
//-------------------------//
#include <Servo.h>

Servo motorOne;
Servo motorTwo;
Servo pwmOne;
Servo pwmTwo;

int motorOnePin = 11;
int motorTwoPin = 10;
int pwmOnePin = 9;
int pwmTwoPin = 6;

int sliderOne;
int sliderTwo;
int sliderThree;
int sliderFour;

void setup(){
  motorOne.attach(motorOnePin);
  motorTwo.attach(motorTwoPin);
  pwmOne.attach(pwmOnePin);
  pwmTwo.attach(pwmTwoPin);
  
  motorOne.write(90);
  motorTwo.write(90);
  pwmOne.write(90);
  pwmTwo..write(90);
}
