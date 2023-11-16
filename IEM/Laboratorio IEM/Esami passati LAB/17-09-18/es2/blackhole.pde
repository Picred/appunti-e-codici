class BlackHole{
  int x,y,D=50;
  
  BlackHole(int x, int y){
    this.x=x;
    this.y=y;
  }
  
  void display(){
    noStroke();
    fill(0);
    ellipse(x,y,D,D);
  }
  
  void move(){
    x=mouseX;
    y=mouseY;
  }
  
  void check(ArrayList<Asteroid> A){
    for(int i=0; i<A.size(); i++){
      if(dist(A.get(i).x,A.get(i).y,x,y) < D/2){
        A.remove(A.get(i));
        D++;
      }
    }
  }

  void run(ArrayList<Asteroid> A){
    check(A);
    move();
    display();
  }

}
