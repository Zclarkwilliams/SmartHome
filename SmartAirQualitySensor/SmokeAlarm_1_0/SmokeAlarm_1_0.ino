#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int smokeA0 = A0;
int LED = D0;

// Your threshold value. You might need to change it.
int sensorThres = 900;

void setup() {
 pinMode(LED, OUTPUT);
 pinMode(smokeA0, INPUT);
 Serial.begin(115200);
 Wire.begin(D2, D1);
 lcd.begin();
 lcd.home();
 lcd.print("Welcome to SmartHome\n");
}

void loop() {
 int analogSensor = analogRead(smokeA0);

 lcd.print("Pin A0: ");
 lcd.println(analogSensor);
 // Checks if it has reached the threshold value
 if (analogSensor > sensorThres)
 {
   digitalWrite(LED, LOW);
 }
 else
 {
   digitalWrite(LED, HIGH);
 }
 delay(1000);
 lcd.clear();
}
