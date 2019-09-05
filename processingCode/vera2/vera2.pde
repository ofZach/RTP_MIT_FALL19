
// VERA 2


void setup(){
  
  size(800,800);
}

void draw(){
  
    background(255);
    
    rectMode(CENTER);
    stroke(0);
    noFill();
    
    randomSeed(mouseX);
    for (int x = 0; x < 5; x++){
        for (int y = 0; y < 5; y++){
            for (int i = 0; i < 10; i++){
                if (random(0,1) < .98) rect(100 + x*100, 100 + y*100, i*10+5, i*10+5);
            }
        }
    }
}
