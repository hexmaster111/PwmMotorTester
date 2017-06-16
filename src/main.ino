//TODO Add The led lights to the switching functions


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
  }else{
    motorOne.write(90);
  }

  if (motorTwoSwitch == HIGH){
    sliderTwo = analogRead(sliderTwoPin);
    map(sliderTwo, 0, 1023, 0, 180);
    motorTwo.write(sliderTwo);
  }else{
    motorTwo.write(90);
  }

  if (motorThreeSwitch == HIGH){
    sliderTwo = analogRead(sliderThreePin);
    map(sliderThree, 0, 1023, 0, 180);
    pwmTwo.write(sliderThree);
  }else{
    pwmOne.write(90);
  }

  if (motorFourSwitch == HIGH){
    sliderFour = analogRead(sliderFourPin);
    map(sliderFour, 0, 1023, 0, 180);
    pwmTwo.write(sliderFour);
  }else{
    pwmTwo.write(90);
  }


}
