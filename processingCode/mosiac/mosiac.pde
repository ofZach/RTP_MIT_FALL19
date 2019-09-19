
PImage img;

void setup(){
  ellipseMode(CENTER); 
  size(1000,500);
  img = loadImage("Knowlton-Ken.jpg");
}
void draw(){
  background(0);
  image(img, 500, 0);
  
  for (int i = 0; i < 500; i+=10){
    for (int j = 0; j < 500; j+=10){
      color c = img.get(i,j);
      float brightness = brightness(c);
      float radius = map(brightness, 0, 255, 0, 10);
      ellipse(i,j,radius,radius);
    }
  }
}
