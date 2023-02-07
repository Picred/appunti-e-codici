class SuperPillow extends Pillow{
  int angle = round(random(0,360));
  
  SuperPillow(int x, int y, int w, int h){
    super(x,y,w,h);
  }
  
  void display(){
    pushMatrix();
    
      translate(x,y);
      rotate(radians(angle));
      
      fill(255);
      noStroke();
      rectMode(CENTER);
      rect(0,0,w,h);
      
      fill(100);
      ellipse(0,0,w,w);
      
    popMatrix();
  }
  
  void incAng(){
    if(dist(mouseX,mouseY,this.x,this.y) < w/2){
      angle+=5;
    }
  }
  
  void run(){
    this.incAng();
    checkMouse();
    move();
    this.display();
  }

}
