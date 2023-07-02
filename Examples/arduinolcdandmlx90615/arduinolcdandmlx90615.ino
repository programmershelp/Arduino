#include <Wire.h>
#include <LiquidCrystal.h>
#include <mlx90615.h>

//setup for the LCD keypad shield
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
MLX90615 mlx = MLX90615();

void setup() 
{
  //init serial for some debug
  Serial.begin(9600);
  Serial.println("Melexis MLX90615 infra-red temperature sensor test");
  //init MLX90615 sensor
  mlx.begin();
  Serial.print("Sensor ID number = ");
  Serial.println(mlx.get_id(), HEX);
  //init LCD
  lcd.begin(16,2);
  //line 1 - temperature
  lcd.setCursor(0,0);
  lcd.print("AMB = ");
  //line 2 - humidity
  lcd.setCursor(0,1);
  lcd.print("OBJ = ");
}

void loop() 
{
  //display temperature on lcd
  
  lcd.setCursor(0,0);
  lcd.print("AMB = ");
  lcd.print(mlx.get_ambient_temp());
  lcd.print(" *c");
  lcd.setCursor(0,1);
  lcd.print("OBJ = ");
  lcd.print(mlx.get_object_temp());
  lcd.print(" *c");

  delay(500);
}


