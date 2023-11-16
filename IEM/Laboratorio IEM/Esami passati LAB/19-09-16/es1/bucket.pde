class Bucket{
  float x,y;
  
  Bucket(float X, float Y){
    x=X;
    y=Y;
  }
  
  void display(){
    fill(#986800);
    beginShape();
      vertex(x,y);
      vertex(x+50,y);
      vertex(x+40,y-40);
      vertex(x+10,y-40);
    endShape(CLOSE);
  }
  
  void move(){
    x = mouseX;
  }
  
  boolean checkEgg(Egg e){
    if(dist(x+15,y-40, e.x, e.y) < 20){ 
      e.on = false;
      return true;
    }  
    return false;
  }
  
  void run(){
    move();
    display();
  }

}
