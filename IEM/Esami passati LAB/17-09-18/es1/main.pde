PImage Im;
int N=101;

void setup(){
  size(512,512);
  Im=loadImage("lena.png");
  
}



void draw(){
  image(Im,0,0);
  
  noFill();
  rectMode(CENTER);
  rect(mouseX,mouseY,N,N);
}

void mousePressed(){
  if(mouseButton==RIGHT){
    Im=applyArea(Im,mouseX,mouseY,N,false);
  }
  if(mouseButton==LEFT){
    Im=applyArea(Im,mouseX,mouseY,N,true);
  }
}

void keyPressed(){
  if(key=='+' && (N<149)){
    N+=2;
  }
  
  if(key=='-' && (N>53)){
    N-=2;
  }
  
  if(key=='r' || key == 'R'){
    setup();
  }
}
