import processing.serial.*;

Serial port;

int random = 0;
int scene = 0;
int count = 0;
int flag = 0;//遷移状況管理用変数
int signal=0;

void setup(){
 background(0); 
 //fullScreen();
 size(400,250);
 //mu2();
 port = new Serial(this, "COM5",9600);
}

void draw(){
 signal =port.read();
 println(signal);
 
 if(signal == 100){//Arduinoからint型の0を受け取っている時default1()を実行（デフォルト状態にする）
   count = 0;
   ok();
   while(count<300){
     count++;
   }
   if(count == 300){
     port.write(2);
     default1();
     flag = 1;
   }
 }else if(signal == 101) {
   if(flag == 1){
     default1();
   }else if(flag == 2){//デフォルト状態でタッチを受けた時
     count = 0;
     egao();
     while(count<300){
      count++;
     }
     if(count == 300){
      port.write(1);//今のところArduinoからsignalはずっと2が帰ってくる
      //default1();
      flag = 1;
    }
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
