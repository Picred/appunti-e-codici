Gun gun;
ArrayList<Bullet> bullets;
ArrayList<Asteroid> asteroids;

void setup(){
  size(512,512);
  frameRate(60);
  
  gun = new Gun(256,470);
  bullets = new ArrayList<Bullet>();
  asteroids = new ArrayList<Asteroid>();
  
}

void draw(){
  background(0,255,255);
  
  if(random(0,1) < 0.05){
    asteroids.add(new Asteroid(-50,random(256), random(2,7), random(-2,2)));
  }
  
  for(Bullet b:bullets)
    b.run();

    for(Asteroid a:asteroids){
      a.run();
      for(Bullet b:bullets)
        a.colpito(b);
  }
    gun.run();

}

void keyPressed(){
  if(key=='A'){
    bullets.add(gun.shot());
  }
}
