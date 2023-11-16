size(435,289);
int incremento=10;

background(0,0);
stroke(255,0,255);
strokeWeight(2);

for(int x=0; x<=width; x+=incremento+10){
  for(int y=0;y<=height; y+=incremento+10){
    line(x,y,x+incremento,y+incremento);
    line(x+incremento,y,x,y+incremento);
  }
}
