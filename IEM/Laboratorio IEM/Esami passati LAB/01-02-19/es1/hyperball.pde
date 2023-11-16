class HyperBall extends Ball{
  color c = color(0,0,255);


  HyperBall(int x, int y, int R){
    super(x,y,R);
  }


  void checkMouse(){
    if(dist(mouseX, mouseY, x, y) < R)
      c = color( random(255), random(255), random(255));
  }


  void display(){
    fill(c);
    noStroke();
    ellipse(x, y, R*2, R*2);
  }


  void move(){
    y+=sy;
    if (y < 0 || y > height)
      sy*=-1;
  }


  void run(){
    checkMouse();
    move();
    display();
  }


}
