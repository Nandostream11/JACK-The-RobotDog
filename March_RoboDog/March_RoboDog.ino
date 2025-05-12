#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Create a servo driver object
Adafruit_PWMServoDriver pwm= Adafruit_PWMServoDriver();

// Define the minimum and maximum pulse width for your servo (adjust according to your servo's specification)
#define SERVOMIN  160 // Minimum pulse length (microseconds)
#define SERVOMAX  600 // Maximum pulse length (microseconds)

// Define the number of the servo channel you want to control
#define SERVO_0 0 // Example channel
#define SERVO_1 1
#define SERVO_2 2
#define SERVO_3 3
#define SERVO_4 4
#define SERVO_5 5
#define SERVO_6 6
#define SERVO_7 7
#define SERVO_8 8
#define SERVO_9 9
#define SERVO_10 10
#define SERVO_11 11


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
  pwm.setPWM(SERVO_7,0,val(135));
  pwm.setPWM(SERVO_8,0,val(25));
  pwm.setPWM(SERVO_9,0,val(40));
  pwm.setPWM(SERVO_10,0,val(130));
  pwm.setPWM(SERVO_11,0,val(160));
}

int val(int deg){
  int value=map(deg,0,180,SERVOMIN,SERVOMAX);
  return value;
}

void loop() {
  // Move the servo from minimum to maximum position
  for (int p1 = val(105),p2=val(75),p3 = val(95),p4 = val(80); p1 >= val(90) && p2 <= val(105) && p3 >= val(85) && p4<= val(110); p1-=val(1),p2+=val(2),p3-=val(1),p4+=val(2)){
    delay(100);
    pwm.setPWM(SERVO_4,0,p1);
    pwm.setPWM(SERVO_5,0,p2);
    pwm.setPWM(SERVO_7,0,p3);
    pwm.setPWM(SERVO_8,0,p4);
  }
  for (int p1 = val(90),p2=val(105),p3 = val(85),p4 = val(110); p1 <= val(100) && p2 >= val(75) && p3 <= val(95) && p4>= val(80); p1+=val(1),p2-=val(2),p3+=val(1),p4-=val(2)){
    delay(100);
    pwm.setPWM(SERVO_4,0,p1);//20deg
    pwm.setPWM(SERVO_5,0,p2);//40deg
    pwm.setPWM(SERVO_7,0,p3);
    pwm.setPWM(SERVO_8,0,p4);
  } 
  delay(1000);
    
  for (int p1 = val(80),p2=val(120),p3 = val(100),p4 = val(115); p1 <= val(90) && p2 >= val(90) && p3 >= val(90) && p4>= val(85); p1+=val(1),p2-=val(2),p3-=val(1),p4-=val(2)){
    delay(100);
    pwm.setPWM(SERVO_1,0,p1);
    pwm.setPWM(SERVO_2,0,p2);
    pwm.setPWM(SERVO_10,0,p3);
    pwm.setPWM(SERVO_11,0,p4);
  }
  for (int p1 = val(90),p2=val(90),p3 = val(90),p4 = val(85); p1 >= val(80) && p2 <= val(120) && p3 <= val(100) && p4<= val(115); p1-=val(1),p2+=val(2),p3+=val(1),p4+=val(2)){
    delay(100);
    pwm.setPWM(SERVO_1,0,p1);
    pwm.setPWM(SERVO_2,0,p2);
    pwm.setPWM(SERVO_10,0,p3);
    pwm.setPWM(SERVO_11,0,p4);
  }

// int time=0;
  // int inc1=val(5);
  // int inc2=val(7.5);
  // int curr1=90;
  // int curr2=105;
  // while(time<4){
  //   curr1+=inc1;
  //   curr2-=inc2;
  //   pwm.setPWM(SERVO_4,0,curr1);
  //   pwm.setPWM(SERVO_5,0,curr2);
  //   delay(1000);
  //   time++;
  // }
  //   time=0;
  //   while(time<4){
  //   curr1-=inc1;
  //   curr2+=inc2;
  //   pwm.setPWM(SERVO_4,0,curr1);
  //   pwm.setPWM(SERVO_5,0,curr2);
  //   delay(1000);
  //   time++;
  // }
  // for (int p1 = val(110),p2=val(65),p3 = val(105),p4 = val(50); p1 >= val(90) && p2 <= val(105) && p3 >= val(85) && p4<= val(90); p1-=val(2.5),p2+=val(5),p3-=val(2.5),p4+=val(5)){
  //   delay(1000);
  //   pwm.setPWM(SERVO_4,0,p1);
  //   pwm.setPWM(SERVO_5,0,p2);
  //   pwm.setPWM(SERVO_7,0,p3);
  //   pwm.setPWM(SERVO_8,0,p4);
  // }
  // for (int p1 = val(90),p2=val(105),p3 = val(85),p4 = val(90); p1 <= val(110) && p2 >= val(65) && p3 <= val(105) && p4>= val(50); p1+=val(2.5),p2-=val(5),p3+=val(2.5),p4-=val(5)){
  //   delay(1000);
  //   pwm.setPWM(SERVO_4,0,p1);//20deg
  //   pwm.setPWM(SERVO_5,0,p2);//40deg
  //   pwm.setPWM(SERVO_7,0,p3);
  //   pwm.setPWM(SERVO_8,0,p4);
  // }
  
  // delay(2000);
    
  // for (int p1 = val(70),p2=val(130),p3 = val(110),p4 = val(130); p1 <= val(90) && p2 >= val(90) && p3 >= val(90) && p4>= val(90); p1+=val(2.5),p2-=val(5),p3-=val(2.5),p4-=val(5)){
  //   delay(1000);
  //   pwm.setPWM(SERVO_1,0,p1);
  //   pwm.setPWM(SERVO_2,0,p2);
  //   pwm.setPWM(SERVO_10,0,p3);
  //   pwm.setPWM(SERVO_11,0,p4);
  // }
  // for (int p1 = val(90),p2=val(90),p3 = val(90),p4 = val(90); p1 >= val(70) && p2 <= val(130) && p3 <= val(110) && p4<= val(130); p1-=val(2.5),p2+=val(5),p3+=val(2.5),p4+=val(5)){
  //   delay(1000);
  //   pwm.setPWM(SERVO_1,0,p1);
  //   pwm.setPWM(SERVO_2,0,p2);
  //   pwm.setPWM(SERVO_10,0,p3);
  //   pwm.setPWM(SERVO_11,0,p4);
  // }

  // for (int pulselen = val2; pulselen > val1; pulselen--){
  //   pwm.setPWM(SERVO_1,0,pulselen);
  //   delay(100);
  // }
  // Serial.println(pwm.getPWM(SERVO_1,true));
  // for (int pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++) {
  //   pwm.setPWM(SERVO_1, 0, pulselen);
  //   pwm.setPWM(SERVO_2, 0, pulselen);
  //   delay(10);
  // }

  
  // Move the servo from maximum to minimum position
  // for (int pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--) {
  //   uint16_t onTime=pwm.getPWM(SERVO_1,true);
  //   Serial.println(onTime);
  //   pwm.setPWM(SERVO_1, 0, pulselen);
  //   pwm.setPWM(SERVO_2, 0, pulselen);
  //   delay(100);
  // }

}
