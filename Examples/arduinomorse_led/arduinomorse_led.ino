const int ledPin = 7;

// constants for tone and rest durations
const int dotlength = 100;
const int dashlength = dotlength * 3;
const int inter = dotlength; 
const int lgap = dotlength * 2; // inter-letter gap
const int wgap = dotlength * 4; //inter-word gap


void setup() 
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  char thischar;
  if (Serial.available())
  {
    // read a single character
    thischar = Serial.read();
    if (thischar>='a' && thischar<='z')
    {
      // convert to upper case
      thischar = thischar -32; 
    }
    // swap for a space if not in A-Z
    if(thischar<65 || thischar>90)
    {
      thischar=' '; 
    }
    ConvertToMorse(thischar);
    delay(lgap);
  }
}


void dot()
{
  // play a dot
  digitalWrite(ledPin, HIGH);
  delay(dotlength);
  digitalWrite(ledPin, LOW);
  delay(inter);
}

void dash()
{
  // play a dash
  digitalWrite(ledPin, HIGH);
  delay(dashlength);
  digitalWrite(ledPin, LOW);
  delay(inter);
}

void ConvertToMorse(char letter)
{
  // letters are in order of frequency
  switch(letter)
  {
  case 'E':
    dot();
    return; 
  case 'T':
    dash();
    return; 
  case 'A':
    dot();
    dash();
    return;
  case 'O':
    dash();
    dash();
    dash();
    return; 
  case 'I':
    dot();
    dot();
    return;
  case 'N':
    dash();
    dot();
    return;
  case 'S':
    dot();
    dot();
    dot();
    return;
  case 'H':
    dot();
    dot();
    dot();
    dot();
    return;
  case 'R':
    dot();
    dash();
    dot();
    return;
  case 'D':
    dash();
    dot();
    dot();
    return;
  case 'L':
    dot();
    dash();
    dot();
    dot();
    return;
  case 'C':
    dash();
    dot();
    dash();
    dot();
    return;
  case 'U':
    dot();
    dot();
    dash();
    return;
  case 'M':
    dash();
    dash();
    return;
  case 'W':
    dot();
    dash();
    dash();
    return;
  case 'F':
    dot();
    dot();
    dash();
    dot();
    return;
  case 'G':
    dash();
    dash();
    dot();
    return;
  case 'Y':
    dash();
    dot();
    dash();
    dash();
    return;
  case 'P':
    dot();
    dash();
    dash();
    dot();
    return;
  case 'B':
    dash();
    dot();
    dot();
    dot();
    return;
  case 'V':
    dot();
    dot();
    dot();
    dash();
    return;
  case 'K':
    dash();
    dot();
    dash();
    return;
  case 'J':
    dot();
    dash();
    dash();
    dash();
    return;
  case 'X':
    dash();
    dot();
    dot();
    dash();
    return;
  case 'Q':
    dash();
    dash();
    dot();
    dash();
    return;
  case 'Z':
    dash();
    dash();
    dot();
    dot();
    return;
  case ' ':
    delay(wgap);
    return; 
  }
}
