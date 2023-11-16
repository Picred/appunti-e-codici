class FireBall{
  float x,y,sx,sy;
  int D;
  
  FireBall(float X, float Y, int d, float SX, float SY){
    x=X;
    y=Y;
    D=d;
    sx=SX;
    sy=SY;
  }
  
  void display(){
    fill(150,0,0);
    noStroke();
    ellipse(x,y,D,D);
  }
  
  void move(){
    x+=sx;
    y+=sy;
  }
  
  void editSY(){
    sy+=0.1;
  }
  
  void run(){
    move();
    display();
  }
}
