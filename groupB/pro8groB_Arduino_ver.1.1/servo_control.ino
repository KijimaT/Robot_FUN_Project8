void servo_control(){
    /*mode_B*/
    if(mode_B == 0){
      //deg_UD == ; //首の通常向きの値を入力
    }else if(mode_B ==1){
      //deg_UD == ; //首の下向きMAX値を入力
    }
    
    /*mode_C*/
    if(mode_C == 0){
      
    }else if(mode_C == 1){

    }
    
    /*mode_D*/
    if(mode_D == 0){
      
    }else if(mode_D == 1){
      if( 0<=count_D && count_D<=180 ){
        deg_T = count_D;
      }else if( 180<count_D && count_D<=360 ){
        deg_T = 180 - (count_D-180);
      }else{
        count_D == 0;
      }
      
      count_D += (deg_T % 140);
    }

    /*servo write*/
    myservo2.write(deg_UD);
    myservo3.write(deg_M);
    myservo4.write(deg_T);



}
