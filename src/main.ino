#include <Servo.h>

Servo motorOne;
Servo motorTwo;
Servo pwmOne;
Servo pwmTwo;

int motorOnePin = 11;
int motorTwoPin = 10;
int pwmOnePin = 9;
int pwmTwoPin = 6;

int motorOneSwitchPin = 5;
int motorTwoSwitchPin = 4;
int motorThreeSwitchPin = 3;
int motorFourSwitchPin = 2;

int motorOneSwitch;
int motorTwoSwitch;
int motorThreeSwitch;
int motorFourSwitch;

int sliderOnePin = 0;
int sliderTwoPin = 1;
int sliderThreePin = 2;
int sliderFourPin = 3;

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
}

void loop(){
  sliderTwo = analogRead(sliderTwoPin);
  sliderThree = analogRead(sliderThreePin);
  sliderFour = analogRead(sliderFourPin);

  motorOneSwitch = digitalRead(motorOneSwitchPin);
  motorTwoSwitch = digitalRead(motorTwoSwitchPin);
  motorThreeSwitch = digitalRead(motorThreeSwitchPin);
  motorFourSwitch = digitalRead(motorFourSwitchPin);

  if (motorOneSwitch == HIGH){
    sliderOne = analogRead(sliderOnePin);
    map(sliderOne, 0, 1023, 0, 180);
    motorOne.write(sliderOne);
  }else{
    motorOne.write(90);
  }

}
