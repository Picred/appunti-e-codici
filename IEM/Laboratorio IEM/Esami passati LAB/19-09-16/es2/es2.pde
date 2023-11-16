PImage Im;
char stato;

void setup(){
  size(512,512);
  Im = loadImage("lena.png");
  Im.resize(256,256);
  stato = 'r';
  
}

void draw(){
  image(Im,0,0);
  image(channel(Im,'r'), Im.width,0);
  image(channel(Im,'g'),0, Im.height);
  image(channel(Im,'b'), Im.width,Im.height);

}


void keyPressed(){
  if(key=='g')
    stato='g';
    
  if(key=='r')
    stato='r';
    
  if(key=='b')
    stato='b';
    
  if(key=='+')
    Im = changeColor(Im,stato,3);

  if(key=='-')
    Im = changeColor(Im,stato,-3);
}


PImage channel(PImage I, char c){
  PImage R = I.copy();
  
  R.loadPixels();
  float r,g,b;

  for(int i=0; i<R.pixels.length; i++){
    r=red(R.pixels[i]);
    g=green(R.pixels[i]);
    b=blue(R.pixels[i]);
    switch(c){
      case 'r':
        R.pixels[i] = color(r,r,r);
        break;
      case 'g':
        R.pixels[i] = color(g,g,g);
        break;
      case 'b':
        R.pixels[i] = color(b,b,b);
        break;
    }
  }
  
  R.updatePixels();
  
  return R;
}


PImage changeColor(PImage I, char c, int n){
  PImage R = I.copy();
  
  R.loadPixels();
  float r,g,b;

  for(int i=0; i<R.pixels.length; i++){
    r=red(R.pixels[i]);
    g=green(R.pixels[i]);
    b=blue(R.pixels[i]);
    switch(c){
      case 'r':
        R.pixels[i] = color(r+n,g,b);
        break;
      case 'g':
        R.pixels[i] = color(r,g+n,b);
        break;
      case 'b':
        R.pixels[i] = color(r,g,b+n);
        break;
    }
  }
  
  R.updatePixels();

  return R;
}
