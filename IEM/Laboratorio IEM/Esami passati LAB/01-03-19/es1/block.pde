class Block{
  int x, y, w, h, sx=4;
  
  Block(int x, int y,int w,int h){
    this.x=x;
    this.y=y;
    this.w=w;
    this.h=h;
  }
  
  void display(){
    fill(0,255,0);
    noStroke();
    rect(x,y,w,h);
  }
  
  
  void move(){
    if(x+sx>width || x+w/2<0)
      sx*=-1;

    x+=sx;
  }
  
  
  void run(){
    move();
    display();
  }
  
}
