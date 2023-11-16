class Frog{
  float x,y,sx,sy;
  
  Frog(float X, float Y, float SX, float SY){
    x=X;
    y=Y;
    sx=SX;
    sy=SY;
  }
  
  void display(){
    noStroke();
    fill(255,0,0);
    ellipse(x-15, y-35,20,20);
    ellipse(x+15, y-35,20,20);

    fill(0,255,0);
    ellipse(x,y,50,70);    
  }
  
  void move(){
    if(x>width-25 || x<25)
      sx*=-1;
    
    if(y>height-35 || y<35)
      sy*=-1;

    x+=sx;
    y+=sy;
    sy+=0.2;
  }
  
  void checkmouse(){
    if(dist(x,y,mouseX,mouseY) < 30){
      sy=-7;
    }
  }
  
  void run(){
    move();
    checkmouse();
    display();
  }
}
