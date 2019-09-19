
import processing.video.*;

Capture cam;

void setup(){
  size(1280, 480);
  ellipseMode(CENTER); 
  cam = new Capture(this, 640, 480);
  cam.start();           
}
void draw(){
  background(0);
  if (cam.available() == true) {
    cam.read();
  }
  image(cam, 640, 0);
 
  stroke(255);
  for (int i = 0; i < 640; i+=10){
    for (int j = 0; j < 480; j+=10){
       color c = cam.get(i,j);
       float brightVal = brightness(c);
       float angle = map(brightVal, 0, 255, 0, PI);
       push();
       translate(i,j);
       rotate(angle);
       line(0-5,0,0+5,0);
       pop();
       
    }
  }
  
}
