PImage Im, ImR, ImC; //Immagine Random ImR, Immagine Combinata ImC
float alfa = 0.5;

void setup(){
  size(768,256);
  Im = loadImage("lena.png");
  Im.resize(256,256);
  ImR = randomIm(256,256);
}

void draw(){
  ImC = combine(Im,ImR, alfa);
  
  image(ImR,0,0);
  image(Im,ImR.width,0);
  image(ImC, ImR.width*2,0);
  
  textSize(30);
  text("Alfa = " + alfa, width/2-Im.width/2,height-40);
}

void keyPressed(){
  if(key=='+' && alfa <1){
    alfa+=0.1;
  }
  
  if(key=='-' && alfa>0.1){
    alfa-=0.1;
  }
}


// FUNZIONI
PImage randomIm(int n1, int n2){
  PImage R = createImage(n1,n2,RGB);
  
  R.loadPixels();
  
  //con Mario Rossi
  int max = 'm'+'r'+1;
  for(int i=0; i<R.pixels.length; i++){
    R.pixels[i]= color(int(random(0,max)), int(random(0,max)), int(random(0,max)));
  }
  
  R.updatePixels();
 
  return R;
}


PImage combine(PImage I, PImage Q, float a){
  PImage R = createImage(I.width, I.height, RGB);
  
  R.loadPixels();
  I.loadPixels();
  Q.loadPixels();
  
  float r,g,b;
  
  for(int i=0; i<I.pixels.length; i++){
    r=(a*red(I.pixels[i]) + (1-a)*red(Q.pixels[i]));
    g=(a*green(I.pixels[i]) + (1-a)*green(Q.pixels[i]));
    b=(a*blue(I.pixels[i]) + (1-a)*blue(Q.pixels[i]));
    
    R.pixels[i] = color(r,g,b);
  }
  
  R.updatePixels();
  return R;
}
