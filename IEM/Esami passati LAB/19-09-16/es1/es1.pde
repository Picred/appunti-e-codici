Bucket bucket;
ArrayList<Egg> eggs;
void setup(){
  size(500,500);
  frameRate(60);
  
  eggs = new ArrayList<Egg>();
  bucket = new Bucket(width/2,450);
}



void draw(){
  background(0,255,255);
  
  bucket.run();
  for(Egg e:eggs){
    e.run();
    bucket.checkEgg(e);
  }
  if(random(0,1) < 0.05){
    eggs.add(new Egg(random(25,475), 0, random(4,8))); 
  }
}
