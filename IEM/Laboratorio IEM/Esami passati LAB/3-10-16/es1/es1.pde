ArrayList<Bubble> bubbles;
ArrayList<Fish> fishes;


void setup(){
  size(500,500);
  frameRate(60);
  bubbles = new ArrayList<Bubble>();
  fishes = new ArrayList<Fish>();
}


void draw(){
  
  background(0,127,255);
  for(Bubble b:bubbles){
    b.run();
  }
  
  for(Fish f:fishes){
    f.run();
    
    if(random(0,1) < 0.02){
      bubbles.add(f.generaBubble());
    }
  }

}

void keyPressed(){
  if (key=='N'){
    fishes.add(new Fish(-50,int(random(50,450)),int(random(1,4)),int(random(-1.5,1.5)),color(random(0,255), random(0,255), random(0,255)) ));
  }
}
