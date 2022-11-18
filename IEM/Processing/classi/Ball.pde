class Ball{
  float px, py, size, sx, sy; //px=posx py=posy sy=speed y
  
  Ball(float x, float y, float size, float sx, float sy){
  this.px=x;
  this.py=y;
  this.size=size;
  this.sx=sx;
  this.sy=sy;
  }
  
  
  Ball(float x, float y, float size){
    this(x,y,size,0,0); //0 0 valori di default  
  }


  void display(){ //disegna la figura
    fill(255,255,0);
    noStroke();
    ellipse(this.px, this.py, this.size, this.size);
  }
  
  
  void move(){
    px+=sx;
    py+=sy;
  }

  
  void bounce(){
    if(px<=size/2 || px>=width-size/2){
      sx=-sx;
    }
    if(py>height-this.size/2){
      sy=-sy;
    }
    
    if(py<this.size/2){ 
      sy=-sy;
      py=height-size/2;
    }
  }

  void gravity(){
    sy+=0.1;
  }

  
  void run(){
    this.gravity();
    this.move();
    this.bounce();
    this.display();
  }
}
