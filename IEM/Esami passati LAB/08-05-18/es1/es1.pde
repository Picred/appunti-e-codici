PImage Im;
int K = 10*2+1;
color c;

void setup(){
  size(1024,512);
  Im = loadImage("lena.png");
}

void draw(){
  image(Im,0,0);
  
  noFill();
  stroke(0,255,0);
  rectMode(CENTER);
  
  if(mouseX < Im.width-K/2 && mouseX > K/2 && mouseY < Im.height-K/2 && mouseY > K/2){
    c = regionMean(Im, mouseX, mouseY, K);
    Im.filter(c);
    
    rect(mouseX,mouseY,K,K);
  }
  else if(mouseX > Im.width-K/2){ //esco a destra
    c = regionMean(Im, Im.width-K/2, mouseY, K);
    Im.filter(c);
    rect(Im.width-K/2,mouseY,K,K);

  }
  else if(mouseX < K/2){ //esco a sinistra
    c = regionMean(Im, K/2, mouseY, K);
    Im.filter(c);
    rect(K/2,mouseY,K,K);
  }
  else if(mouseY < K/2){ //esco sopra
    c = regionMean(Im, mouseX, K/2, K);
    Im.filter(c);
  rect(mouseX,K/2,K,K);

  }
   
   else if(mouseY > Im.height-K/2){ //esco sotto
    c = regionMean(Im, mouseX, Im.height-K/2, K);
    Im.filter(c);
    rect(mouseX, Im.height-K/2,K,K);


  }
    
  rectMode(CORNER);
  noStroke();
  fill(c);
  rect(Im.width, 0, 512, 512);
}

void keyPressed(){
  if(key=='+' && K<=240){
    K+=10;
  }
  
  if(key=='-'&& K>=20){
    K-=10;
  }
}

color imMean(PImage I){
  color R;
  
  float r=0 ,g=0, b=0;
  I.loadPixels();
  
  for(int i=0; i<I.pixels.length; i++){
    r+= red(I.pixels[i]);
    g+= green(I.pixels[i]);
    b+= blue(I.pixels[i]);
  }
  
  r/=I.pixels.length;
  b/=I.pixels.length;
  g/=I.pixels.length;
  
  R = color(r,g,b);
  return R;
}

color regionMean(PImage I, int x, int y, int n){
    if(x-n/2 < 0)
      x=n/2;
    
    if(y-n/2 < 0)
      y=n/2;
      
    if(x+n/2 > I.width)
      x=I.width-n/2;
      
    if(y+n/2 > I.height)
      y=I.height-n/2;
  
  PImage region = I.get(x-n/2,y-n/2, n, n);
  
  return imMean(region);
}
