class Pillow{
  int x, y, w, h, sx=2;

  
  Pillow(int x, int y, int w, int h){
    this.x=x;
    this.y=y;
    this.w=w;
    this.h=h;
  }
  
  void display(){
    fill(255);
    noStroke();
    rectMode(CENTER);
    rect(x,y,w,h);
  }
  
  void move(){
    x+=sx;
  }
  
  void checkMouse(){
    if(x <= 0 || x >= width){
      sx*=-1;
    }
  }
  
  void run(){
    checkMouse();
    move();
    display();
  }
  
}
