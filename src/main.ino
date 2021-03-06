//By Trevor Gruszynski, A porgram for testing PWM motor contolrers for HUHS FIRST
//Robotics. Feel Free To Modify this program and use it as you like


//TODO TEST THIS MONSTER


#include <Servo.h>  //Include the servo library

Servo motorOne;     //Initlize the servo outputs
Servo motorTwo;     //Servos use the same PWM output
Servo pwmOne;       //Thus we can use the servo lib to do pwm output
Servo pwmTwo;       //0 is -100 90 is 0 and 180 is 100

int motorOnePin = 11;
int motorTwoPin = 10;
int pwmOnePin = 9;
int pwmTwoPin = 6;

int motorOneSwitchPin = 5;
int motorTwoSwitchPin = 4;
int motorThreeSwitchPin = 3;
int motorFourSwitchPin = 2;

int sliderOnePin = 0;
int sliderTwoPin = 1;
int sliderThreePin = 2;
int sliderFourPin = 3;

int ledOnePin = 13;
int ledTwoPin = 12;
int ledThreePin = 8;
int ledFourPin = 7;

int motorOneSwitch;
int motorTwoSwitch;
int motorThreeSwitch;
int motorFourSwitch;

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
  pwmTwo.write(90);
  //A little Flashing So we know all the leds are working
  digitalWrite(ledOnePin, HIGH);
  digitalWrite(ledTwoPin, HIGH);
  digitalWrite(ledThreePin, HIGH);
  digitalWrite(ledFourPin, HIGH);
  delay(1000);
  digitalWrite(ledOnePin, LOW);
  digitalWrite(ledTwoPin, LOW);
  digitalWrite(ledThreePin, LOW);
  digitalWrite(ledFourPin, LOW);
  //End of the flashy flashy
}

void loop(){
  motorOneSwitch = digitalRead(motorOneSwitchPin);
  motorTwoSwitch = digitalRead(motorTwoSwitchPin);
  motorThreeSwitch = digitalRead(motorThreeSwitchPin);
  motorFourSwitch = digitalRead(motorFourSwitchPin);

  if (motorOneSwitch == HIGH){
    sliderOne = analogRead(sliderOnePin);
    map(sliderOne, 0, 1023, 0, 180);
    motorOne.write(sliderOne);
    digitalWrite(ledOnePin, HIGH);
  }else{
    motorOne.write(90);
    digitalWrite(ledOnePin, LOW);
  }

  if (motorTwoSwitch == HIGH){
    sliderTwo = analogRead(sliderTwoPin);
    map(sliderTwo, 0, 1023, 0, 180);
    motorTwo.write(sliderTwo);
    digitalWrite(ledTwoPin, HIGH);
  }else{
    motorTwo.write(90);
    digitalWrite(ledTwoPin, LOW);
  }

  if (motorThreeSwitch == HIGH){
    sliderTwo = analogRead(sliderThreePin);
    map(sliderThree, 0, 1023, 0, 180);
    pwmTwo.write(sliderThree);
    digitalWrite(ledThreePin, HIGH);
  }else{
    pwmOne.write(90);
    digitalWrite(ledThreePin, LOW);
  }

  if (motorFourSwitch == HIGH){
    sliderFour = analogRead(sliderFourPin);
    map(sliderFour, 0, 1023, 0, 180);
    pwmTwo.write(sliderFour);
    digitalWrite(ledFourPin, High);
  }else{
    pwmTwo.write(90);
    digitalWrite(ledFourPin, LOW);
  }
}
