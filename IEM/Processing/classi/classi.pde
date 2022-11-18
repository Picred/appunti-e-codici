ArrayList <Ball> bs; //array di Ball

void setup(){
  size(800,500);
  background(0); // faccio anche la scia dopo con un rect grande quanto la canvas
  bs=new ArrayList<Ball>();
}


void draw(){
  noStroke();
  fill(0,30);
  rect(0,0,width,height); //per la scia
  
  for (Ball b:bs){ //per ogni elemento b in bs
    b.run();
  }
  
}


void keyPressed(){
  if(key=='b' || key == 'B'){
    bs.add(new Ball(random(30,width-30),random(30,height-30),random(20,60),random(1,10),random(1,10)));
  }
  if(key=='g' || key == 'G'){
    bs.add(new GreenBall(random(30,width-30),random(30,height-30),random(20,60),random(1,10),random(1,10)));
  }
  
  if(key=='r' || key == 'R'){
    setup(); //reset della canvas
  }
}
