//Game of freeze tag with rfid & addressable lights
//on start up, all players are green
//if tagged by 'it' color changes to all blue
//and over time, change to purple
//if other-player tags you, you change back to green
//if you tag yourself, yellow and red "X" 

#include <Adafruit_NeoPixel.h>    //for lights
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif
#define LED_PIN 6
#define LED_COUNT 50
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

#include <Wire.h>               //for nfc/rfid
#include <SPI.h>
#include <Adafruit_PN532.h>

#define PN532_SCK  (13)
#define PN532_MOSI (12)
#define PN532_SS   (10)
#define PN532_MISO (11)
Adafruit_PN532 nfc(PN532_SCK, PN532_MISO, PN532_MOSI, PN532_SS);

void setup() {
  //nfc/rfid
  Serial.begin(115200);
  nfc.begin();
  uint8_t it[]={0x##, 0x##, 0x##, 0x##};    //it
  uint8_t self[]={0x##, 0x##, 0x##, 0x##};   //self-player
  uint8_t other[]={0x##, 0x##, 0x##, 0x##};  //other-player


  //lights
  strip.begin();
  strip.show();
  strip.setBrightness(50);

}


void loop() {
  //game begin
  //lights
  colorWipe(strip.Color(0,255,0),0);     //game start - all solid green

  //nfc
  uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };  // Buffer to store the returned UID 
  uint8_t uidLength;
  nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength);   //read card

  if (uid[]==it[]){                             //if uid = it; do this
    colorWipe(strip.Color(0,0,255),0);     //change color to blue
    delay(10000);                           //wait 10 seconds
    countDown(strip.Color(255,0,255),strip.Color(0,0,255)); 
  }

  if (uid[]==other[]){
    colorWipe(strip.Color(0,255,0)0);         //un-freeze, back to green
  }

  if (uid[]==self[]) {                                            //if you try to cheat&tag yourself
    cheat(strip.Color(255,0, 0),strip.Color(255,255,0));        //lights show big "x"
  }                    

}

void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}

void countDown(uint32_t color1, uint32_t color2){
  for(int i=0; i<7; i++){
    strip.setPixelColor(i, color1);
  }
  for(int k=7; k<strip.numPixels(); k++){
    strip.setPixelColor(k, color2);
  }
  strip.show();
  delay(10000);

  for(int i=0; i<14; i++){
    strip.setPixelColor(i, color1);
  }
  for(int k=14; k<strip.numPixels(); k++){
    strip.setPixelColor(k, color2);
  }
  strip.show();
  delay(10000);

  for(int i=0; i<21; i++){
    strip.setPixelColor(i, color1);
  }
  for(int k=21; k<strip.numPixels(); k++){
    strip.setPixelColor(k, color2);
  }
  strip.show();
  delay(10000);

  for(int i=0; i<28; i++){
    strip.setPixelColor(i, color1);
  }
  for(int k=28; k<strip.numPixels(); k++){
    strip.setPixelColor(k, color2);
  }
  strip.show();
  delay(10000);

  for(int i=0; i<35; i++){
    strip.setPixelColor(i, color1);
  }
  for(int k=35; k<strip.numPixels(); k++){
    strip.setPixelColor(k, color2);
  }
  strip.show();
  delay(10000);

  for(int i=0; i<42; i++){
    strip.setPixelColor(i, color1);
  }
  for(int k=42; k<strip.numPixels(); k++){
    strip.setPixelColor(k, color2);
  }
  strip.show();
  delay(10000);

  for(int k=0; k<strip.numPixels(); k++){
    strip.setPixelColor(k, color2);
  }
  strip.show();
  delay(10000);
}

void cheat(uint32_t color1, uint32_t color2){
  strip.setPixelColor(1, color1);       //fill
  strip.setPixelColor(2, color1);
  strip.setPixelColor(3, color1);
  strip.setPixelColor(4, color1);
  strip.setPixelColor(5, color1);
  strip.setPixelColor(13, color1);
  strip.setPixelColor(11, color1);
  strip.setPixelColor(10, color1);
  strip.setPixelColor(9, color1);
  strip.setPixelColor(7, color1);
  strip.setPixelColor(20, color1);
  strip.setPixelColor(19, color1);
  strip.setPixelColor(17, color1);
  strip.setPixelColor(15, color1);
  strip.setPixelColor(14, color1);
  strip.setPixelColor(27, color1);
  strip.setPixelColor(26, color1);
  strip.setPixelColor(25, color1);
  strip.setPixelColor(23, color1);
  strip.setPixelColor(22, color1);
  strip.setPixelColor(21, color1);
  strip.setPixelColor(34, color1);
  strip.setPixelColor(33, color1);
  strip.setPixelColor(31, color1);
  strip.setPixelColor(29, color1);
  strip.setPixelColor(28, color1);
  strip.setPixelColor(41, color1);
  strip.setPixelColor(39, color1);
  strip.setPixelColor(38, color1);
  strip.setPixelColor(37, color1);
  strip.setPixelColor(35, color1);
  strip.setPixelColor(47, color1);
  strip.setPixelColor(46, color1);
  strip.setPixelColor(45, color1);
  strip.setPixelColor(44, color1);
  strip.setPixelColor(43, color1);

  strip.setPixelColor(0, color2);           //the "x"
  strip.setPixelColor(6, color2);
  strip.setPixelColor(12, color2);
  strip.setPixelColor(8, color2);
  strip.setPixelColor(18, color2);
  strip.setPixelColor(16, color2);
  strip.setPixelColor(24, color2);
  strip.setPixelColor(30, color2);
  strip.setPixelColor(36, color2);
  strip.setPixelColor(42, color2);
  strip.setPixelColor(48, color2);

  strip.show();
  delay(1000);                              //delay one second
  //flip colors
  strip.setPixelColor(1, color2);       //fill
  strip.setPixelColor(2, color2);
  strip.setPixelColor(3, color2);
  strip.setPixelColor(4, color2);
  strip.setPixelColor(5, color2);
  strip.setPixelColor(13, color2);
  strip.setPixelColor(11, color2);
  strip.setPixelColor(10, color2);
  strip.setPixelColor(9, color2);
  strip.setPixelColor(7, color2);
  strip.setPixelColor(20, color2);
  strip.setPixelColor(19, color2);
  strip.setPixelColor(17, color2);
  strip.setPixelColor(15, color2);
  strip.setPixelColor(14, color2);
  strip.setPixelColor(27, color2);
  strip.setPixelColor(26, color2);
  strip.setPixelColor(25, color2);
  strip.setPixelColor(23, color2);
  strip.setPixelColor(22, color2);
  strip.setPixelColor(21, color2);
  strip.setPixelColor(34, color2);
  strip.setPixelColor(33, color2);
  strip.setPixelColor(31, color2);
  strip.setPixelColor(29, color2);
  strip.setPixelColor(28, color2);
  strip.setPixelColor(41, color2);
  strip.setPixelColor(39, color2);
  strip.setPixelColor(38, color2);
  strip.setPixelColor(37, color2);
  strip.setPixelColor(35, color2);
  strip.setPixelColor(47, color2);
  strip.setPixelColor(46, color2);
  strip.setPixelColor(45, color2);
  strip.setPixelColor(44, color2);
  strip.setPixelColor(43, color2);

  strip.setPixelColor(0, color1);           //the "x"
  strip.setPixelColor(6, color1);
  strip.setPixelColor(12, color1);
  strip.setPixelColor(8, color1);
  strip.setPixelColor(18, color1);
  strip.setPixelColor(16, color1);
  strip.setPixelColor(24, color1);
  strip.setPixelColor(30, color1);
  strip.setPixelColor(36, color1);
  strip.setPixelColor(42, color1);
  strip.setPixelColor(48, color1);

  strip.show();
  delay(1000);                              //delay one second

}
