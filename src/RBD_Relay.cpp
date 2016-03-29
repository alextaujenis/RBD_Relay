// Arduino RBD Relay Library v1.0.0 - Control many relays without interrupts or delay.
// https://github.com/alextaujenis/RBD_Relay
// Copyright 2016 Alex Taujenis
// MIT License

#include <Arduino.h>
#include <RBD_Relay.h> // https://github.com/alextaujenis/RBD_Relay

namespace RBD {
  Relay::Relay(int pin) {
    _pin = pin;
    _setInput();
  }

  Relay::Relay(int pin, bool invert) {
    _pin = pin;
    _invert = invert;
    _setInput();
  }

  void Relay::on() {
    if(_invert) {_state = LOW;}
    else {_state = HIGH;}
    _activate();
  }

  void Relay::off() {
    if(_invert) {_state = HIGH;}
    else {_state = LOW;}
    _activate();
  }

  bool Relay::isOn() {
    if(_invert) {return _state == LOW;}
    else {return _state == HIGH;}
  }

  bool Relay::isOff() {
    return !isOn();
  }

  bool Relay::onActive() {
    if(!_has_been_active && isOn()) {
      return _has_been_active = true;
    }
    return false;
  }

  bool Relay::onInactive() {
    if(!_has_been_inactive && isOff()) {
      return _has_been_inactive = true;
    }
    return false;
  }

  void Relay::invertReading() {
    _invert = !_invert;
  }


  // private

  void Relay::_setInput() {
    pinMode(_pin, OUTPUT);
  }

  void Relay::_activate() {
    _has_been_active   = false;
    _has_been_inactive = false;
    digitalWrite(_pin, _state);
  }
}