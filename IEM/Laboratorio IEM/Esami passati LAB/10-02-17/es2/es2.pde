PImage Im;
int S;
void setup(){
  size(512,256);
  Im = loadImage("lena.png");
  Im.resize(256,256);
  Im.filter(GRAY);
  
  S=2;
}


void draw(){
  background(0);
  image(Im,0,0);

  image(jonnyFilter(Im,S),Im.width,0);
  
  textSize(30);
  text("S = " + S,width-70, 50);
}

void keyPressed(){
  if(key=='+' && S < 9)
    S++;
  if(key=='-' && S > 2)
    S--;
}



PImage jonnyFilter(PImage I, int N){
  PImage R = I.copy();
  PImage window;
  
  
  for(int x=N/2; x<R.width-N/2; x++){
    for(int y=N/2; y<R.height-N/2; y++){
      window = R.get(x-N/2, y-N/2,N,N);
      window.loadPixels();
      float max = red(window.pixels[0]);
      float min = red(window.pixels[0]);
      
      for(int i=1; i<window.pixels.length; i++){
        if(red(window.pixels[i]) > max)
          max = red(window.pixels[i]);
          
        if(red(window.pixels[i]) < min)
          min = red(window.pixels[i]);
      }
      float diff = max-min;
      
      R.set(x-N/2, y-N/2, color(diff));
      
      /*
      R.loadPixels();
      R.pixels[j] = color(diff);
      if(j<R.pixels.length)
        j++;  
      R.updatePixels();*/
    }
  }
  return R;
}
