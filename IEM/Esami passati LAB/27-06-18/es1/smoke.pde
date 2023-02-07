class Smoke{
  float x,y,sy;
  int D;
  color c;
  
  Smoke(float x, float y, float sy, int d, color c){
    this.x=x;
    this.y=y;
    this.sy=sy;
    this.D=d;
    this.c=c;
  }
  
  
  void display(){
    fill(c);
    ellipse(x,y,D,D);
  }
  
  void move(){
    y+=sy;
  }
  
  void run(){
    move();
    display();
  }
}
