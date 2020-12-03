
void no(){
  background(0);
}



void mu(){//モータ制御用変数port.write(1)
    port.write(20);
    fill(#006400);
    ellipse(width/4,height/3,width*1/10,width*1/10);
    ellipse(width*3/4,height/3,width*1/10,width*1/10);
    rect(width*375/1000,height*6/10,width*2/10+10,height*1/20);//無表情
}

void mu2(){//モータ制御用変数port.write(2)
    port.write(22);
    fill(#006400);
    ellipse(width/4,height/3,width*1/10,width*1/10);
    ellipse(width*3/4,height/3,width*1/10,width*1/10);
    rect(width*350/1000,height*550/1000,width*300/1000,height*10/100);//無表情
}

void egao(){//モータ制御用変数port.write(3)
    port.write(21);
    fill(#006400);
    ellipse(width/4,height/3,width*1/10,width*1/10);
    ellipse(width*3/4,height/3,width*1/10,width*1/10);
    arc(width/2, height*150/250, width*130/400, height*130/250, radians(0), radians(180));
}

void egao2(){//モータ制御用変数port.write(4)
    port.write(23);
    fill(#006400);
    arc(width*150/400, height*75/250, width*50/400, height*50/250, radians(180), radians(360));
    arc(width-width*150/400, height*75/250, width*50/400, height*50/250, radians(180), radians(360));
    arc(width/2, height*150/250, width*130/400, height*130/250, radians(0), radians(180)); 
    fill(0,0,0);
    arc(width*150/400, height*75/250, width*30/400, height*30/250, radians(180), radians(360));
    arc(width-width*150/400, height*75/250, width*30/400, height*30/250, radians(180), radians(360));
    
}

void ok(){//モータ制御用変数port.write(5)
    no();
    fill(#006400);
    textSize(75);
    text("OK!",width/3,height/2);
}

void good(){
    no();
    fill(255,0,0);
    arc(width*150/400, height*75/250, width*50/400, height*50/250, radians(180), radians(360));
    arc(width-width*150/400, height*75/250, width*50/400, height*50/250, radians(180), radians(360));
    arc(width/2, height*150/250, width*130/400, height*130/250, radians(0), radians(180)); 
    fill(0,0,0);
    arc(width*150/400, height*75/250, width*30/400, height*30/250, radians(180), radians(360));
    arc(width-width*150/400, height*75/250, width*30/400, height*30/250, radians(180), radians(360));
}
