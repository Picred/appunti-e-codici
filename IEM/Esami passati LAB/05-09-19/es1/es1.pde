Pillow cuscino;
Pillow supercuscino;

void setup(){
  size(256,512);
  cuscino = new Pillow(int(random(width)), int(random(height/2)), 40, 80);
  supercuscino = new SuperPillow(int(random(width)), int(random(height/2,height)), 40, 80);
}




void draw(){
  background(0);
  cuscino.run();
  supercuscino.run();
}

void keyPressed(){
  if(key=='r' || key=='R'){
    setup();
  }
}
