// Arduino RBD Relay Library v1.0.0 Example - Turn a relay on.
// https://github.com/alextaujenis/RBD_Relay
// Copyright 2016 Alex Taujenis
// MIT License

#include <RBD_Relay.h>

RBD::Relay relay(2); // digital pin 2

void setup() {}

void loop() {
  relay.on(); // set output current to HIGH
}