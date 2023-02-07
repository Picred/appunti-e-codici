ArrayList<Heart> hearts = new ArrayList<Heart>();

void setup(){
  size(512,512);
  frameRate(60);
}


void draw(){
  fill(0,0,50,40);
  rect(0,0,width,height);
  
  
  if(random(0,1)<0.05){
    hearts.add(new Heart());
  }
  
  for(Heart h:hearts){
    h.run();
    if(mousePressed && h.alive){
      h.checkMouse();
    }
  }
}
