PImage Im, ImUni, ImLog;
int N;
void setup(){
  size(768,280);
  N=10;
  
  Im = loadImage("lena.png");
  Im.resize(256,256);
  Im.filter(GRAY);
  image(Im,0,0);
  
}


void draw(){
  ImUni = uniQuant(Im,N);
  ImLog = logQuant(Im,N);
  
  image(ImUni,Im.width,0);
  image(ImLog,Im.width*2,0);
  
  fill(0);
  textSize(20);
  textAlign(CENTER);
  text("Originale",Im.width/2,Im.height+15);
  text("Uniforme",Im.width/2*3,ImUni.height+15);
  text("Logaritmica",Im.width/2*5,ImLog.height+15);
  
  text("N = " + N, width/2, 15);

}

void keyPressed(){
  if(key=='+' && N<256){
    N++;
  }
  
  if(key=='-'&& N > 2){
    N--;
  }
}




PImage uniQuant(PImage I, int k){
  PImage R = I.copy();
  R.filter(GRAY);
  
  
  
  // L' = L*k / N --> N=256 bit
  R.loadPixels();
  int v2;
  
    for(int i=0; i<R.pixels.length; i++){
      int v1 = int(red(R.pixels[i]));
      v2 = floor((v1*k)/256);
      
      //normalizza ---> attuale / max[0,8] * 255

      v2=floor((v2/float(k-1))*255); 
      R.pixels[i] = color(v2);
    }
    
  R.updatePixels();
  return R;
  
}

PImage logQuant(PImage I, int k){
  PImage R = I.copy();
  R.filter(GRAY);
  
  // L' = L*k / N N=8 bit
  R.loadPixels();
  int v2;
    for(int i=0; i<R.pixels.length; i++){
      int v1 = int(red(R.pixels[i]));
      v2 = floor((log(v1)*k)/log(256));
      
      //normalizza
      v2=floor((v2/float(k-1))*255);

      R.pixels[i] = color (v2);
    }
    
  R.updatePixels();
  return R;
  
}
