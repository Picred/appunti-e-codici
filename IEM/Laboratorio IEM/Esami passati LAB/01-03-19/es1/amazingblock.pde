class AmazingBlock extends Block{
  int angle = int(random(360));
  
  AmazingBlock(int x, int y,int w,int h){
    super(x,y,w,h);
  }
  
  void display(){
    fill(angle%256,255-angle%256,255);
    noStroke();
    rectMode(CENTER);
    pushMatrix();
      translate(x,y);
      rotate(radians(angle));
      rect(0,0,w,h);
    popMatrix();
    
    angle+=5;
  }
  
  void run(){
    super.move();
    this.display();
  }
  
}
