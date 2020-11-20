import processing.serial.*;

Serial port;

int scene = 0;

void setup(){
  size(400,250);
  port = new Serial(this, "/dev/cu.usbmodem14201",9600);
}



void draw(){
  background(0);
  if(scene == 0){
    mu();
  }else if(scene == 1){
    egao();
  }
}

void mu(){
    fill(#006400);
    ellipse(150,75,20,20);
    ellipse(width-150,75,20,20);
    rect(150,150,100,20);//無表情
}

void egao(){
    fill(#006400);
    ellipse(150,75,20,20);
    ellipse(width-150,75,20,20);
    arc(width/2, 150, 130, 130, radians(0), radians(180)); //口笑顔
}

void mousePressed(){
  if(scene == 0){
    scene = 1;
    port.write("1");
  }else if(scene == 1){
    scene = 0;
    port.write("0");
  }
}
