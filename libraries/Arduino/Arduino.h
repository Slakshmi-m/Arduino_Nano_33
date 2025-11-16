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

// Pin modes
#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2

// Pin states
#define LOW 0x0
#define HIGH 0x1

// Misc
void delay(unsigned long ms);
void delayMicroseconds(unsigned int us);

// Digital I/O
void pinMode(uint8_t pin, uint8_t mode);
void digitalWrite(uint8_t pin, uint8_t val);
int digitalRead(uint8_t pin);
unsigned long pulseIn(uint8_t pin, uint8_t state);

// Analog I/O
int analogRead(uint8_t pin);
void analogReference(uint8_t mode);
void analogWrite(uint8_t pin, int val);

#ifdef __cplusplus
} // extern "C"

// Serial class
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
  
  // Print functions
  void print(const char *str);
  void print(char c);
  void print(unsigned char c);
  void print(int n);
  void print(unsigned int n);
  void print(long n);
  void print(unsigned long n);
  void print(double n);
  
  void println(const char *str);
  void println(char c);
  void println(unsigned char c);
  void println(int n);
  void println(unsigned int n);
  void println(long n);
  void println(unsigned long n);
  void println(double n);
  void println(void);
};

extern HardwareSerial Serial;

#endif

#endif
