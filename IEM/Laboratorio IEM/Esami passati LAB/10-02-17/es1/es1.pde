Volcano v1;
Volcano v3;
Volcano v2;
ArrayList<FireBall> fireballs;
String stato = "OFF";

void setup(){
  size(640,480);
  frameRate(60);
  
  v1 = new Volcano(random(40,600), height);
  v2 = new Volcano(random(40,600), height);
  v3 = new Volcano(random(40,600), height);
  
  fireballs = new ArrayList<FireBall>();
  

}


void draw(){
  background(0);
  v1.run();
  v2.run();
  v3.run();  
  
  for(FireBall fb:fireballs){
    fb.run();
  }
  
  if(stato == "ON"){
    if(random(0,1) < 0.2){
      FireBall tmp = v1.genera();
      fireballs.add(tmp);
    }
  }
  
  if(stato == "ON"){
    if(random(0,1) < 0.2){
      FireBall tmp = v2.genera();
      fireballs.add(tmp);
    }
  }
  
  if(stato == "ON"){
    if(random(0,1) < 0.2){
      FireBall tmp = v3.genera();
      fireballs.add(tmp);
    }
  }
  
  
}

void keyPressed(){
  if(key=='N' || key == 'n'){
    if(stato == "OFF")
      stato = "ON";
      
    else if(stato == "ON")
      stato = "OFF";
  }
    println(stato);
}
