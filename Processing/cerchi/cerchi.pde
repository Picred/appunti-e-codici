size(750,400);

int n_cerchi=8;
int pos = 150;
int diametro=140;
int decremento=30;

background(255);
fill(255);
stroke(255,0,255,100);
strokeWeight(8);
noFill();


for(int i=pos; n_cerchi!=0&&(i+diametro+5)<width; i+=diametro-20,diametro-=15){
  ellipse(i,height/2,diametro-decremento,diametro-decremento);
  n_cerchi--;
}

save("cerchi.jpg");
