class Heart{
  int x,y;
  float sx,sy;
  boolean alive = true;
  
  Heart(int X, int Y, float SX, float SY){
    x=X;
    y=Y;
    sx=SX;
    sy=SY;
  }
  
  Heart(){
    this(int(random(0,width)),height+30,random(-5,5),-random(3,7));
  }
  
  void display(){
    if(!alive)
      fill(150);
    else
      fill(255,50,50);
      
      noStroke();
      
      bezier(x-30,y,x-30,y-30,x,y-30,x,y);
      bezier(x,y,x,y-30,x+30,y-30,x+30,y);  
      
      beginShape();
        vertex(x-30,y);
        vertex(x+30,y);
        vertex(x,y+30);
      endShape(CLOSE);
  }
  
/* Il valore di q=43191 è uguale alle ultime 5 cifre del
numero di matricola. (quindi è semi casuale)
*/

  void move(){
    x+=sx;
    
    if(!alive){
      sy+=0.1+(34390%21)/80.0;
    }
    y+=sy;
  }
  
  void checkMouse(){
    if(dist(x,y,mouseX,mouseY) < 30){
      alive=!alive;
    }
    
  }
  
  
  
  void run(){
    this.move();    
    this.display();
  }
}
