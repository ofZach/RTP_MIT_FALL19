
// VERA 1


void setup(){
  
  size(800,800);
}

void draw(){
  
    // mouse right left for random seed
    // up down for noise
    
    background(255);
    randomSeed(mouseX);
    stroke(0);
    for (int i = 0; i < 50; i++){
        for (int j = 0; j < 50; j++){
            float x = map(i, 0, 49, 50, 750);
            float y = map(j, 0, 49, 50, 750);
            
            pushMatrix();
            translate(x,y);
            rotate(random(0,360));
            
            float noise = noise(i*0.0912, j*0.0912, mouseY*0.1);
            if (noise > .25) line(0-15, 0, 0+15, 0);
            
            popMatrix();
            //ofDrawCircle(x,y,5);
        }
    }
}
