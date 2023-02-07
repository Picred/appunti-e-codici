class Spear{
  float x,y,sy;
  
  Spear(float X, float Y, float SY){
    x=X;
    y=Y;
    sy=SY;
  }
  
  void display(){
    fill(4,200,200);
    noStroke();
    beginShape();
      vertex(x,y);
      vertex(x+100,y);
      vertex(x+50,y+50);
    endShape(CLOSE);
  }
  
  void move(){
    y+=sy;
  }
  
  void run(){
    move();
    display();
  }
  
}
