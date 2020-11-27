void mousePressed(){
    port.write(2);
    if(flag == 1){
    flag = 2;
    //port.write(0); //これはいるのかわからんからとりあえずコメントアウト
  }
  
  
}
