int time =0;
void default1() {
  //int time=0;
  if (flag == 1) {
    if (scene == 0) {
      no();
      delay(1000);
      scene = num % 5;
    } else if (scene == 1) {
      mu();
      delay(1000);
      //println("time:"+time);
      no();
      scene = num % 5;
    } else if (scene == 2) {

      mu2();
      delay(1000);
      no();
      scene = num % 5;
    } else if (scene == 3) {

      egao();
      delay(1000);
      no();
      scene = num % 5;
    } else if (scene == 4) {
      egao2();
      delay(1000);
      no();
      scene = num % 5;
   }
  } else {
    //default1が呼び出されててもタッチでflagが2ならばegaoを表示する
    egao();
    //Arduinoには2を送信して、102が帰ってくる
  }
}
