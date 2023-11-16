Ball ball;
Ball hyperBall;


void setup(){
  size(512,256);
  ball = new Ball( int(random(256)), int(random(256)), 40);
  hyperBall = new HyperBall( int(random(256,512)), int(random(256)), 40);
}


void draw(){
  background(0);
  ball.run();
  hyperBall.run();
}
