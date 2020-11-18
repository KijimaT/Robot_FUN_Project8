#include <Servo.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>

int deg = 90;
int rx, vo, arg, flag;
Servo neck, rs;
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *legMotor = AFMS.getMotor(1);
Adafruit_DCMotor *headMotor = AFMS.getMotor(2);
//Adafruit_DCMotor *rotateMotor  = AFMS.getMotor(3);

/*TODO*/
void setup() {
  //Arduinoに電源を供給し、ロボットの動作がスタートする
  Serial.begin(9600);
  //首
  neck.attach(8);
  //右肩
  rs.attach(9);
 
  /*** 電源を入れた時の動作 ***/
  uint8_t i;
  Serial.print("init");
  /* TODO */
  //可動範囲調整が必要
  //右肩を左右に動かす
  rs.write();
  //目線が上を向いて水平にする
  //勢いよく上を向く
  headMotor->run(FORWARD);
   for (i = 0; i < 220; i=i+10) {
    headMotor->setSpeed(i);
    delay(10);
  }
  for (i=200; i!=0; i=i-10) {
    headMotor->setSpeed(i);  
    delay(10);
  }
  //一定の速度で水平に
  headMotor->run(BACKWARD);
  headMotor->setSpeed(i);
    delay(10);
  }
  //首を左右に動かす
  neck.write();
  //Raspberry Piにシリアル通信で表情を指示する
  Serial.write();
  myMotor->run(RELEASE);
  delay(1000);

  Serial.print("stand by");
}

void loop() {
 
}
