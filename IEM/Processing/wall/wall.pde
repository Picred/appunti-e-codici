void setup(){
size(500,500);
}
void draw(){
int incremento=50;
int spostamento = 25;
boolean bs = false;
for(int y=0;y<=height;y+=spostamento){
  line(0,y*2,width,y*2);
}


for(int y=0; y<height;y+=50){
  if (bs) {
    spostamento+=25;
  }
  else {
    spostamento-=25;
  }
  for(int x=50;x<width;x+=incremento){
     line(x+spostamento,y,x+spostamento,y+incremento);
  }
  bs=!bs;
}

textSize(50);
textMode(SHAPE);
text("Ciao",width/2,height/4);

if(mousePressed){
  exit();
}}
