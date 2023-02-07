Orologio o;
int fps=1; 
void setup(){
  size(500,500);
  background(255);
  o = new Orologio(width/2,height/2,int(random(0,60)),int(random(0,60)),int(random(0,12)));
  
}


void draw(){
  frameRate(fps);
  o.run();
}

void keyPressed(){
  if(key=='-'){
    if(fps>1){
      fps--;
    }
  }
  
  if(key=='+'){
    fps++;
  }
  
}
