PImage Im;
int S = 80;
int x,y;
boolean firstTime = true;

void setup(){
  size(512,512);
  background(0);
  
  Im=loadImage("lena.png");
  
  image(Im,0,0);
}


void draw(){
  //modifiche cumulative
  
  if(!firstTime){
    image(Im,0,0);
    noFill();
    noStroke();
    fill(0,0,200,40);
    rect(x,y,S,S);
    noFill();
    stroke(0);
    rectMode(CENTER);
    rect(mouseX,mouseY,S,S);
    
  }
  else{
    image(Im,0,0);
    noFill();
    stroke(0);
    rectMode(CENTER);
    rect(mouseX,mouseY,S,S);
    
  }
  
  
}


void mousePressed(){
  if(firstTime){
    
    x = mouseX;
    y = mouseY;    
    firstTime=false;
    
    if(x-S/2 < 0)
      x+= S/2;

    if(y-S/2 < 0)
      y+= S/2;
      
    if(x+S/2 > width)
      x-= S/2;

    if(y+S/2 > height)
      y-= S/2;

  }
  else{
    
    Im = swap(Im,x,y,mouseX,mouseY,S);
    firstTime=true;
  }
}


void keyPressed(){
  if (key=='+' && S<150 && firstTime)
    S+=10;

  if (key=='-' && S>30 && firstTime)
    S-=10;
}


PImage swap(PImage I, int x1, int y1, int x2, int y2, int s){
  PImage R = I.copy();

  PImage tmp1 = I.get(x1-s/2, y1-s/2,s,s);
  PImage tmp2 = I.get(x2-s/2, y2-s/2,s,s);
  
  R.set(x2-s/2, y2-s/2, tmp1);
  R.set(x1-s/2, y1-s/2, tmp2);

  return R;
}
