PImage Im;
PImage ImCMY;

void settings(){
  Im = loadImage("lena.png");
  Im.resize(Im.width/2,Im.height/2);
  size(Im.width*3,Im.height+30);
}

void setup(){
  
  image(Im,0,0); //mostro la rgb normale scelta
  
  ImCMY = rgb2cmy(Im); //converto Im da rgb a cmy
  image(ImCMY,Im.width,0); //mostro la versione cmy al centro
  imageCMY(ImCMY,ImCMY.width*2,0); //torno alla versione rgb da ImCMY
  
  //didascalie sotto le immagini
  textAlign(CENTER);
  textSize(20);
  fill(0);
  text("RGB Originale",Im.width/2,Im.height+15);
  text("CMY in RGB",Im.width/2+Im.width,Im.height+15);
  text("CMY Corretta",Im.width/2+Im.width*2,Im.height+15);
}

void draw(){

}


PImage rgb2cmy(PImage I){
    PImage R = I.copy();
    R.loadPixels();
    
    float r,g,b,c,m,y;
    for(int i=0; i<R.pixels.length; i++){
      r = red(R.pixels[i]);
      g = green(R.pixels[i]);
      b = blue(R.pixels[i]);
      
      c = 255-r;
      m = 255-g;
      y = 255-b;
      
      R.pixels[i] = color(c,m,y);
    }
    
    R.updatePixels();
    return R;
}

PImage cmy2rgb(PImage I){
    PImage R = I.copy();
    R.loadPixels();
    
    float r,g,b,c,m,y;
    for(int i=0; i<R.pixels.length; i++){
      c = red(R.pixels[i]);
      m = green(R.pixels[i]);
      y = blue(R.pixels[i]);
      
      r = 255-c;
      g = 255-m;
      b = 255-y;
      
      R.pixels[i] = color(r,g,b);
    }
    
    R.updatePixels();
    return R;
}

void imageCMY(PImage I, int x, int y){
  I = cmy2rgb(I);
  image(I,x,y);
}
