size (500,500);
colorMode(RGB,500);
int trasp= 500;
int lato = 50;
noStroke();

int x=0;
for(;x<width;x+=lato){
  for(int i=x;i>=0;i-=lato){
    fill(0,trasp);
    rect(i,x-i,lato,lato);
  }
  trasp-=lato;
}

for (;x>width-lato;x-=lato){
    for(int i=x;i<width-lato;i+=lato){
      fill(0,ijhh);
      rect(i,x-i,lato,lato);
    }
}
