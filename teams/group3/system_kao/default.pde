void default1(){
    
  if(count>300){
      no();
      count = 0;
      random = (int)random(0,255);
      if(random%5 == 0){
        count = 0;
        scene = 1;
      }else if(random%5 == 1){
        count = 0;
        scene = 2;
     }else if(random%5 == 2){
      count = 0;
      scene = 3;
     }else if(random%5 == 3){
      count = 0;
      scene = 4;
      }else if(random%5 == 4){
      count = 0;
      scene = 0;
     }
    }
  else if(scene == 1){
    egao();
    if(count>300){
      no();
      random = (int)random(0,255);
      if(random%5 == 0){
        count = 0;
        scene = 2;
      }else if(random%5 == 1){
        count = 0;
        scene = 2;
     }else if(random%5 == 2){
      count = 0;
      scene = 3;
     }else if(random%5 == 3){
      count = 0;
      scene = 4;
      }else if(random%5 == 4){
      count = 0;
      scene = 0;
     }
   }
  }else if(scene == 2){
    mu2();
    if(count>300){
      no();
      random = (int)random(0,255);
      if(random%5 == 0){
        count = 0;
        scene = 1;
      }else if(random%5 == 1){
        count = 0;
        scene = 3;
     }else if(random%5 == 2){
      count = 0;
      scene = 3;
     }else if(random%5 == 3){
      count = 0;
      scene = 4;
      }else if(random%5 == 4){
      count = 0;
      scene = 0;
     }
    }
  }else if(scene == 3){
    egao2();
    if(count>300){
      no();
      random = (int)random(0,255);
      if(random%5 == 0){
        count = 0;
        scene = 1;
      }else if(random%5 == 1){
        count = 0;
        scene = 2;
     }else if(random%5 == 2){
      count = 0;
      scene = 1;
     }else if(random%5 == 3){
      count = 0;
      scene = 4;
      }else if(random%5 == 4){
      count = 0;
      scene = 0;
     }
    }
  }else if(scene == 4){
    ok();
    if(count>300){
      no();
      count = 0;
      random = (int)random(0,255);
      if(random%5 == 0){
        count = 0;
        scene = 1;
      }else if(random%5 == 1){
        count = 0;
        scene = 2;
     }else if(random%5 == 2){
      count = 0;
      scene = 3;
     }else if(random%5 == 3){
      count = 0;
      scene = 0;
      }else if(random%5 == 4){
      count = 0;
      scene = 0;
     }
    }
  }
}
