BlackHole b;
ArrayList<Asteroid> asteroids;

void setup(){
  size(512,512);
  b = new BlackHole(mouseX,mouseY);
  asteroids = new ArrayList<Asteroid>();
}


void draw(){
  background(200);
  b.run(asteroids);
  
  if(random(0,1)<0.15){
    asteroids.add(new Asteroid(int(random(0,512)),int(random(0,512)),int(random(5,25))));
  }
  
  for(Asteroid A:asteroids){
    A.run(b);
  }
}

void keyPressed(){
  setup();
}
