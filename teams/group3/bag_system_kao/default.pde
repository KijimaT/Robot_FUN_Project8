void default1(){  
  if(scene == 0){
      scene = 1;
      println("d_count:"+d_count);
      random = (int)random(0,255);
      if(d_count > 300){
      if(random%5 == 0){
        d_count = 0;
        scene = 2;
      }else if(random%5 == 1){
        d_count = 0;
        scene = 3;
     }else if(random%5 == 2){
      d_count = 0;
      scene = 4;
     }else if(random%5 == 3){
      d_count = 0;
      scene = 5;
      }else if(random%5 == 4){
      d_count = 0;
      scene = 5;
     }
    }
  }
  else if(scene == 1){
    scene = 2;
    println("d_count"+d_count);
    if(d_count > 300){
    if(count>300){
      no();
      random = (int)random(0,255);
      if(random%5 == 0){
        d_count = 0;
        scene = 1;
      }else if(random%5 == 1){
        d_count = 0;
        scene = 2;
     }else if(random%5 == 2){
      d_count = 0;
      scene = 3;
     }else if(random%5 == 3){
      d_count = 0;
      scene = 4;
      }else if(random%5 == 4){
      d_count = 0;
      scene = 5;
     }
   }}
  }else if(scene == 2){
    scene = 3;
    println("d_count:"+d_count);
    if(d_count > 300){
    if(d_count>300){
      no();
      random = (int)random(0,255);
      if(random%5 == 0){
        d_count = 0;
        scene = 1;
      }else if(random%5 == 1){
        d_count = 0;
        scene = 2;
     }else if(random%5 == 2){
      d_count = 0;
      scene = 3;
     }else if(random%5 == 3){
      d_count = 0;
      scene = 4;
      }else if(random%5 == 4){
      d_count = 0;
      scene = 5;
     }
    }}
  }else if(scene == 3){
    scene = 4;
    println("d_count:"+d_count);
    if(d_count>300){
      no();
      random = (int)random(0,255);
      if(random%5 == 0){
        d_count = 0;
        scene = 1;
      }else if(random%5 == 1){
        d_count = 0;
        scene = 2;
     }else if(random%5 == 2){
      d_count = 0;
      scene = 3;
     }else if(random%5 == 3){
      d_count = 0;
      scene = 4;
      }else if(random%5 == 4){
      d_count = 0;
      scene = 5;
     }
    }
  }else if(scene == 4){
    no();
    scene = 5;
    println("d_count:"+d_count);
    if(d_count>300){
      no();
      d_count = 0;
      random = (int)random(0,255);
      if(random%5 == 0){
        d_count = 0;
        scene = 1;
      }else if(random%5 == 1){
        d_count = 0;
        scene = 2;
     }else if(random%5 == 2){
      d_count = 0;
      scene = 3;
     }else if(random%5 == 3){
      d_count = 0;
      scene = 4;
      }else if(random%5 == 4){
      d_count = 0;
      scene = 5;
     }
    }
  }else if(scene == 5){
     no();
    scene = 1;
    println("d_count:"+d_count);
    if(d_count>300){
      no();
      d_count = 0;
      random = (int)random(0,255);
      if(random%5 == 0){
        d_count = 0;
        scene = 1;
      }else if(random%5 == 1){
        d_count = 0;
        scene = 2;
     }else if(random%5 == 2){
      d_count = 0;
      scene = 3;
     }else if(random%5 == 3){
      d_count = 0;
      scene = 4;
      }else if(random%5 == 4){
      d_count = 0;
      scene = 5;
     }
    }
  }
}
