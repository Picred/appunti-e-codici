PImage Im, ImH, ImH2;

void setup(){
  size(768,256);
  Im = loadImage("lena.png");
  Im.filter(GRAY);
  
  
  Im.resize(256,256);
  image(Im,0,0);
  
  ImH = hash(Im, int(random(256)), int(random(256)));
  image(ImH, Im.width, 0);
  
  ImH2 = hash(Im, int(random(1,256)), int(random(1,256)), int(random(3, 11)));
  image(ImH2, Im.width*2, 0);

}


void draw(){}



PImage hash(PImage I, int h, int k){
  PImage R = I.copy();
  
  R.loadPixels();
  
  R.pixels[h*R.width+h] = color(0);
  R.pixels[k*R.width+k] = color(0);
  
  R.updatePixels();
  R.filter(GRAY);
  
  return R;
}



PImage hash(PImage I, int h, int k, int n){
  PImage R = I.copy();

  R.loadPixels();

  //operatore di massimo

  PImage window = R.get(h,k,n,n);

  window.loadPixels();
  float max = red(R.pixels[0]);
  for(int i=1; i<window.pixels.length; i++){
    if(red(window.pixels[i]) > max){
      max = red(R.pixels[i]);
    }
  }

  //devo impostare il pixel max nel punto [h,k]
  R.set(h+n/2,k+n/2, int(max));
  //fine operatore di massimo

  R.pixels[h*R.width+h] = color(0);
  R.pixels[k*R.width+k] = color(0);

  R.updatePixels();
  R.filter(GRAY);

  return R;

}

// RIVEDERE l'operatore di massimo
