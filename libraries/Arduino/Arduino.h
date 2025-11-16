/*
  Arduino.h - Main include file for the Arduino SDK
*/

#ifndef Arduino_h
#define Arduino_h

#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifdef __cplusplus
extern "C"{
#endif

typedef unsigned char byte;
typedef unsigned char uint8_t;

// Misc
void delay(unsigned long ms);
void delayMicroseconds(unsigned int us);

// Digital I/O
void pinMode(uint8_t pin, uint8_t mode);
void digitalWrite(uint8_t pin, uint8_t val);
int digitalRead(uint8_t pin);

// Analog I/O
int analogRead(uint8_t pin);
void analogReference(uint8_t mode);
void analogWrite(uint8_t pin, int val);

// Serial
class HardwareSerial
{
public:
  HardwareSerial();
  void begin(unsigned long baud);
  void begin(unsigned long baud, byte config);
  void end();
  virtual int available(void);
  virtual int peek(void);
  virtual int read(void);
  int availableForWrite(void);
  virtual void flush(void);
  virtual size_t write(uint8_t);
};

extern HardwareSerial Serial;

#ifdef __cplusplus
} // extern "C"
#endif

#endif
