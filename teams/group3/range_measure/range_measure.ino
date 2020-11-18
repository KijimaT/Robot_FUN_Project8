#include <Servo.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>

int deg = 90;
int rx, vo, arg, flag;
Servo neck, rshoulder;
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *legMotor1 = AFMS.getMotor(1);

void setup() {
  Serial.begin(9600);
  neck.attach(8);
  rshoulder.attach(9);
  
  /*
  myservo1.write(120);
  myservo2.write(120);
  /*
  AFMS.begin();
  myMotor->setSpeed(150);
  myMotor->run(FORWARD);
  // turn on motor
  myMotor->run(RELEASE);
  */
}

void loop() {
  uint8_t i;

  Serial.print("tick");

  myMotor->run(FORWARD);
  for (i = 0; i < 255; i++) {
    myMotor->setSpeed(i);
    delay(10);
  }
  for (i = 255; i != 0; i--) {
    myMotor->setSpeed(i);
    delay(10);
  }

  Serial.print("tock");

  myMotor->run(BACKWARD);
  for (i = 0; i < 255; i++) {
    myMotor->setSpeed(i);
    delay(10);
  }
  for (i = 255; i != 0; i--) {
    myMotor->setSpeed(i);
    delay(10);
  }

  Serial.print("tech");
  myMotor->run(RELEASE);
  delay(1000);
}
  
  /*
  //rx = Serial.read();
  //vo = analogRead(A0);
  //arg = myservo.read();
  //TODO:ボリューム抵抗とサーボの回転を同期させる
  /*
    if(vo <=60){
    deg = 0;
    }else if(vo >60 && vo <962){
    deg = 0.2 * vo -12;
    }else{
    deg = 180;
    }

    if(rx == '1') flag = 1;
    else if(rx == '0') flag = 0;
    if(flag){
    Serial.print(vo); //シリアル送信
    Serial.print(','); //シリアル送信
    Serial.print(deg); //シリアル送信
    Serial.print('\n'); //シリアル送信
    }
  */
  /*
  deg = 90;
  myservo1.write(deg);
  myservo2.write(deg);
  //delay(500);
  delayMicroseconds(20000);
  uint8_t i;

  Serial.print("tick");

  myMotor->run(FORWARD);
  for (i = 0; i < 255; i++) {
    myMotor->setSpeed(i);
    delay(10);
  }
  for (i = 255; i != 0; i--) {
    myMotor->setSpeed(i);
    delay(10);
  }

  Serial.print("tock");

  myMotor->run(BACKWARD);
  for (i = 0; i < 255; i++) {
    myMotor->setSpeed(i);
    delay(10);
  }
  for (i = 255; i != 0; i--) {
    myMotor->setSpeed(i);
    delay(10);
  }

  Serial.print("tech");
  myMotor->run(RELEASE);
  delay(1000);
  */
//}
