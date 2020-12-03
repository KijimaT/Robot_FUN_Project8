#include <VarSpeedServo.h>
//#include <Servo.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>

int deg = 90;
int rx, vo, arg, flag;
int mInit = 0;
int sInit = 0;
int data = 0; //RaspberryPiからの信号用
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
#define SERVO_RS_SPEED3 10

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *legMotor = AFMS.getMotor(DC_LEG_PIN);
Adafruit_DCMotor *headMotor = AFMS.getMotor(DC_HEAD_PIN);
//Adafruit_DCMotor *rotateMotor  = AFMS.getMotor(DC_ROTATE_PIN);

void setup() {
  //ArduinoにRaspberry piから電源を供給し、ロボットの動作がスタートする
  Serial.begin(115200);
}

void loop() {
  uint8_t i;
  //受信したデータを読み込む
  data = Serial.read();
  Serial.println(data);
  /** 電源を入れた時の動作 **/
  if (data == 0) { //RaspberryPiとの通信の確認前
    /*** モータの初期動作　***/
    if (mInit == 0) {
      neck.attach(SERVO_NECK_PIN);
      rs.attach(SERVO_RSHOULDER_PIN);
      rs.write(80, SERVO_RS_SPEED1, true);
      neck.write(90, SERVO_NECK_SPEED1, true);
      delay(3000);
      //可動範囲調整が必要
      //右腕を上下に動かす
      rs.write(60, SERVO_RS_SPEED1, true);
      delay(100);
      rs.write(120, SERVO_RS_SPEED1, true);
      rs.write(90, SERVO_RS_SPEED1, true);
      delay(3000);
      AFMS.begin();
      //目線が上を向いて水平にする
      /*
      headMotor->run(FORWARD);
      for (i = 0; i < 120; i = i + 10) {
        headMotor->setSpeed(i);
        delay(1000);
      }
      for (i = 120; i != 0; i = i - 10) {
        headMotor->setSpeed(i);
        delay(1000);
      }
      headMotor->run(RELEASE);
      //一定の速度で水平に
      headMotor->setSpeed(10);
      headMotor->run(BACKWARD);
      delay(1000);
      headMotor->run(RELEASE);
      delay(1000);
      */
      //首を左右に動かす
      neck.write(60, SERVO_NECK_SPEED2, true);
      delay(1000);
      neck.write(120, SERVO_NECK_SPEED2, true);
      delay(1000);
      neck.write(90, SERVO_NECK_SPEED1, true);
      //neck.wait();

      //Raspberry Piにシリアル通信で表情を指示する
      //myMotor->run(RELEASE);
      delay(1000);
      neck.detach();
      rs.detach();
      mInit = 1; //モータの初期動作完了
      Serial.write(100);
    } else {
      if (sInit == 0) {
        Serial.write(0);
      } else {
        Serial.write(100);
      }
    }


  } else if (data == 1) {
    if (sInit == 0) {
      //Serial.print("stand by");
      //Serial.write(100);//初回の通信
      //RaspberryPiから1を受け取ったら
      sInit = 1;//初回の通信を記録
    } else {
      Serial.write(101);//デフォルトに行けるように101を送信
    }
    //
  } else if (data == 2 ) {
    //タップしたときのegaoでモータを動かす
    //neck.attach(SERVO_NECK_PIN);
    delay(500);
    rs.attach(SERVO_RSHOULDER_PIN);
    rs.write(120, SERVO_RS_SPEED1, true);
    rs.write(90, SERVO_RS_SPEED1, true);
    delay(3000);
    Serial.write(102);
  } else if (data == 3) {
    //servo2.write(0);
    Serial.write(3);
  } else if (data == 20) {
    delay(500);
    rs.attach(SERVO_RSHOULDER_PIN);
    rs.write(75, SERVO_RS_SPEED3, true);
    Serial.write(101);
  } else if (data == 21){
    delay(500);
    rs.attach(SERVO_RSHOULDER_PIN);
    rs.write(110, SERVO_RS_SPEED1, true);
    Serial.write(101);
  } else if(data == 22){
    delay(500);
    rs.attach(SERVO_RSHOULDER_PIN);
    rs.write(90, SERVO_RS_SPEED3, true);
    Serial.write(101);
  } else if(data ==23){
    delay(500);
    rs.attach(SERVO_RSHOULDER_PIN);
    rs.write(110, SERVO_RS_SPEED3, true);
    rs.write(105, SERVO_RS_SPEED2,true);
    rs.write(110, SERVO_RS_SPEED2,true);
    rs.write(105, SERVO_RS_SPEED2,true);
    Serial.write(101);
  }
}
