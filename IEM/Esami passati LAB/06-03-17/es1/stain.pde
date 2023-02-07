class Stain{
  int x,y,D;
  color c;
  
  
  Stain(int X, int Y, int d, color C){
    x=X;
    y=Y;
    D=d;
    c=C;
  }
  
  void display(){
    noStroke();
    fill(c);
    ellipse(x,y,D,D);
  }
  
  void move(){
    int sy = int(random(4));
    int sx = int(random(-1,1));
    
    x+=sx;
    y+=sy;
  }
  
  void run(){
    move();
    display();
  }
  
  void delete(){
    x-=width*2;
    y = height;
  }
  
}
