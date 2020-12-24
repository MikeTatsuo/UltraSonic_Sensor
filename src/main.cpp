#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int echoPin = 2;
const int triggerPin = 3;

float distance = 0;
long duration = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(echoPin, INPUT);
  pinMode(triggerPin, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Distance:");
}

void loop() {
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(triggerPin,LOW);

  duration = pulseInLong(echoPin, HIGH);

  if (duration >= 38000) {
    duration = 0;
  }

  distance = duration * 0.0343 / 2;

  lcd.setCursor(0,1);
  lcd.print(distance);
  lcd.print(" cm             ");
  delay(100);
}
