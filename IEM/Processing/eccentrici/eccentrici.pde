size(500,500);

background(255);
int diametro=width/8;
int incremento=diametro;
int centro=width/2;
int x = width/16;
strokeWeight(3);
line(0,height/2,width,height/2);
fill(0,0);

for (int i = 1; i < 8; i++){  
  ellipse(x+diametro/2,centro,diametro,diametro);
  diametro+=incremento;
}

save("eccentrici.jpg");
