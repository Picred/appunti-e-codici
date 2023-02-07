Sponge s;
ArrayList<Stain> stains;

void setup(){
  size(700,700);
  
  s = new Sponge(30);
  stains = new ArrayList<Stain>();
}



void draw(){
  background(0,255,255);
  
  for(Stain st:stains){
    s.absorb(st);
    st.run();

    if(s.absorb(st)){
      st.delete();
    }
  }
  s.run();
}

void keyPressed(){
  if(key=='S'){
    color colore = color( int(random(255)), int(random(255)), int(random(255)) );
    stains.add(new Stain( int(random(50,650)) , -30, int(random(10,50)), colore)); 
  }
  
  if(key=='R'){
      s = new Sponge(30);

  }
}
