Block block, block2;

void setup(){
  size(256,512);
  block=new Block((int)random(width),(int)random(height/2-60),40,60);
  block2=new AmazingBlock((int)random(width),(int)random(height/2+60,height-60),40,60);
}

void draw(){
  background(0);
  block.run();
  block2.run();
 
 stroke(0);
 line(0,height/2,width,height/2);
}

void keyPressed(){
  if((key=='r')||(key=='R'))
    setup();
}
