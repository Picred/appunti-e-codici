PImage Im, center, right;

void setup(){
  size(768,256);
  Im = loadImage("lena.png");
  Im.resize(256,256);
  
  image(Im,0,0);
  
  center = sBlock(Im, round(random(10,80)));
  image(center, Im.width,0);
  
  right = sBlock(Im, round(random(10,80)), random(0.5, 1.5) );
  image(right, 2*Im.width,0);
  
}


void draw(){}


void keyPressed(){
  if(key=='r' || key == 'R'){
    setup();
  }
}


PImage sBlock(PImage I, int h){
  PImage R = I.copy();
  int x = int(random(I.width));
  int y = int(random(I.height));
  
  PImage window = I.get(x, y, h, h);
  
  window.loadPixels();
  for(int i=0; i<window.pixels.length; i++){
    window.pixels[i] = color(100,100,255);
  }
  
  window.updatePixels();
  R.set(x,y,window);
  
  //secondo quadrato
  x = int(random(I.width));
  y = int(random(I.height));
  
  window = I.get(x, y, h, h);
  
  window.loadPixels();
  for(int i=0; i<window.pixels.length; i++){
    window.pixels[i] = color(100,100,255);
  }
  
  window.updatePixels();
  R.set(x,y,window);
  // fine secondo quadrato
  
  return R;
}


PImage sBlock(PImage I, int h, float s){
  PImage Q = sBlock(I,h);
  
  PImage R = createImage(Q.width, Q.height, RGB);
  
  R.loadPixels();
  for(int i=0; i<R.pixels.length; i++){
    R.pixels[i] = color(0);
  }
  R.updatePixels();

  float x,y;
  float u1,v1;
  for(int u=0; u<Q.width; u++){
    for(int v=0; v<Q.height; v++){
      
      //traslo e riporto l'origine (traslato) nel punto d'origine (0,0)
      u1 = u-Q.width/2;
      v1=v-Q.height/2;
      
      x=u1*s;
      y=v1*s;
      
      //riporto l'origine in modo "traslato" come era prima
      x+=Q.width/2;
      y+=Q.height/2;
      
      R.set(int(x), int(y), Q.get(u,v));
    }
  }  

  return R;
}
