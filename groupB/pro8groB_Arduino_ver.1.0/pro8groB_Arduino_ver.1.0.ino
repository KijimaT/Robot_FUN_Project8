#include <Wire.h>
#include "rgb_lcd.h"
#include <Servo.h>

Servo myservo1; //Pin:7
int deg_LR = 90;//Left Right

Servo myservo2; //Pin:8
int deg_UD = 90;//Up Down

Servo myservo3; //Pin:12
int deg_M  = 90;//Mouth

Servo myservo4; //Pin:13
int deg_T  = 90;//Tail

rgb_lcd lcd;
String rx = "";
String cmds[15] = {""}; // 分割された文字列を格納する配列 


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
    myservo1.attach(7);
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
        myservo1.write(deg_LR);
      }
      if(cmds[i]=="B"){
        deg_UD = cmds[i+1].toInt();
        myservo2.write(deg_UD);
      }
      if(cmds[i]=="C"){
        deg_M = cmds[i+1].toInt();
        myservo3.write(deg_M);
      }
      if(cmds[i]=="D"){
        deg_T = cmds[i+1].toInt();
        myservo4.write(deg_T);
      }
    }
    
    lcd_write();
    cmds_reset();
    delay(100);

}
