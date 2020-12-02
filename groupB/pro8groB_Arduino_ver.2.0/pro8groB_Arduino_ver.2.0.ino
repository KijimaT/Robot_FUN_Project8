#include <Wire.h>
#include "rgb_lcd.h"
#include <VarSpeedServo.h> 

VarSpeedServo myservo1; //Pin:7
int deg_LR = 90;//Left Right
int deg_LR_check = 0;

VarSpeedServo myservo2; //Pin:8
int deg_UD = 100;//Up Down

VarSpeedServo myservo3; //Pin:12
int deg_M  = 0;//Mouth

VarSpeedServo myservo4; //Pin:13
int deg_T  = 83;//Tail[77-90]

rgb_lcd lcd;
String rx = "";
String cmds[15] = {""}; // 分割された文字列を格納する配列 
int mode_B = 0;
int mode_C = 0;
int mode_D = 0;
int count_D = 0;
int min_D = 62;
int max_D = 80; //尻尾モーターの可動範囲の2倍の値(0~??)

int split(String data, char delimiter, String *dst){
    //分割数 = 分割処理(文字列, 区切り文字, 配列) 
    int index = 0;
    int arraySize = (sizeof(data)/sizeof((data)[0]));  
    int datalength = data.length();
    for (int i = 0; i < datalength; i++) {
        char tmp = data.charAt(i);
        if ( tmp == delimiter ) {
            index++;
            if ( index > (arraySize - 1)) return -1;
        }
        else dst[index] += tmp;
    }
    return (index + 1);
}


void setup() {
    Serial.begin(9600);
    //myservo1.attach(7);
    myservo2.attach(8);
    myservo3.attach(12);
    myservo4.attach(13);
    lcd.begin(16, 2);
    lcd.setRGB(255, 255, 255);//(R,G,B)
    lcd.print("Ready to Serial.");
    delay(1000);

}

void loop() {
    if (Serial.available() > 0){
      rx = Serial.readString();
      int index = split(rx, ',', cmds);
      lcd_reset();
      lcd_write();
    }

    for(int i=0; i < 10; i++){
      if(cmds[i]=="A"){
        deg_LR = cmds[i+1].toInt();
        if(deg_LR != deg_LR_check){
          myservo1.attach(7);
          delay(100);
          if(deg_LR < 180){
            myservo1.write(deg_LR,50,true);
          }
          myservo1.detach();
        }
      }
      if(cmds[i]=="B"){
        mode_B = cmds[i+1].toInt();
      }
      if(cmds[i]=="C"){
        mode_C = cmds[i+1].toInt();
      }
      if(cmds[i]=="D"){
        mode_D = cmds[i+1].toInt();
      }
    }

    servo_control();    //modeに応じて自動的にサーボモータに信号を送り続ける
    
    lcd_write();        //LCDにサーボモータの値等を表示する
    cmds_reset();       //配列の初期化
    delay(100);

}
