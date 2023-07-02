#define LIGHT_SENSOR  A1

#define del 500

void setup() 
{
  // put your setup code here, to run once:
   Serial.begin(9600);
   pinMode(LIGHT_SENSOR, INPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  uint16_t resistance;
  resistance = (uint16_t)getLightIntensity();
  Serial.print("resistance = ");
  Serial.println(resistance);
  delay(del);
}


float getLightIntensity()
{
  int sensorValue = analogRead(LIGHT_SENSOR);
  float rsensor;
  rsensor=(float)(1023-sensorValue)*10/sensorValue;
  return rsensor;
}
