int num = 0;
int scene = 0;//画面遷移切り替え用変数
int count = 0;//時間管理用変数
int flag = 0;//タッチ管理での状態遷移状況管理用変数
int signal = 0;//arduinoからの値100~
int sInit = 0;

void setup() {
  background(0); 
  //fullScreen();
  size(400, 250);
  //mu2();
  //port = new Serial(this, "/dev/ttyACM0", 9600);
}

void draw() {
 // delay(100);
  //signal =port.read();
  num = (int)random(0,255);
  /*
  print(signal);
  print(",");
  print(num%5);
  print(",");
  println(scene);
  println("flag:"+flag);
  */

  /*signalが0か100の時*/
  if (signal==0) {//signal=0(初期値)
    /*TODO*/
    //Loading...など表示する？
    signal = 100;
    //port.write(1);//Arduinoに1を送る
  } else if (signal == 100) {//Arduinoから100を受け取ってる時okを実行（デフォルト状態にする）
    count = 0;
    ok();
    signal = 101;
    /*TODO*/
    //Arduinoへokを表示していることを伝える
    //port.write(1);
    //flag = 1;
  } else if (signal == 101) {
    /*TODO*/
    //通信のタイミング?が分からないので(?)
    //初回の通信を確認したら(101)、時間経過でデフォルトに移行するようにしたい
    //flagをどう使うか？
    //→
    no();
    flag = 1;
    default1();
    //background(0);
    //port.write(1);
    
  } else if (signal == 102) {
    /*TODO*/
    //起動完了後の動作
    no();
    good();
    delay(2500);//遅延させて、デフォルトに戻る
    //port.write(1);
    flag = 1;
    delay(2500);
    signal = 101;
  } else {
    //port.write(0);
  }
}
