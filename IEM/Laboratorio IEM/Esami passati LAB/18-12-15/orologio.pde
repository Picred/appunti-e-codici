class Orologio{
   int x,y;
   int ore,min,sec;
  Orologio(int x, int y, int sec, int min, int ore){
    this.x=x;
    this.y=y;
    this.ore=ore;
    this.sec=sec;
    this.min=min;
  }
  
  void display(){
    strokeWeight(14);
    stroke(0,180,0);
    fill(255);
    ellipse(x,y,150,150);
    
    pushMatrix();
      translate(x,y);
      rotate(radians(map(sec,0,60,0,360)));
      //lancetta dei secondi
      strokeWeight(1);
      stroke(0);
      line(0,0,0,0-50);
    popMatrix();
    
    pushMatrix();
      translate(x,y);
      rotate(radians(map(min,0,60,0,360)));
      //lancetta dei minuti
      stroke(200,0,0);
      strokeWeight(2);
      line(0,0,0,0-40);
    popMatrix();
    
    pushMatrix();
      translate(x,y);
      rotate(radians(map(ore,0,12,0,360)));
      //lancetta delle ore
      stroke(0,0,200);
      strokeWeight(3);
      line(0,0,0,0-30);
    popMatrix();
}
  
  void move(){
    sec++;
    
    if(sec>59){
      sec=0;
      min++;
    }
    
    if(min>59){
      min=0;
      ore++;
    }
    
    if(ore>11){
      ore=0;      
    }
    
  }
  
  void run(){
    display();
    move();
  }

}
