class Warp{
  int x,y;
  color c;
  int angolo;
  int potenza;

  Warp(int x, int y, color c, int angolo, int potenza){
    this.x=x;
    this.y=y;
    this.c=c;
    this.angolo=angolo;
    this.potenza=potenza;
  }
  
  void display(){
    ellipseMode(RADIUS);
    fill(0);
    ellipse(x,y,35,35);
    
    fill(40);
    ellipse(x,y,30,30);
    
    fill(c);
    ellipse(x,y,25,25);
  }
  
  Bullet shot(){
    float sx = potenza*cos(radians(angolo));
    float sy = potenza*sin(radians(angolo));
    return new Bullet(x,y,sx,sy,this.c);
  }
  
  boolean checkMouse(){
    if(dist(x,y,mouseX,mouseY) < 25){
      return true;
    }
    else{
    return false;
    }
}
  
  void run(){
    display();
  }
}
