#include <Servo.h>

const int servoPin = 9;  // Pin connected to the servo signal wire

Servo needleServo;

const int needleIn = 110;   // Angle for needle in position
const int needleOut = 0;   // Angle for needle out position
const int moveDelay = 20;  // Delay between each degree of movement (milliseconds)
const int holdTime = 5000; // Time to hold the needle inside (milliseconds)

void setup() {
  needleServo.attach(servoPin);
  needleServo.write(needleOut); // Initial position
}

void loop() {
  // Move the needle in quickly
  needleServo.write(needleIn);
  delay((needleIn - needleOut) * moveDelay); // Calculate time to move in

  // Hold the needle inside for 5 seconds
  delay(holdTime);

  // Move the needle out quickly
  needleServo.write(needleOut);
  delay((needleIn - needleOut) * moveDelay); // Calculate time to move out

  // Add a delay before the next cycle (optional)
  delay(1500);
}