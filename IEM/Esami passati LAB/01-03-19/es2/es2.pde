PImage Im;

void setup(){
  size(768,256);
  Im = loadImage("lena.png");
  Im.filter(GRAY);
  Im.resize(256,256);
  
  image(Im,0,0);
  
  image(logOp(Im), Im.width,0);
  
  image(logOp(Im), Im.width,0);
  image(logOp(Im, int(random(10,70)), int(random(10,70))), Im.width*2,0);

}


void draw(){}


void keyPressed(){
  if(key=='R' || key=='r'){
    setup();
  }
}


PImage logOp(PImage I){
  float c=255/log(256);

  //R(x,y) = c log(1+I(x,y));
  PImage R = createImage(I.width,I.height,RGB);
  
  I.loadPixels();
  R.loadPixels();
  
  for(int i=0; i<I.pixels.length; i++){
    float u = red(I.pixels[i]);
    float v = c*log(1+u);
    R.pixels[i] = color(v);
  }
  
  R.updatePixels();
  
  return R;
}



PImage logOp (PImage I, int h, int k){
  PImage R = I.copy();
  PImage tmp = createImage(h,k,RGB);
  
  int x = int(random(I.width-h));
  int y = int(random(I.width-k));
  tmp = R.get(x, y, h, k);
  
  tmp.loadPixels();
  for(int i=0; i<tmp.pixels.length; i++){
    tmp.pixels[i] = color(0);
  }
  
  tmp.updatePixels();
  R.set(x-h, y-k, tmp);
  
  R = logOp(R);
  
  return R;
}
