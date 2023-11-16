size(500,500);
background(0);
noStroke();
int i= width/2;
int decremento=19;
int v=width;

rectMode(CORNERS);

for(;i>0;i-=19){
  fill(230+decremento,60);
  rect(i,i,v,v);
  v-=decremento;
}

save("quadrati.jpg");
