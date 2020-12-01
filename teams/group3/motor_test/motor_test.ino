//#include <Servo.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <VarSpeedServo.h>

int deg = 90;
int rx, vo, arg, flag;
int mInit = 0;
int sInit = 0;
int data = 0; //RaspberryPiからの信号用
int signal = 0;
VarSpeedServo neck;//首
VarSpeedServo rs;//右肩
#define DC_HEAD_PIN 1
#define DC_LEG_PIN 2
#define DC_ROTATE_PIN 3
#define SERVO_NECK_PIN 10
#define SERVO_RSHOULDER_PIN 9

#define SERVO_NECK_SPEED1 20
#define SERVO_NECK_SPEED2 50
#define SERVO_RS_SPEED1 20
#define SERVO_RS_SPEED2 65

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *legMotor = AFMS.getMotor(DC_LEG_PIN);
Adafruit_DCMotor *headMotor = AFMS.getMotor(DC_HEAD_PIN);
//Adafruit_DCMotor *rotateMotor  = AFMS.getMotor(DC_ROTATE_PIN);

void setup() {
  
  //ArduinoにRaspberry piから電源を供給し、ロボットの動作がスタートする
  Serial.begin(9600);
  neck.attach(SERVO_NECK_PIN);
  rs.attach(SERVO_RSHOULDER_PIN);
}

void loop() {
  uint8_t i;
  //シリアルモニタからデータを書き込んでテスト
  data = Serial.read();

  /** 電源を入れた時の動作 **/
  if (data == 1) { //RaspberryPiとの通信の確認前
    /*** モータの初期動作　***/
    if (mInit == 0) {
      //Serial.print("init");
      rs.write(80, SERVO_RS_SPEED1);
      neck.write(90, SERVO_NECK_SPEED1);
      //neck.wait();
      //rs.wait();
      //可動範囲調整が必要
      //右腕を上下に動かす
      rs.write(60, SERVO_RS_SPEED2);
      rs.write(120, SERVO_RS_SPEED2);
      //目線が上を向いて水平にする
      //勢いよく上を向く
      /*
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
        　　　 */
      //首を左右に動かす
      neck.write(60, SERVO_NECK_SPEED2);
      neck.write(120, SERVO_NECK_SPEED2);
      //neck.wait();

      //Raspberry Piにシリアル通信で表情を指示する
      //myMotor->run(RELEASE);
      delay(1000);
      mInit = 1; //モータの初期動作完了
    } else {
      if (sInit == 0) {
        //Serial.write(100);
        signal == 100;
      } else {
        //Serial.write(101);
        signal = 101;
      }
    }


  } else if (data == 2) {
    if (sInit == 0) {
      //Serial.print("stand by");
      //Serial.write(100);//初回の通信
      signal = 100;
      //RaspberryPiから1を受け取ったら
      sInit = 1;//初回の通信を記録
    } else {
      //Serial.write(101);//デフォルトに行けるように101を送信
    }
    //
  } else if (data == 3 ) {
    //タップしたときのegaoでモータを動かす
    //Serial.write(102);
    signal = 102;
  } else if (data == 4) {
    //servo2.write(0);
    //Serial.write(103);
    signal = 103;
  } else if (data == 5) {

  }
}
