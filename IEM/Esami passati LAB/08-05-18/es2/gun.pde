class Gun{
  int x, y;
  
  Gun(int x, int y){
    this.x=x;
    this.y=y;
  }
  
  void display(){
    fill(180);
    rectMode(CENTER);
    rect(x,y,20,70);
  }
  
  void move(){
    x=mouseX;
  }
  
  Bullet shot(){
    return new Bullet(x-10,y-60);
  }
  
  void run(){
    move();
    display();
  }
  
}
