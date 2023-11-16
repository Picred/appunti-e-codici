class Baloon{
  float x,y;
  
  Baloon(float X, float Y){
    x=X;
    y=Y;
  }

  void display(){
    noStroke();
    fill(255,0,0);
    ellipse(x,y,50,50);
  }
  
  
  void move(double e){
    x+=e;
  }
  
  boolean checkRange(float a, float b){
    
    if(x-25 < a || x+25 > b)
      return true;
    else
      return false;
  }
  
  
  boolean checkCollision(Spear s){
     if(dist(s.x+50, s.y+50, x, y) < 25)
       return true;
     
     return false;
  }
  
  
  void run(double e){
    move(e);
    display();
  }
}
