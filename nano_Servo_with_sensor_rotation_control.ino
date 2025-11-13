#include <Servo.h>

const int trigPin = 8;
const int echoPin = 9;
Servo myServo;

void setup() {
  Serial.begin(9600);
  myServo.attach(7);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration;
  int distance;

  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure echo time
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // Convert to cm

  // Print distance
  Serial.print(distance);

  // Determine servo angle
  int angle;
  if (distance <= 30)
    angle = 30;
  else if (distance <= 100)
    angle = 60;
  else if (distance <= 300)
    angle = 90;
  else if (distance <= 600)
    angle = 120;
  else
    angle = 180;

  // Move servo
  myServo.write(angle);

  Serial.print("Servo Angle: ");
  Serial.println(angle);

  delay(500); // Wait before next measurement
}
