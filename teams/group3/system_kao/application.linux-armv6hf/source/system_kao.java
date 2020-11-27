import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import processing.serial.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class system_kao extends PApplet {



Serial port;

int random = 0;
int scene = 0;//画面遷移切り替え用変数
int count = 0;//時間管理用変数
int flag = 0;//タッチ管理での状態遷移状況管理用変数
int signal=0;//arduinoからの値100~
int sInit = 0;

public void setup() {
  background(0); 
  //fullScreen();
  
  //mu2();
  port = new Serial(this, "/dev/ttyACM0", 9600);
}

public void draw() {
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
    }
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

public void default1(){
  int time=0;
  if(scene == 0){
      no();
      random = (int)random(0,255);
      if(random%5 == 0){
        
        scene = 1;
      }else if(random%5 == 1){
        
        scene = 2;
     }else if(random%5 == 2){
      
      scene = 3;
     }else if(random%5 == 3){
     
      scene = 4;
      }else if(random%5 == 4){
     
      scene = 0;
     }
    }
  else if(scene == 1){
    egao();
    time++;
    if(time==300){
      time=0;
      no();
      random = (int)random(0,255);
      if(random%5 == 0){
        
        scene = 2;
      }else if(random%5 == 1){
        
        scene = 2;
     }else if(random%5 == 2){
      
      scene = 3;
     }else if(random%5 == 3){
      
      scene = 4;
      }else if(random%5 == 4){
      
      scene = 0;
     }
   }
  }else if(scene == 2){
    mu2();
    if(time==300){
      time=0;
      no();
      random = (int)random(0,255);
      if(random%5 == 0){
        
        scene = 1;
      }else if(random%5 == 1){
        
        scene = 3;
     }else if(random%5 == 2){
      
      scene = 3;
     }else if(random%5 == 3){
      
      scene = 4;
      }else if(random%5 == 4){
      
      scene = 0;
     }
    }
  }else if(scene == 3){
    egao2();
    time++;
    if(time==300){
      time=0;
      no();
      random = (int)random(0,255);
      if(random%5 == 0){
        
        scene = 1;
      }else if(random%5 == 1){
        
        scene = 2;
     }else if(random%5 == 2){
      
      scene = 1;
     }else if(random%5 == 3){
      
      scene = 4;
      }else if(random%5 == 4){
      
      scene = 0;
     }
    }
  }else if(scene == 4){

      //no();
      random = (int)random(0,255);
      if(random%5 == 0){
        
        scene = 1;
      }else if(random%5 == 1){
        
        scene = 2;
     }else if(random%5 == 2){
      
      scene = 3;
     }else if(random%5 == 3){
      
      scene = 0;
      }else if(random%5 == 4){
      
      scene = 0;
     }
    
  }
}
//顔

public void no(){
  background(0);
}



public void mu(){//モータ制御用変数port.write(1)
    fill(0xff006400);
    ellipse(width/4,height/3,width*1/10,width*1/10);
    ellipse(width*3/4,height/3,width*1/10,width*1/10);
    rect(width*375/1000,height*6/10,width*2/10+10,height*1/20);//無表情
}

public void mu2(){//モータ制御用変数port.write(2)
    fill(0xff006400);
    ellipse(width/4,height/3,width*1/10,width*1/10);
    ellipse(width*3/4,height/3,width*1/10,width*1/10);
    rect(150,150,100,20);//無表情
}

public void egao(){//モータ制御用変数port.write(3)
    fill(0xff006400);
    ellipse(width*375/1000,height*75/100,20,20);
    ellipse(width*250/1000,75,20,20);
    arc(width/2, height*150/1000, 130, 130, radians(0), radians(180)); //口笑顔
}

public void egao2(){//モータ制御用変数port.write(4)
    fill(0xff006400);
    arc(150, 75, 50, 50, radians(180), radians(360));
    arc(width-150, 75, 50, 50, radians(180), radians(360));
    arc(width/2, 150, 130, 130, radians(0), radians(180)); 
    fill(0,0,0);
    arc(150, 75, 30, 30, radians(180), radians(360));
    arc(width-150, 75, 30, 30, radians(180), radians(360));
    
}

public void ok(){//モータ制御用変数port.write(5)
    fill(0xff006400);
    textSize(75);
    text("OK!",width/3,height/2);
}
public void mousePressed(){
    port.write(2);
    if(flag == 1){
    flag = 2;
    //port.write(0); //これはいるのかわからんからとりあえずコメントアウト
  }
  
  
}
  public void settings() {  size(400, 250); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "--present", "--window-color=#030000", "--stop-color=#cccccc", "system_kao" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
