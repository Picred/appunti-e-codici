class Bullet{
  int x,y;
  
  Bullet(int _x, int _y){
    x=_x;
    y=_y;
  }
  
  void display(){
    fill(#B900A4);
    noStroke();
    ellipse(x,y,10,10);
  }
  
  void move(){
    y-=10;
  }
  
  void run(){
    move();
    display();
  }
}
