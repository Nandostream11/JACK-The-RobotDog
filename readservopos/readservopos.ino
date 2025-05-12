#include <Servo.h>

// Create a Servo object
Servo servoMotor;

// Define the pin to which the servo signal wire is connected
const int servoPin = 9;

const int fixed=93;

void setup() {
  // Start serial communication
  Serial.begin(9600);
  // Attach the servo to the pin
  servoMotor.attach(servoPin);
}

void loop() {
  // Read the current position of the servo
  int currentPosition = servoMotor.read();
  Serial.println(currentPosition);
  // Print the current position to the serial monitor
  // if(currentPosition<fixed){
  //   servoMotor.write(currentPosition+10);
  // }

  delay(1000);
// Wait for 1 second before reading again
}
