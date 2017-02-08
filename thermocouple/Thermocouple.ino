#include <SPI.h>
#include "Adafruit_MAX31855.h"

// (c) Anton Golubev 2017

// Default connection is using software SPI, but comment and uncomment one of
// the two examples below to switch between software SPI and hardware SPI:

// Example creating a thermocouple instance with software SPI on any three
// digital IO pins.
//#define MAXDO   3
//#define MAXCS   4
//#define MAXCLK  5
//
//// initialize the Thermocouple
//Adafruit_MAX31855 thermocouple(MAXCLK, MAXCS, MAXDO);

// Example creating a thermocouple instance with hardware SPI
// on a given CS pin.
#define MAXCS   10
Adafruit_MAX31855 thermocouple(MAXCS);

void setup() {
  while (!Serial); // wait for Serial on Leonardo/Zero, etc

  Serial.begin(115200);

  Serial.println("MAX31855 test");
  Serial.println("MAX31855 test 2");
  // wait for MAX chip to stabilize
  delay(500);
}

void loop() {
  // basic readout test, just print the current temp
   Serial.print("Internal Temp = ");
   Serial.println(thermocouple.readInternal());

   double c = thermocouple.readCelsius();
   if (isnan(c)) {
     Serial.println("Something wrong with thermocouple!");
   } else {
     Serial.print("C = ");
     Serial.println(c);
   }
   //Serial.print("F = ");
   //Serial.println(thermocouple.readFarenheit());

   delay(1000);
}
