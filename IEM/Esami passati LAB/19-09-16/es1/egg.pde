class Egg{
  float x, y, sy;
  boolean on = true;
  
  Egg(float X, float Y, float SY){
    x=X;
    y=Y;
    sy=SY;
  } 
  
  void move(){
    y+=sy;
  }
  
  void display(){
    noStroke();
    fill(255);
    ellipse(x,y,30,40);
  }
  
  void run(){
    if(on){
      move();
      display();
    }
  }
}
