class Fish{
  int x, y, sx, sy; //spostamento x e spostamento y -> sx e sy
  color c;
  
  Fish(int X, int Y, int SX, int SY, color C){
    x=X;
    y=Y;
    sx=SX;
    sy=SY;
    c=C;
  }
  
  void display(){
    //pesce
    fill(c);
    ellipse(x,y,80,50);
    
    //coda a sinsitra
    beginShape();
      vertex(x-40,y);
      vertex(x-40-40,y-25);
      vertex(x-40-40,y+25);
    endShape(CLOSE);
    
    //occhio in alto a destra del pesce
    fill(0);
    ellipse(x+20,y-10,5,5);
    
  }
  
  
  void move(){
    if(sx>0){ //limito il movimento solo a destra
      x+=sx;
    }
    
    y+=sy;
  }
  
  Bubble generaBubble(){
    Bubble R = new Bubble(x+70,y,80/10, int(random(10,30)));
    return R;
  }
  
  void run(){
    move();
    display();
  }
}
