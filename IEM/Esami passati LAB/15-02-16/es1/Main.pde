int K=10;
Warp[] warps = new Warp[K];
ArrayList<Bullet> bullets = new ArrayList<Bullet>();
void setup(){
  size(600,600);
  
  for(int i=0; i<K; i++){
    color c = color(random(0,255),random(0,255),random(0,255));
    warps[i]= new Warp(int(random(50,550)), int(random(50,550)), c, int(random(0,360)), int(random(1,10)));
  }
  
}

void draw(){
    background(255);
    for(int i=0; i<K; i++){
      warps[i].run();
    }
    
    for(Bullet b:bullets){
      b.run();
    }
    
}

void mousePressed(){
  
  for(int i=0; i<K; i++){
    if(warps[i].checkMouse()){
      bullets.add(warps[i].shot());
    }
  }
}
