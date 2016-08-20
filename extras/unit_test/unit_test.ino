// Arduino RBD Relay Library v1.0.1 - Unit test coverage.
// https://github.com/alextaujenis/RBD_Relay
// Copyright 2016 Alex Taujenis
// MIT License

#include <ArduinoUnit.h> // https://github.com/mmurdoch/arduinounit
#include <RBD_Relay.h>   // https://github.com/alextaujenis/RBD_Relay

// Test setup: brige Arduino pins 2 and 3 with a 1k ohm resistor,
// also brige Arduino pins 4 and 5 with a 1k ohm resistor
RBD::Relay relay(2);
int _sense_pin  = 3;
RBD::Relay inverted_relay(4, true);
int _inverted_sense_pin = 5;

// test helpers
bool isOn()  {return digitalRead(_sense_pin);}
bool isOff() {return !isOn();}
bool invertedIsOn()  {return digitalRead(_inverted_sense_pin);}
bool invertedIsOff() {return !invertedIsOn();}

// on
  test(on_should_turn_on_the_output_current) {
    relay.on();
    assertTrue(isOn());
    testCleanup();
  }

// inverted on
  test(inverted_on_should_turn_off_the_output_current) {
    inverted_relay.on();
    assertTrue(invertedIsOff());
    testCleanup();
  }

// off
  test(off_should_turn_off_the_output_current_current) {
    relay.on();
    relay.off();
    assertTrue(isOff());
    testCleanup();
  }

// inverted off
  test(inverted_off_should_turn_on_the_output_current) {
    inverted_relay.on();
    inverted_relay.off();
    assertTrue(invertedIsOn());
    testCleanup();
  }

// isOn
  test(isOn_should_return_true_when_the_relay_is_on) {
    relay.on();
    assertTrue(relay.isOn());
    testCleanup();
  }

  test(isOn_should_return_false_when_the_relay_is_off) {
    relay.off();
    assertFalse(relay.isOn());
    testCleanup();
  }

// inverted isOn
  test(inverted_isOn_should_return_true_when_the_relay_is_on) {
    inverted_relay.on();
    assertTrue(inverted_relay.isOn());
    testCleanup();
  }

  test(inverted_isOn_should_return_false_when_the_relay_is_off) {
    inverted_relay.off();
    assertFalse(inverted_relay.isOn());
    testCleanup();
  }

// isOff
  test(isOff_should_return_true_when_the_relay_is_off) {
    relay.off();
    assertTrue(relay.isOff());
    testCleanup();
  }

  test(isOff_should_return_false_when_the_relay_is_on) {
    relay.on();
    assertFalse(relay.isOff());
    testCleanup();
  }

// inverted isOff
  test(inverted_isOff_should_return_true_when_the_relay_is_off) {
    inverted_relay.off();
    assertTrue(inverted_relay.isOff());
    testCleanup();
  }

  test(inverted_isOff_should_return_false_when_the_relay_is_on) {
    inverted_relay.on();
    assertFalse(inverted_relay.isOff());
    testCleanup();
  }

// onActive
  test(onActive_should_return_true_when_the_relay_is_turned_on) {
    relay.on();
    assertTrue(relay.onActive());
    testCleanup();
  }

  test(onActive_should_return_true_only_once_when_the_relay_is_turned_on) {
    relay.on();
    assertTrue(relay.onActive());
    assertFalse(relay.onActive());
    assertFalse(relay.onActive());
    testCleanup();
  }

  test(onActive_should_return_false_when_the_relay_is_turned_off) {
    relay.off();
    assertFalse(relay.onActive());
    testCleanup();
  }

// inverted onActive
  test(inverted_onActive_should_return_true_when_the_relay_is_turned_on) {
    inverted_relay.on();
    assertTrue(inverted_relay.onActive());
    testCleanup();
  }

  test(inverted_onActive_should_return_true_only_once_when_the_relay_is_turned_on) {
    inverted_relay.on();
    assertTrue(inverted_relay.onActive());
    assertFalse(inverted_relay.onActive());
    assertFalse(inverted_relay.onActive());
    testCleanup();
  }

  test(inverted_onActive_should_return_false_when_the_relay_is_turned_off) {
    inverted_relay.off();
    assertFalse(inverted_relay.onActive());
    testCleanup();
  }

// onInactive
  test(onInactive_should_return_true_when_the_relay_is_turned_off) {
    relay.off();
    assertTrue(relay.onInactive());
    testCleanup();
  }

  test(onInactive_should_return_true_only_once_when_the_relay_is_turned_off) {
    relay.off();
    assertTrue(relay.onInactive());
    assertFalse(relay.onInactive());
    assertFalse(relay.onInactive());
    testCleanup();
  }

  test(onInactive_should_return_false_when_the_relay_is_turned_on) {
    relay.on();
    assertFalse(relay.onInactive());
    assertFalse(relay.onInactive());
    testCleanup();
  }

// inverted onInactive
  test(inverted_onInactive_should_return_true_when_the_relay_is_turned_off) {
    inverted_relay.off();
    assertTrue(inverted_relay.onInactive());
    testCleanup();
  }

  test(inverted_onInactive_should_return_true_only_once_when_the_relay_is_turned_off) {
    inverted_relay.off();
    assertTrue(inverted_relay.onInactive());
    assertFalse(inverted_relay.onInactive());
    assertFalse(inverted_relay.onInactive());
    testCleanup();
  }

  test(inverted_onInactive_should_return_false_when_the_relay_is_turned_on) {
    inverted_relay.on();
    assertFalse(inverted_relay.onInactive());
    assertFalse(inverted_relay.onInactive());
    testCleanup();
  }

// invertReading
  test(on_should_turn_off_the_output_current_after_calling_invertReading) {
    relay.invertReading();
    relay.on();
    assertTrue(isOff());
    // test cleanup
    relay.invertReading();
    testCleanup();
  }

  test(off_should_turn_on_the_output_current_after_calling_invertReading) {
    relay.invertReading();
    relay.off();
    assertTrue(isOn());
    // test cleanup
    relay.invertReading();
    testCleanup();
  }

// setup and run tests
void setup() {
  testSetup();
  Serial.begin(115200);
  while(!Serial);
}

void loop() {
  Test::run();
}

void testSetup() {
  pinMode(_sense_pin, INPUT);
}

void testCleanup() {
  relay.off();
}