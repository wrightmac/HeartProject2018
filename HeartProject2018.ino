/* I Heart You project
   Peter Hein 2018, wrightmac.net
  ATTiny85 + 8x8 HT16K33 Keyestudio LED matrix
  8x8MATRIX ->  ATTiny85
  Power
  Ground
  SDA       -> PB0 - pin 5
  SCL       -> PB2 - pin 7
*/

//Required Libraries
// Keep wire around for testing the code on an Uno - Can strip when done testing 
//#include "Wire.h"

// TinyWire is for the ATTiny85 version.
// Note**TinyWireM is the version from Adafruit
#include <TinyWireM.h>
#include "Adafruit_GFX.h"
#include "Adafruit_LEDBackpack.h"

Adafruit_8x8matrix matrix = Adafruit_8x8matrix();

void setup() {

  // address for the matrix
  matrix.begin(0x70);  
}

// Frames for the heart animation
static const uint8_t PROGMEM
  heart1_bmp[] =
  { B00000000,
    B00000000,
    B00000000,
    B00010000,
    B00001000,
    B00000000,
    B00000000,
    B00000000, },
  heart2_bmp[] =
  { B00000000,
    B00000000,
    B00000000,
    B00011000,
    B00011000,
    B00000000,
    B00000000,
    B00000000, },
  heart3_bmp[] =
  { B00000000,
    B01100110,
    B10011001,
    B10011001,
    B01011010,
    B00100100,  
    B00011000,
    B00001000, },
  heart_bmp[] =
  { B00000000,
    B01100110,
    B11111111,
    B11111111,
    B01111110,
    B00111100,
    B00011000,
    B00001000, };

void loop() {
  // debug to find the 0 of the display
  // Note with 8x8 pins on the bottom setRotation(1) put the 0,0 in the upper, left corner
  // set Rotation(3) is upside down.
  //matrix.clear();      // clear display
  //matrix.setRotation(1);
  //matrix.drawPixel(0, 0, LED_ON);  
  //matrix.writeDisplay();  // write the changes we just made to the display
  //delay(1500);
  
  // Animate the heart
  matrix.setRotation(1);
  matrix.clear();
  matrix.drawBitmap(0, 0, heart1_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(500);

  matrix.clear();
  matrix.drawBitmap(0, 0, heart2_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(500);

  matrix.clear();
  matrix.drawBitmap(0, 0, heart3_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(500);

  matrix.clear();
  matrix.drawBitmap(0, 0, heart_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(500);

  matrix.clear();
  matrix.drawBitmap(0, 0, heart_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(250);

  matrix.clear();
  matrix.drawBitmap(0, 0, heart_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(500);

  matrix.clear();
  matrix.drawBitmap(0, 0, heart1_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(500);

  matrix.clear();
  matrix.drawBitmap(0, 0, heart2_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(500);

  matrix.clear();
  matrix.drawBitmap(0, 0, heart3_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(500);

  matrix.clear();
  matrix.drawBitmap(0, 0, heart_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(250);

  matrix.clear();
  matrix.drawBitmap(0, 0, heart_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(250);

  matrix.clear();
  matrix.drawBitmap(0, 0, heart_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(500);


  // Clear the screen and my special message
  //matrix.setRotation(1);
  matrix.setTextWrap(false);
  matrix.clear();
  for (int8_t x=8; x>=-100; x--){
    matrix.clear(); 
    matrix.setCursor(x - 8, 0); 
    matrix.print("My Beautiful Wife"); 
    matrix.writeDisplay(); 
    delay(100);
  }

  matrix.setRotation(4);
  matrix.clear();
  matrix.drawBitmap(0, 0, heart_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(500);
   matrix.setRotation(3);
  matrix.clear();
  matrix.drawBitmap(0, 0, heart_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(500);
   matrix.setRotation(2);
  matrix.clear();
  matrix.drawBitmap(0, 0, heart_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(500);
   matrix.setRotation(1);
  matrix.clear();
  matrix.drawBitmap(0, 0, heart_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(500);

    matrix.setTextWrap(false);
  matrix.clear();
  for (int8_t x=8; x>=-100; x--){
    matrix.clear(); 
    matrix.setCursor(x - 8, 0); 
    matrix.print("I Love You!"); 
    matrix.writeDisplay(); 
    delay(100);
  }
}
