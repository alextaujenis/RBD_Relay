// Arduino RBD Relay Library v1.0.1 - Control many relays without interrupts or delay.
// https://github.com/alextaujenis/RBD_Relay
// Copyright 2016 Alex Taujenis
// MIT License

#ifndef RBD_RELAY_H
#define RBD_RELAY_H

#include "Arduino.h"

namespace RBD {
  class Relay {
    public:
      Relay(int pin);
      Relay(int pin, bool invert);
      void on();
      void off();
      bool isOn();
      bool isOff();
      bool onActive();
      bool onInactive();
      void invertReading();
    private:
      int _pin;
      bool _invert = false;
      bool _state = LOW;
      bool _has_been_active = false;
      bool _has_been_inactive = false;
      void _setOutput();
      void _activate();
  };
}
#endif