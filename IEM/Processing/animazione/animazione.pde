void setup(){
size(500,500);
background(0);
}

int x = 0;


void draw(){

strokeWeight(random(500));
      stroke(random(255),random(255),random(255));
      point(random(width),random(width));
      strokeWeight(random(500));
      stroke(random(255),random(255),random(255));
      point(random(width),random(width));
      delay(300);
}
