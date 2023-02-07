PImage Im;
int K;
int mode;
void setup(){
  Im = loadImage("lena.png");
  size(512,512);
  K=75;
  mode = 1;
}


void draw(){
  image(Im,0,0);
  noFill();
  stroke(0,255,0);
  rectMode(CENTER);
  rect(mouseX,mouseY,K,K);
}

void mousePressed(){
  Im = applyOperator(Im,mouseX,mouseY,K,mode);
}

void keyPressed(){
  if(key=='+' && K<511)
    K+=2;
  if(key=='-' && K>3)
    K-=2;
    
  if(key=='1')
    mode=1;
  if(key=='2')
    mode=2;
}




PImage gamma(PImage I, float gm){
  PImage R = I.copy();
  
  R.loadPixels();
  I.loadPixels();
  float r,g,b;
   float C=1/pow(255,gm-1);
    for(int i=0; i<R.pixels.length; i++){
       r=C*pow(red(I.pixels[i]),gm);
       g=C*pow(green(I.pixels[i]),gm);
       b=C*pow(blue(I.pixels[i]),gm); 
       R.pixels[i]=color(r,g,b);
    }
  
  R.updatePixels();
  return R;
}

PImage logaritmo(PImage I){
  PImage R=createImage(I.width,I.height,RGB);
  float r,g,b;
  float C=255/log(256);
  
  R.loadPixels();
  I.loadPixels();
  
  for(int i=0; i<R.pixels.length; i++){
    r=C*log(1+red(I.pixels[i]));
    g=C*log(1+green(I.pixels[i]));
    b=C*log(1+blue(I.pixels[i]));
    
    R.pixels[i]=color(r,g,b);
  }
  R.updatePixels();
  return R;
}


PImage applyOperator(PImage I, int x, int y, int n, int s){
  PImage R = I.copy();
  PImage window = I.get(x-n/2, y-n/2, n,n);
  
  if(s==1){
    window = logaritmo(window);
  }
  
  if(s==2){
    window = gamma(window,2);
  }
  
  R.set(x-n/2, y-n/2,window);
  
  return R;
  
}
