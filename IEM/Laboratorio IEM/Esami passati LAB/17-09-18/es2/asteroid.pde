class Asteroid{
  int x,y,H;
  
  Asteroid(int x,int y, int h){
    this.x=x;
    this.y=y;
    H=h;
  }
  
  Asteroid(){
    this(0,0,int(random(5,25)));
  }
  
  void display(){
    fill(178,92,5);
    noStroke();
    ellipse(x,y,H,H);
  }
  
  void move(BlackHole B){
    float S = dist(this.x,this.y,B.x,B.y);
    
    //componenti versore
    float sx = -(this.x-B.x)/S;
    float sy = -(this.y-B.y)/S;
    
    sx*=3;
    sy*=3;
    
    x+=sx;
    y+=sy;
  }
  
  void run(BlackHole B){
    move(B);
    display();
  }
  
}
