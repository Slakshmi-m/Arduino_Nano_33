#include <Arduino.h>
#include <Servo.h>

Servo myServo;
int pos = 0;

void setup(){
    Serial.begin(9600);
    myServo.attach(7);
    myServo.write(0);
}

void loop(){
    for (pos = 0; pos <= 180; pos += 2){
        myServo.write(pos);
        delay(15);
    }

    for(pos = 180; pos >= 0; pos -= 2){
        myServo.write(pos);
        delay(15);
    }
}