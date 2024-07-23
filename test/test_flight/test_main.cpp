#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
#include <Adafruit_ADS1X15.h>       //SYSTEM PARAMETER  - ADS1115/ADS1015 ADC Library (By: Adafruit)

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
Adafruit_ADS1115 ads;             //SYSTEM PARAMETER  - ADS1115 ADC Library (By: Adafruit) Kindly uncomment this if you are using ADS1115

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  Serial.begin(115200);
}

void loop()
{
  lcd.clear();                 // clear display
  lcd.setCursor(0, 0);         // move cursor to   (0, 0)
  lcd.print("Arduino");        // print message at (0, 0)
  lcd.setCursor(2, 1);         // move cursor to   (2, 1)
  lcd.print("GetStarted.com"); // print message at (2, 1)
  delay(2000);                 // display the above for two seconds

  lcd.clear();                  // clear display
  lcd.setCursor(3, 0);          // move cursor to   (3, 0)
  lcd.print("DIYables");        // print message at (3, 0)
  lcd.setCursor(0, 1);          // move cursor to   (0, 1)
  lcd.print("www.diyables.io"); // print message at (0, 1)
  delay(2000);                  // display the above for two seconds
}