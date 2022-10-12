size(700,300);
background(0);

int diametro=90;
int empty=20;

int fase=4;

fill(255);
for(int x=60;x<=width;x+=(diametro+empty)){
  ellipse(x,height/2,diametro,diametro);
}

fill(0);
for(int x=60;x<=width;x+=(diametro+empty)){
  ellipse(x+fase,height/2-fase,diametro,diametro);
  fase+=4;
}

save("fasi_luna.jpg");
