Baloon b;
double energy;
ArrayList<Spear> spears;
float yRect;

void setup(){
  size(512,512);
  frameRate(60);
  energy = 0;
  spears = new ArrayList<Spear>();
  yRect =height- (height * 5 / 100);
  
  b = new Baloon(width/2, yRect);
  loop();
}
  


void draw(){
    background(0,255,255);
  fill(255);
  rect(0,yRect,width,yRect);

  b.run(energy);
  
  for(Spear s:spears){
    s.run();
    if(b.checkCollision(s))
      noLoop();
  }
  
  if(b.checkRange(0,width)){
    energy*=-1;
  }
  
  if(random(0,1)<0.1)
    spears.add(new Spear(random(12,500),-60, random(3,8)));
}

void keyPressed(){
  if(key=='R')
    setup();
    
  if(key=='A' && energy>-3)  
    energy-=0.2;

  if(key=='D' && energy<3)  
    energy+=0.2;
    
  if(energy > 0)
    energy-=0.05;  
    
  if(energy < 0)
    energy+=0.05;
}
