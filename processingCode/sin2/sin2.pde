

ArrayList<PVector> line = new ArrayList<PVector>();

void setup(){
  
  size(800,800);
}

void draw(){
  background(0);
  ellipseMode(CENTER);
  noStroke();
  fill(255);
  float time = millis()/1000.0;
  float xOrig = 400;
  float yOrig = 400;
  
  // circle
  float radius = 200;
  
  // flower
  //float radius = map(sin(time*7), -1, 1, 100, 300);
  
  float angle = time;
  float x = xOrig + radius * cos(angle);
  float y = yOrig + radius * sin(angle);
  ellipse(x,y,20,20);
  line.add(new PVector(x,y));
  
  stroke(255);
  noFill();
  beginShape();
  for (int i = 0; i < line.size(); i++){
    vertex(line.get(i).x, 
            line.get(i).y);
  }
  endShape();
  
  if (line.size() > 200){
    line.remove(0); 
  }
  

  
}
