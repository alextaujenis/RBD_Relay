// Arduino RBD Relay Library v1.0.1 Example - Turn an inverted relay on.
// https://github.com/alextaujenis/RBD_Relay
// Copyright 2016 Alex Taujenis
// MIT License

#include <RBD_Relay.h> // https://github.com/alextaujenis/RBD_Relay

RBD::Relay relay(2, true); // digital pin 2, inverted

void setup() {}

void loop() {
  relay.on(); // set output current to LOW
}