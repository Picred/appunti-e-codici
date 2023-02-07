class Asteroid{
  float x, y, sx, sy;
  boolean stato = true; //true = è on
  
  Asteroid(float x, float y, float sx, float sy){
    this.x=x;
    this.y=y;
    this.sx=sx;
    this.sy=sy;
  }
  
  void display(){
    strokeWeight(5);
    stroke(255,255,0);
    if(stato)
      fill(180,0,0);
    else
      fill(150);
    ellipse(x,y,50,50);
  }
  
  void move(){
    x+=sx;
    y+=sy;
    if(stato == false)
      sy+=0.2;
  }
  
  void colpito(Bullet b){
    if(dist(b.x,b.y,x,y) < 25){
      if(stato)
        stato = false;
    }
  }
  
  void run(){
    move();
    display();
  }
}
