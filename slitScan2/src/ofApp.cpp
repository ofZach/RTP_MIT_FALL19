#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    grabber.setup(640,480);
    img.allocate(grabber.getWidth(), grabber.getHeight(), OF_IMAGE_COLOR);
}

//--------------------------------------------------------------
void ofApp::update(){

    grabber.update();
    
    ofImage temp;
    frames.push_back(temp);
    frames.back().setUseTexture(false);
    frames.back().setFromPixels(grabber.getPixels());
    if (frames.size() > 60){
        frames.erase(frames.begin());
    }
    
    for (int j = 0; j < grabber.getHeight(); j++){
        
        int whichFrame = ofMap(j, 0, grabber.getHeight(), 0, frames.size());
        if (frames.size() > whichFrame){
            for (int i = 0; i < grabber.getWidth(); i++){
                img.setColor(i,j, frames[whichFrame].getColor(i,j));
            }
        }
    }
    img.update();
    
    
    
    
    //cout << frames.size() << endl;
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    grabber.draw(0,0);
    
    img.draw(grabber.getWidth(), 0);
    
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
