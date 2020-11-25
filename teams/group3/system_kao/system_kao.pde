import processing.serial.*;

Serial port;

int random = 0;
int scene = 0;
int count = 0;
int flag = 0;//遷移状況管理用変数

void setup(){
 background(0); 
 //fullScreen();
 size(400,250);
 mu2();
 //port = new Serial(this, "/dev/cu.usbmodem14101",9600);
 //port.write(0);//コードが起動した時にArduinoに起動したという合図を出す。
}

void draw(){
 count++;
 if(port.read() == 0){//Arduinoからint型の0を受け取った時default1()を実行（デフォルト状態にする）
   ok();
   count = 0;
   if(count > 300){
     default1();
     flag = 1;
   }
 }
 if(flag == 2)//デフォルト状態でタッチを受けた時
 {
   count = 0;
   egao();
   if(count > 300){
     default1();
   }
 }
   
}


/*

scene は画面遷移切り替え用変数。
flag はタッチ管理での状態遷移状況管理用変数。
random は乱数生成用変数。乱数はdefaultでの画面切り替えに用いる。
count は時間管理用変数。

・モーターの動作と顔の表情の連携についてはそれぞれの顔関数(kao部分にある関数)にあるport.write(番号)の番号により、
　Arduino側に表情が変わったことを伝える。

*/
