#include "ofApp.h"



// used:
// https://github.com/hardikvasa/google-images-download


//--------------------------------------------------------------
void ofApp::setup(){

    ofDirectory dir;
    dir.listDir("pbears");
    for (int i = 0; i < dir.size(); i++){
        cout << dir.getPath(i) << endl;
        
        ofImage temp;
        images.push_back(temp);
        images.back().load(dir.getPath(i));
        
    }
    
    int w = images[0].getWidth();
    int h = images[0].getHeight();
    
    average.allocate(images[0].getWidth(),
                     images[0].getHeight(),
                     OF_IMAGE_COLOR);
    
    for (int i = 0; i < w; i++){
        for (int j = 0; j < h; j++){
            int r = 0;
            int g = 0;
            int b = 0;

            for (int k = 0; k < images.size(); k++){
                ofColor col = images[k].getColor(i,j);
                
                r += col.r;
                g += col.g;
                b += col.b;
            }
            r /= images.size();
            g /= images.size();
            b /= images.size();
            average.setColor(i,j, ofColor(r,g,b));
            
        }
    }
    
    average.update();
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(255, 255, 255);
    average.draw(100,100);
    
    //images[ ofGetFrameNum() % images.size() ].draw(0,0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
