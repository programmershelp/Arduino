void setup()
{
  // declare the serial comm at 9600 baud rate
  Serial.begin(9600);
 
  // output pins
  pinMode(6, OUTPUT); // red
  pinMode(7, OUTPUT); // green
  pinMode(8, OUTPUT); // blue
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
}
 
void loop()
{
  // call the returned value from GetFromSerial() function
  switch(GetFromSerial())
  {
  case '1':
    digitalWrite(6, LOW);
    break;
  case '2':
    digitalWrite(6, HIGH);
    break;
  case '3':
    digitalWrite(7, LOW);
    break;
  case '4':
    digitalWrite(7, HIGH);
    break;
  case '5':
    digitalWrite(8, LOW);
    break;
  case '6':
    digitalWrite(8, HIGH);
    break;
  }
}
 
// read the serial port
int GetFromSerial()
{
  while (Serial.available()<=0) {
  }
  return Serial.read();
}
