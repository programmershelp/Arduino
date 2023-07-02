#include "Arduino_LED_Matrix.h"


ArduinoLEDMatrix matrix;

const uint32_t frame1[] = {
  0xfff80180,
  0x18018018,
  0x1801fff,
  66
};

const uint32_t frame2[] = {
  0x7fe40,
  0x24024024,
  0x27fe000,
  66
};

const uint32_t frame3[] = {
  0x3f,
  0xc2042043,
  0xfc000000,
  66
};

const uint32_t frame4[] = {
  0x0,
  0x1f81f80,
  0x0,
  66
};

void setup() 
{
  matrix.begin();
}

void loop() {
  matrix.loadFrame(frame1);
  delay(500);
  matrix.loadFrame(frame2);
  delay(500);
  matrix.loadFrame(frame3);
  delay(500);
  matrix.loadFrame(frame4);
  delay(500);
}
