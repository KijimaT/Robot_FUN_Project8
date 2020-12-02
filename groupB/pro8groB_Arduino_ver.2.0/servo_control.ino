void servo_control(){
    /*mode_B*/
    if(mode_B == 0){
      deg_UD = 90;  //首の通常向きの値を入力
    }else if(mode_B == 1){
      deg_UD = 180; //首の下向きMAX値を入力
      mode_B = 0;
    }
    
    /*mode_C*/
    if(mode_C == 0){
      deg_M = 0; //口の閉じた状態の値を入力
    }else if(mode_C == 1){
      deg_M = 20; //口の開いた状態の値を入力
    }
    
    /*mode_D*/
    if(mode_D == 0){
      
    }else if(mode_D == 1){
      if( count_D <= 20  ){
        count_D+=3;
      }else if( 20<count_D && min_D > 53-20 ){
        min_D-=3;
      }else{
        count_D = 0;
        min_D = 62;
      }
      Serial.println(min_D + count_D);
      //count_D += 1;  //尻尾稼働速度
    }

    /*servo write*/
    myservo2.write(deg_UD,50,true);
    myservo3.write(deg_M);
    myservo4.write(min_D + count_D);



}
