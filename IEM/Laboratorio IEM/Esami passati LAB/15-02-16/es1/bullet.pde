class Bullet{
  int x,y; //posizione bullet
  float sx,sy; //velocita in x e y
  color c;
  
  Bullet(int X, int Y, float SX, float SY, color C){
    this.x=X;
    this.y=Y;
    this.sx=SX;
    this.sy=SY;
    this.c=C;
  }
  

  void display(){
    noStroke();
    fill(c);
    ellipse(x,y,10,10);
  }
  
  void move(){
    x+=sx;
    y+=sy;
  }
  
  
  void run(){
    move();
    display();
  }
}
