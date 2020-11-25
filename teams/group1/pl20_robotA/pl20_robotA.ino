/*
  pl20_robotA.ino
  mainファイル
  作成者 b1018194 Ito Hajime
*/
#include <Wire.h> //I2C通信制御
#include <Servo.h> //サーボ制御
#include <CapacitiveSensor.h> //静電容量センサ制御
#define LED_PIN 11 //PWM
#define SERVO_NECY_PIN 5 //PWM 首(縦)のサーボ
#define SERVO_NECX_PIN 6 //PWM 首(横)のサーボ
#define SERVO_ARMR_PIN 9 //PWM 腕(右)のサーボ
#define SERVO_ARML_PIN 10 //PWM 腕(左)のサーボ
#define TOUCH_INPUT_PIN 8 //静電容量センサのインプット
#define TOUCH_OUTPUT_PIN 9 //静電容量センサのアウトプット
#define LSI_VOICE_ADDRESS 0x2E //音声合成LSIのデバイスアドレス
#define DISTANCE_SENSOR_PIN A0 //赤外線測距センサ

struct TRIGGER
{
  bool awake;
  bool distance;
  bool touch;
  bool none;
};

TRIGGER t;
CapacitiveSensor cs = CapacitiveSensor(TOUCH_OUTPUT_PIN, TOUCH_INPUT_PIN);
Servo nec_y;
Servo nec_x;
Servo arm_r;
Servo arm_l;

void setup()
{
  t = {true, false, false, false};
  pinMode(LED_PIN, OUTPUT);
  nec_y.attach(SERVO_NECY_PIN);
  nec_x.attach(SERVO_NECX_PIN);
  arm_r.attach(SERVO_ARMR_PIN);
  arm_l.attach(SERVO_ARML_PIN);
  cs.set_CS_AutocaL_Millis(0xFFFFFFFF);
  Wire.begin(); //マスターに設定
  Serial.begin(9600); //Serial設定
}

void loop()
{
  handle_trigger(&t);
  delay(500);
}
