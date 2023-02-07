class Torpedo{
  float x,y,sx;
  
  Torpedo(float x, float y, float sx){
    this.x=x;
    this.y=y;
    this.sx=sx;
  }
  
  void display(){
    fill(180,50,50);
    rect(x,y,100,20);
    
    ellipse(x+100,y+10,20,20);
  }
  
  void move(){
    if(sx>=0)
      x+=sx;
  }
  
  Smoke generaSmoke(){
    float d = random(10,30);
    return new Smoke(x-10,y+10, -d/5, (int)d, color(random(50,200)));
  }
  
  void run(){
    move();
    display();
  }
  
}
