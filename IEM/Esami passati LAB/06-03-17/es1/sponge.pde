class Sponge{
  int x,y,L;
  color c = color(200,200,100);
  
  
  Sponge(int l){
    L=l;
  }
  
  
  void display(){
    noStroke();
    fill(c);
    rectMode(CENTER);
    rect(x,y,L,L);
  }
  
  
  void move(){
    x=mouseX;
    y=mouseY;
  }
  
  boolean absorb(Stain s){
    //verifico che stain è nel quadrato sponge
    
    if(dist(x,y,s.x,s.y) < L/2 ){
      L+=s.D/2;
      float r,g,b;
      r = (red(c) + red(s.c) )/2;
      g = (green(c) + green(s.c) )/2;
      b = (blue(c) + blue(s.c) )/2;
      
      this.c = color(r,g,b);
      
      return true;
    }
    
    return false;
  }
  
  
  void run(){
    move();
    display();
  }

  
}
