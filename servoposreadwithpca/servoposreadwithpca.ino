#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Create a servo driver object
Adafruit_PWMServoDriver pwm= Adafruit_PWMServoDriver();

// Define the minimum and maximum pulse width for your servo (adjust according to your servo's specification)
#define SERVOMIN  160 // Minimum pulse length (microseconds)
#define SERVOMAX  600 // Maximum pulse length (microseconds)

// Define the number of the servo channel you want to control
#define SERVO_1 5 // Example channel
#define SERVO_2 6

void setup() {
  Serial.begin(9600);
  Wire.begin();
  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
}

void loop() {
  // Move the servo from minimum to maximum position
  // Read the current pulse width of the servo
  uint16_t onTime, offTime;
  onTime = pwm.getPWM(SERVO_1, true);
int pulseWidth = map(onTime, 0, 4095, SERVOMIN, SERVOMAX);

  
  // Map the pulse width to degrees
  int degrees = map(pulseWidth, SERVOMIN, SERVOMAX, 0, 180);

  // Print the current position
  Serial.print("Current position: ");
  Serial.println(degrees);
  // for (int pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++) {
  //   pwm.setPWM(SERVO_1, 0, pulselen);
  //   pwm.setPWM(SERVO_2, 0, pulselen);
  //   delay(10);
  // }
  // delay(1000);
  
  // // Move the servo from maximum to minimum position
  // for (int pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--) {
  //   pwm.setPWM(SERVO_1, 0, pulselen);
  //   pwm.setPWM(SERVO_2, 0, pulselen);
  //   delay(10);
  // }
  // delay(1000);
}