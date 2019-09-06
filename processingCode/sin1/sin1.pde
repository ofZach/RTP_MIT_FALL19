


void setup(){
  
  size(800,800);
}

void draw(){
  background(0);
  ellipseMode(CENTER);
  noStroke();
  float time = millis()/1000.0;
  for (int i = 0; i < 800; i++){
      // phase offset 
      //float x = map(sin(time + (i*0.1)), -1, 1, 200,600);
      
      // fequency offset 
      float x = map(sin(time * (i*0.1)), -1, 1, 200,600);
      ellipse(x,i, 5,5);
   }
}
