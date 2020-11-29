//顔

void no(){
  background(0);
}



void mu(){//モータ制御用変数port.write(1)
    
    fill(#006400);
    ellipse(width/4,height/3,width*1/10,width*1/10);
    ellipse(width*3/4,height/3,width*1/10,width*1/10);
    rect(width*375/1000,height*6/10,width*2/10+10,height*1/20);//無表情
}

void mu2(){//モータ制御用変数port.write(2)
    
    fill(#006400);
    ellipse(width/4,height/3,width*1/10,width*1/10);
    ellipse(width*3/4,height/3,width*1/10,width*1/10);
    rect(150,150,100,20);//無表情
}

void egao(){//モータ制御用変数port.write(3)
    
    fill(#006400);
    ellipse(width*375/1000,height*75/100,20,20);
    ellipse(width*250/1000,75,20,20);
    arc(width/2, height*150/1000, 130, 130, radians(0), radians(180)); //口笑顔
}

void egao2(){//モータ制御用変数port.write(4)
    
    fill(#006400);
    arc(150, 75, 50, 50, radians(180), radians(360));
    arc(width-150, 75, 50, 50, radians(180), radians(360));
    arc(width/2, 150, 130, 130, radians(0), radians(180)); 
    fill(0,0,0);
    arc(150, 75, 30, 30, radians(180), radians(360));
    arc(width-150, 75, 30, 30, radians(180), radians(360));
    
}

void ok(){//モータ制御用変数port.write(5)
    no();
    fill(#006400);
    textSize(75);
    text("OK!",width/3,height/2);
}

void good(){
    no();
    fill(#006400);
    textSize(75);
    text("good!",width/3,height/2);
}
