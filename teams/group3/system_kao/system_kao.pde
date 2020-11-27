import processing.serial.*;

Serial port;

int random = 0;
int scene = 0;//画面遷移切り替え用変数
int count = 0;//時間管理用変数
int flag = 0;//タッチ管理での状態遷移状況管理用変数
int signal=0;//arduinoからの値100~
int sInit = 0;

void setup() {
  background(0); 
  //fullScreen();
  size(400, 250);
  //mu2();
  port = new Serial(this, "/dev/ttyACM0", 9600);
}

void draw() {
  delay(100);
  signal =port.read();
  println(signal);

  /*signalが0か100の時*/
  if (signal==0) {//signal=0(初期値)
    /*TODO*/
    //Loading...など表示する？

    port.write(1);//Arduinoに1を送る
  } else if (signal == 100) {//Arduinoから100を受け取ってる時okを実行（デフォルト状態にする）
    count = 0;
    ok();
    /*TODO*/
    //Arduinoへokを表示していることを伝える
    port.write(1);
    //flag = 1;
  } else if (signal == 101) {
    /*TODO*/
    //通信のタイミング?が分からないので(?)
    //初回の通信を確認したら(101)、時間経過でデフォルトに移行するようにしたい
    //flagをどう使うか？
    //→
    flag =1;
    default1();
    /*
    if (flag == 2) {//デフォルト状態でタッチを受けた時
      //count = 0;
      egao();
      delay(2500);
      port.write(1);
      flag = 1;
      /*
     while(count<300){
       count++;
       }
       if(count == 300){
       
       //default1();
       
       }*/
       
    
  } else if (signal ==102) {
    /*TODO*/
    //起動完了後の動作
    egao();
    delay(2500);
    port.write(1);
    flag = 1;
  } else {
    port.write(0);
  }
}


/*

 scene は画面遷移切り替え用変数。
 flag はタッチ管理での状態遷移状況管理用変数。
 random は乱数生成用変数。乱数はdefaultでの画面切り替えに用いる。
 count は時間管理用変数。
 
 ・モーターの動作と顔の表情の連携についてはそれぞれの顔関数(kao部分にある関数)にあるport.write(番号)の番号により、
 　Arduino側に表情が変わったことを伝える。
 →100番代にしてみた
 */
