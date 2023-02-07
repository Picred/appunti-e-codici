class Bubble{
  int x,y,v,D; //velocità Diametro
  
  Bubble(int X, int Y, int V, int D){
    this.x=X;
    this.y=Y;
    this.v=V;
    this.D=D;
  }
  
  void display(){
    fill(99,20,255);
    ellipse(x,y,D,D);
    
    fill(255);
    ellipse(x-D/2+D/4, y-D/2+D/4, D/4, D/4);
  }
  
  void move(){
    y-=v; //movimento solo verticale dal basso verso l'alto
  }
  
  void run(){
    move();
    display();
  }
}  
