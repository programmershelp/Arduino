#define LED4  5
#define LED3  4
#define LED2  3
#define LED1  2

#define del 500

void setup() 
{
  // put your setup code here, to run once:
  pinMode(LED4, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED1, OUTPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  digitalWrite(LED4, HIGH);
  delay(del);
  digitalWrite(LED3, HIGH);
  delay(del);
  digitalWrite(LED2, HIGH);
  delay(del);
  digitalWrite(LED1, HIGH);
  delay(del);
  digitalWrite(LED1, LOW);
  delay(del);
  digitalWrite(LED2, LOW);
  delay(del);
  digitalWrite(LED3, LOW);
  delay(del);
  digitalWrite(LED4, LOW);
  delay(del);
}
