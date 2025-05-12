#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Create a servo driver object
Adafruit_PWMServoDriver pwm= Adafruit_PWMServoDriver();

// Define the minimum and maximum pulse width for your servo (adjust according to your servo's specification)
#define SERVOMIN  160 // Minimum pulse length (microseconds)
#define SERVOMAX  600 // Maximum pulse length (microseconds)

// Define the number of the servo channel you want to control
#define SERVO_0 3 // Example channel
#define SERVO_1 4
#define SERVO_2 5
#define SERVO_3 6
#define SERVO_4 7
#define SERVO_5 8
#define SERVO_6 0
#define SERVO_7 1
#define SERVO_8 2
#define SERVO_9 9
#define SERVO_10 10
#define SERVO_11 11

int val(int deg){
  int value=map(deg,0,180,SERVOMIN,SERVOMAX);
  return value;
}

int p0=135,p1=90,p2=90,p3=125,p4=90,p5=105,p6=45,p7=85,p8=110,p9=40,p10=90,p11=85;
void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  pwm.setPWM(SERVO_0,0,val(135));
  pwm.setPWM(SERVO_1,0,val(90));
  pwm.setPWM(SERVO_2,0,val(90));
  pwm.setPWM(SERVO_3,0,val(125));
  pwm.setPWM(SERVO_4,0,val(90));
  pwm.setPWM(SERVO_5,0,val(105));
  pwm.setPWM(SERVO_6,0,val(45));
  pwm.setPWM(SERVO_7,0,val(85));
  pwm.setPWM(SERVO_8,0,val(110));
  pwm.setPWM(SERVO_9,0,val(40));
  pwm.setPWM(SERVO_10,0,val(90));
  pwm.setPWM(SERVO_11,0,val(85));
}
void loop() {
  // Move the servos up
  int i=1,j=1,k=1;
  while(i<=5){
    p4+=0.4;
    p5-=0.8;
    p7+=0.4;
    p8-=0.8;
    pwm.setPWM(SERVO_4,0,val(p4));
    pwm.setPWM(SERVO_5,0,val(p5));
    pwm.setPWM(SERVO_7,0,val(p7));
    pwm.setPWM(SERVO_8,0,val(p8));
    i++;
    delay(10);
  }
  delay(20);
  // move servos down
  while(j<=5){
    p4-=0.8;
    p5+=1.2;
    p7-=0.8;
    p8+=1.2;
    
    pwm.setPWM(SERVO_4,0,val(p4));
    pwm.setPWM(SERVO_5,0,val(p5));
    pwm.setPWM(SERVO_7,0,val(p7));
    pwm.setPWM(SERVO_8,0,val(p8));
    delay(10);
    j++;

  }
  //shoulder Hinge push body forward
  delay(20);
  while(k<=5){
    p4+=0.4;
    p5-=0.4;
    p7+=0.4;
    p8-=0.4;
    pwm.setPWM(SERVO_4,0,val(p4));
    pwm.setPWM(SERVO_5,0,val(p5));
    pwm.setPWM(SERVO_7,0,val(p7));
    pwm.setPWM(SERVO_8,0,val(p8));
    k++;
    delay(10);

  }
}