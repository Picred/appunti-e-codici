class GreenBall extends Ball{
  
  GreenBall(float x, float y, float s, float sx, float sy){
    super(x,y,s,sx,sy); //chiamo costruttore madre
  }
  
  GreenBall(float x, float y, float size){
    super(x,y,size);
  }
  
  void display(){
    fill(0,255,0);
    stroke(128,0,255);
    strokeWeight(5);
    ellipse(px,py,size,size);
  }
  
}
