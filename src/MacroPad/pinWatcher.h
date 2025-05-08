// --- pinWatcher.h ---
#ifndef PINWATCHER_H
#define PINWATCHER_H

#include <Arduino.h>
#include <BleKeyboard.h>

extern BleKeyboard bleKeyboard;

class PinWatcher {
  public:
    PinWatcher() : _state(false), _lastState(false), _lastDebounceTime(0) {}

    void update(bool currentReading) {
      unsigned long now = millis();

      if (currentReading != _lastState) {
        _lastDebounceTime = now;
        _lastState = currentReading;
      }

      if ((now - _lastDebounceTime) > debounceDelay) {
        if (currentReading != _state) {
          _state = currentReading;

          if (_state) onPress();    // LOW → HIGH
          else       onRelease();   // HIGH → LOW
        }
      }
    }

    virtual void onPress() {}
    virtual void onRelease() {}

  private:
    bool _state;
    bool _lastState;
    unsigned long _lastDebounceTime;
    const unsigned long debounceDelay = 10; // ms
};

class TeclaBLE : public PinWatcher {
  public:
    TeclaBLE(uint8_t keycode, bool isModifier = false) :
      _keycode(keycode), _isModifier(isModifier) {}

    void onPress() override {
      Serial.print("PRESIONA tecla: ");
      Serial.println(_keycode, HEX);
      bleKeyboard.press(_keycode);
    }

    void onRelease() override {
      Serial.print("SUELTA tecla: ");
      Serial.println(_keycode, HEX);
      bleKeyboard.release(_keycode);
    }

  private:
    uint8_t _keycode;
    bool _isModifier;
};

#endif
