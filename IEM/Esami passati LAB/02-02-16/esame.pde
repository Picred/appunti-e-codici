PImage Im;
PImage ImG; //gray Image
PImage ImBP; //Bit plane Image
int N=8;
boolean saved;

void settings(){
  Im = loadImage("lena.png");
  size(Im.width*3,Im.height);
}

void setup(){
  ImG = imToGray(Im);
  
  image(Im,0,0);
  
  image(ImG,Im.width,0);
  saved = false;
}

void draw(){
  ImBP = estraiPianoN(ImG,N);
  image(ImBP,Im.width*2,0);
}

void keyPressed(){
  if(key=='1'){N=1;}
  if(key=='2'){N=2;}
  if(key=='3'){N=3;}
  if(key=='4'){N=4;}
  if(key=='5'){N=5;}
  if(key=='6'){N=6;}
  if(key=='7'){N=7;}
  if(key=='8'){N=8;}
  
  if(key=='s' && (!saved)){
    saved = true;
    salvaBitPlane(ImG);
  }
}


PImage imToGray(PImage I){
  PImage R = I.copy();
  
  R.loadPixels();
  
  for (int i=0; i<R.pixels.length; i++){
    float r = red(R.pixels[i]);
    float g = green(R.pixels[i]);
    float b = blue(R.pixels[i]);
    
    R.pixels[i] = color(0.5*r+0.2*g+0.3*b);
  }
  
  R.updatePixels();
  return R;
}


PImage estraiPianoN(PImage I,int n){
  PImage R = I.copy();
  R.filter(GRAY);
  
  R.loadPixels();
  int r;
  int v;
  for(int i=0; i<R.pixels.length; i++){
    r = int(red(R.pixels[i]));
    
    v = (r>>n-1)&1;
    
    R.pixels[i]=color(255*v);
  }
  
  
  R.updatePixels();
  return R;
}


void salvaBitPlane(PImage I){
  PImage toSave;
  for(int i=1; i<=8; i++){
    toSave = estraiPianoN(I,i);
    
    toSave.save("b"+i+".png");
  }
}
