#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define startpin 3
#define rows 10
// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 10 // Popular NeoPixel ring size
// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
//Adafruit_NeoPixel pixels[10];
int n;
Adafruit_NeoPixel pixels[10];


 int red;
  int green;
  int blue;
void setup() {
  dht.begin();
  for(n=0;n<rows;n++){
   pixels[n]={NUMPIXELS, n+startpin, NEO_GRB + NEO_KHZ800};
    pixels[n].begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels[n].clear(); // Set all pixel colors to 'off'
  Serial.begin(9600);
  pixels[n].show();
  }
  pinMode(2,OUTPUT);
  }
  
 
void loop() {
  if(Serial.read()=='d'){ //Anzeigen der Pixel
   delay(1);
  
  for (int n=0;n<rows;n++){
    delay(1);
    if(Serial.read()=='s'){
      //digitalWrite(2,HIGH); 
 for(int i=NUMPIXELS-1;i>=0;i--){
delay(1);
  if(Serial.read()=='\r')
  {
 
  red = Serial.parseInt();
  green = Serial.parseInt();
  blue = Serial.parseInt();
  pixels[n].setPixelColor(i, pixels[n].Color(red, green, blue));
   
  }
 }
 }
pixels[n].show();
  } 
  Serial.write('e');}

  if(Serial.read()=='q'){ //Senden der temp/hum
 float h = dht.readHumidity();
 int hum=int(h*100.0);
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  int temp=int(t*100.0);
//Serial.write(hum);/Serial.write('\r');
Serial.print(temp);
Serial.write('\r');
Serial.print(hum);
Serial.write('\r');
Serial.write('e');

  }
}
