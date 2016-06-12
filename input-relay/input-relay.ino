#include <Gamer.h>
#include <ArduinoJson.h>

Gamer gamer;

StaticJsonBuffer<200> jsonBuffer;

const unsigned long BAUD_RATE = 9600;
const unsigned long MESSAGE_DELAY = 1000;

JsonObject& root = jsonBuffer.createObject();

void setup() {
  Serial.begin(BAUD_RATE);
  gamer.begin();
}

void loop() {
  updateRoot();
  printRoot();
  delay(MESSAGE_DELAY);
}

void updateRoot() {
  root["ldr"] = gamer.ldrValue();
  root["up_pressed"] = gamer.isPressed(UP);
  root["up_held"] = gamer.isHeld(UP);
  root["left_pressed"] = gamer.isPressed(LEFT);
  root["left_held"] = gamer.isHeld(LEFT);
  root["right_pressed"] = gamer.isPressed(RIGHT);
  root["right_held"] = gamer.isHeld(RIGHT);
  root["down_pressed"] = gamer.isPressed(DOWN);
  root["down_held"] = gamer.isHeld(DOWN);
  root["start_pressed"] = gamer.isPressed(START);
  root["start_held"] = gamer.isHeld(START);
}

void printRoot() {
  root.printTo(Serial);
  Serial.println();
}

