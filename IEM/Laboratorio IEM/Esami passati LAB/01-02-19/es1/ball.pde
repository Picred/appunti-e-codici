class Ball{
  int x, y, R, sy=5;
  
  
  Ball(int x, int y, int R){
    this.x=x;
    this.y=y;
    this.R=R;
  }
  
  
  void display(){
    fill(255,0,0);
    noStroke();
    ellipse(x, y, R*2, R*2);
  }
  
  
  void move(){
    y+=sy;
    if (y < 0 || y > height)
      sy*=-1;
  }
  
  
  void run(){
    move();
    display();
  }


}
