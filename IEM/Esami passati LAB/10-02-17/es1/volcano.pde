class Volcano{
  float x,y;
  
  
  Volcano(float X, float Y){
    x=X;
    y=Y;
  }
  
  void display(){
    fill(160,100,0);
    beginShape();
      vertex(x,y);
      vertex(x+100,y);
      vertex(x+60,y-60);
      vertex(x+40,y-60);
    endShape(CLOSE);
  }
  
  FireBall genera(){
    FireBall fb = new FireBall(x+50, y-60, (int)random(5,10), random(-2,2), random(-8,-2) );
    return fb;
  }
  
  void run(){
    display();
  }
}
