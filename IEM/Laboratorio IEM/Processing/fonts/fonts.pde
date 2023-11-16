PFont f; //variabile che conterrà il mio font

void setup(){
  size(500,500);
  f = createFont("Calibri",16);
  // println(PFont.list()); vedo i font nel pc
  textFont(f);
  
}

void draw(){
  background(255);
  fill(0);
  textSize(50);
  text("Ciao World bla1 bla2 bla3 bla4",0,height/2+25,width,height/2);
}
