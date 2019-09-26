#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    grabber.setup(640,480);
    
}

//--------------------------------------------------------------
void ofApp::update(){

    grabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0);
    
    //grabber.draw(grabber.getWidth(),0);
    
    
    cam.begin();
    cam.enableOrtho();
    ofPushMatrix();
    ofScale(2,-2,2);
    ofRotateX(30);
    for (int i = 0; i < grabber.getHeight(); i+=5){
        ofPolyline line;
        for (int j =0; j < grabber.getWidth(); j++){
            ofColor col = grabber.getPixels().getColor(j,i);
            int brightness = col.getBrightness();
            line.addVertex(j - grabber.getWidth()/2,i - grabber.getHeight()/2, ofMap(brightness, 0, 255, 0, 100));
        }
        line = line.getSmoothed(11);
        line.draw();
    }
    ofPopMatrix();
    
    cam.end();
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
