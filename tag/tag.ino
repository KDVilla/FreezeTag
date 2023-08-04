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
  unit8_t it[]={0x##, 0x##, 0x##, 0x##};    //it
  unit8_t self[]={0x##, 0x##, 0x##, 0x##}   //self-player
  unit8_t other[]={0x##, 0x##, 0x##, 0x##}  //other-player


  //lights
  pinMode (LED_PIN, OUTPUT);
  strip.begin();
  strip.show();
  strip.setBrightness(50);

}


void loop() {
  //lights

  colorWipe(strip.Color(0,255,0),0);     //game start - all solid green

  //nfc
  uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };  // Buffer to store the returned UID 
  uint8_t uidLength;
  nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength);   //read card

  while uid[]==it[]{                         //while uid = it; do this
    colorWipe(strip.Color(0,0,255),0);     //change color to blue
    delay(10000);                           //wait 10 seconds
    colorWipe(led 0-6 purple);   //count down starts; every ten seconds, 7 more lights change to purple
    colorWipe(led 7-49 blue);   //don't know the code to address each light 
    delay(10000);
    colorWipe(led 0-13 purple); 
    colorWipe(led 14-49 blue);
    delay(10000);
    colorWipe(led 0-20 purple); 
    colorWipe(led 21-49 blue;)
    delay(10000);
    colorWipe(led 0-27 purple);
    colorWipe(led 28-49 blue);
    delay(10000);
    colorWipe(led 0-34 purple); 
    colorWipe(led 35-49 blue);
    delay(10000);
    colorWipe(led 0-41 purple); 
    colorWipe(led 42-49 blue); 
    delay(10000);
    colorWipe(strip.Color(255,0,255)0);         //player melted, all purple
    delay(10000);
  }

  while uid[]==other[]{
    colorWipe(strip.Color(0,255,0)0);
  }
  int fill[] = {1, 2, 3, 4, 5, 13, 11, 10, 9, 7, 14, 15, 17, 19, //array of lights for x fill
              20, 27, 26, 25, 23, 22, 21, 28, 29, 31, 33, 34, 41,
               39, 38, 37, 35, 43, 44, 45, 46, 47},
  int x[]={0, 6, 12, 8, 16, 18, 24, 30, 32, 40, 36, 42, 48};    //array of lights for x

  while uid[]==self[] {                       //if you try to cheat&tag yourself
    colorWipe(fill[] red);                    //lights show big "x"
    colorWipe(x[] yellow);
    delay(1000);                              //one second wait
    colorWipe(x[] red);                       //flip colors
    colorWipe(fill[] yellow);
    delay(1000);
  }                    

}

void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}
