#include <Servo.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>

int deg = 90;
int rx, vo, arg, flag;
Servo neck;//首
Servo rs;//右肩
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *legMotor = AFMS.getMotor(1);
Adafruit_DCMotor *headMotor = AFMS.getMotor(2);
Adafruit_DCMotor *rotateMotor  = AFMS.getMotor(3);

void setup() {
  //ArduinoにRaspberry piから電源を供給し、ロボットの動作がスタートする
  Serial.begin(9600);
  //首
  neck.attach(8);
  neck.write(90);
  //右肩
  rs.attach(9);
  rs.write(90);
}

void loop() {
 
  uint8_t i;
  
  
  if (Serial.available() > 0) {

    // 受信したデータを読み込む
    int data = Serial.read();

    if (data == '0') {
    /* TODO */
    /*** 電源を入れた時の動作 ***/
      Serial.print("init");
    //可動範囲調整が必要
    //右肩を左右に動かす
      rs.write(0);
      delay(1000);
      rs.write(80);
    //目線が上を向いて水平にする
    //勢いよく上を向く
      headMotor->run(FORWARD);
      for (i = 0; i < 220; i = i + 10) {
        headMotor->setSpeed(i);
        delay(10);
      }
      for (i = 200; i != 0; i = i - 10) {
        headMotor->setSpeed(i);
        delay(10);
      }
      //一定の速度で水平に
      headMotor->run(BACKWARD);
      headMotor->setSpeed(10);
      delay(10);

        //首を左右に動かす
      neck.write(0);
      delay(1000);
      neck.write(150);
      delay(1000);
      neck.write(90);
      //Raspberry Piにシリアル通信で表情を指示する
      //myMotor->run(RELEASE);
      delay(1000);
      Serial.print("stand by");
      Serial.write(0);//起動完了後Raspberry Piに0を返してデフォルトに移る
    }else if (data == '1') {
      //servo2.write(0);
      Serial.write(2);
    }else if(data == '2'){

    }
  }
}