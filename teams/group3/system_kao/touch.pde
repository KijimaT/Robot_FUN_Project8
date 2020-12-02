void mousePressed(){
    
    if(signal==101){
      port.write(2);
      if(flag == 1){
      flag = 2;
    //port.write(0); //これはいるのかわからんからとりあえずコメントアウト
    }
  }
    
  
  
}
