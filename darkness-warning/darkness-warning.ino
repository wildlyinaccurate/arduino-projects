#include <Gamer.h>

Gamer gamer;

const long scaryDark = 780;
const long blinkDelay = 500;
unsigned long previousMillis = 0;

byte shoutImage[8] = {
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00000000,
  B00011000,
  B00011000
};

bool shouting = false;

void setup() {
  gamer.begin();
}

void loop() {
  unsigned long currentMillis = millis();
   
  if (isScaryDark()) {
    gamer.setLED(true);
    
    if (currentMillis - previousMillis >= blinkDelay) {
      previousMillis = currentMillis;
  
      if (shouting) {
        stopShouting();
      } else {
        shout();
      }
    }
  } else {
    gamer.clear();
    gamer.setLED(false);
  }
}

bool isScaryDark() {
  return (gamer.ldrValue() > scaryDark);
}

void shout() {
  gamer.printImage(shoutImage);
  shouting = true;
}

void stopShouting() {
  gamer.clear();
  shouting = false;
}

