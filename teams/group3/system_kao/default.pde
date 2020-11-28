
void default1(){
  int time=0;
  
  /*if(scene == 0){
    no();
  }else if(scene == 1){
    no();
    mu();
  }else if(scene == 2){
    no();
    mu2();
  }else if(scene == 3){
    no();
    egao();
  }else if(scene == 4){
    no();
    egao2();
  }*/
  
  
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
    no();
    mu();
    time++;
    if(time==600){
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
    no();
    mu2();
    if(time==600){
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
    no();
    egao();
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

      no();
      egao2();
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
