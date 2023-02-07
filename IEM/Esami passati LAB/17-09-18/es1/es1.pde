PImage lemonFilter(PImage I){
  PImage R = I.copy();  
  R.loadPixels();
  int r,g,b;
  
  for(int i=0; i<R.pixels.length; i++){
    r = int(red(R.pixels[i]));
    g = int(red(R.pixels[i]));
    b = int(red(R.pixels[i]));
    
    R.pixels[i] = color(r-b/8,g+b,0);
  }
  
  R.updatePixels();
  return R;
}


PImage orangeFilter(PImage I){
  PImage R = I.copy();  
  R.loadPixels();
  int r,g,b;
  
  for(int i=0; i<R.pixels.length; i++){
    r = int(red(R.pixels[i]));
    g = int(red(R.pixels[i]));
    b = int(red(R.pixels[i]));
    
    R.pixels[i] = color(r+b,g,0);
  }
  
  R.updatePixels();
  return R;
}


PImage applyArea(PImage I, int x, int y, int d, boolean f){
  PImage R = I.copy();
  PImage tmp = R.get(x-d/2,y-d/2,d,d);
  
  if(f){
    tmp = orangeFilter(tmp);
  }
  else{
    tmp = lemonFilter(tmp);
  }
  
  R.set(x-d/2,y-d/2,tmp);
  return R;
}
