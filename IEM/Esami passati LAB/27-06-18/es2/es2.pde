PImage Im1, Im2;
float K;
void setup(){
  size(512,512);
  K = 0.5;
  
  Im1 = loadImage("lena.png");
  Im2 = loadImage("baboon.jpg");
  
  Im1.resize(256,256);
  Im2.resize(256,256);
  
  image(Im1,0,0);
  image(Im2,0,Im1.height);
  

}


void draw(){
  image(fusion(Im1,Im2,K),Im1.width,0);
  image(subtract(Im1,Im2,K),Im1.width,Im1.height);
}


void keyPressed(){
  if(key=='+' && K < 1)
    K+=0.05;
    
  if(key=='-' && K > 0)
    K-=0.05;
}



PImage fusion(PImage I, PImage Q, float k){
  PImage R = createImage(I.width,I.height,RGB);
  
  R.loadPixels();
  I.loadPixels();
  Q.loadPixels();
  
  float r1,g1,b1,r2,g2,b2;
  
  for(int i=0; i<R.pixels.length; i++){
    r1 = red(I.pixels[i]);
    g1 = green(I.pixels[i]);
    b1 = blue(I.pixels[i]);
    
    r2 = red(Q.pixels[i]);
    g2 = green(Q.pixels[i]);
    b2 = blue(Q.pixels[i]);
    
    R.pixels[i] = color((k*r1)+((1-k)*r2), (k*g1)+((1-k)*g2), (k*b1)+((1-k)*b2));
  }
  
  R.updatePixels();  
  return R;
  
}



PImage subtract(PImage I, PImage Q, float k){
  PImage R = createImage(I.width,I.height,RGB);
  
  R.loadPixels();
  I.loadPixels();
  Q.loadPixels();
  
  float r1,g1,b1,r2,g2,b2;
  
  for(int i=0; i<R.pixels.length; i++){
    r1 = red(I.pixels[i]);
    g1 = green(I.pixels[i]);
    b1 = blue(I.pixels[i]);
    
    r2 = red(Q.pixels[i]);
    g2 = green(Q.pixels[i]);
    b2 = blue(Q.pixels[i]);
    
    R.pixels[i] = color(r1-(k*r2), g1-(k*g2), b1-(k*b2));
  }
  
  R.updatePixels();  
  return R;
}
