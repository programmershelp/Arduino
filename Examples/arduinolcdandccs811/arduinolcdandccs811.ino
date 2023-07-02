#include <Wire.h>
#include <LiquidCrystal.h>
#include "Adafruit_CCS811.h"

//setup for the LCD keypad shield
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
Adafruit_CCS811 ccs;

void setup() 
{
  //init serial for some debug
  Serial.begin(9600);
  Serial.println("CCS811 test"); 
  //init CCS811 sensor
  if(!ccs.begin())
  {
    Serial.println("Failed to start sensor! Please check your wiring.");
    while(1);
  }
  //calibrate temperature sensor
  while(!ccs.available());
  float temp = ccs.calculateTemperature();
  ccs.setTempOffset(temp - 25.0);
  //init LCD
  lcd.begin(16,2);
  //line 1 - temperature
  lcd.setCursor(0,0);
  lcd.print("Temp = ");
  //line 2 - humidity
  lcd.setCursor(0,1);
  lcd.print("Hum = ");
}

void loop() 
{
  //display temperature on lcd
  if(ccs.available())
  {
  float temp = ccs.calculateTemperature();
    if(!ccs.readData())
    {
      lcd.setCursor(0,0);
      lcd.print("CO2: ");
      lcd.print(ccs.geteCO2());
      lcd.print(" ppm");
      lcd.setCursor(0,1);
      lcd.print("TVOC: ");
      lcd.print(ccs.getTVOC());
  
    }
    else
    {
      Serial.println("ERROR!");
      while(1);
    }
  }
  delay(500);
}


