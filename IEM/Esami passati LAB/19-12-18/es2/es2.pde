int fps;
ArrayList<Frog> frogs;
void setup(){
  frogs = new ArrayList<Frog>();
  size(512,512);
  fps = 60;
  
}


void draw(){
  background(255);
  frameRate(fps);
  for(Frog f:frogs)
    f.run();

}

void keyPressed(){
  if(key=='F')
    frogs.add(new Frog(random(50,450), random(50,450), random(-3,3), random(-3,3)));

  if(key=='+' && fps<300)
    fps++;
  
  if(key=='-' && fps>5)
    fps--;

  if(key=='R')
    setup();
}
