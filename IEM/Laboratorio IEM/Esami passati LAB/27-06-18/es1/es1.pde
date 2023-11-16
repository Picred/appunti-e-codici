ArrayList<Smoke> smokes;
ArrayList<Torpedo> torpedos;
void setup(){
  size(512,512);
  frameRate(60);  
  smokes = new ArrayList<Smoke>();
  torpedos = new ArrayList<Torpedo>();
}



void draw(){
  background(0,255,255);
 
  
  for(Torpedo t:torpedos){
    t.run();
    if(random(0,1)<0.5){
      smokes.add(t.generaSmoke());
      
    }
  }
  
  for(Smoke s:smokes){
    s.run();
  }  

  
  
}

void keyPressed(){
  if(key=='N')
    torpedos.add(new Torpedo(-50,random(50,450), random(5,10)));
}
