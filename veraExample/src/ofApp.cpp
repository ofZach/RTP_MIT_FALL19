#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(255);
    ofSeedRandom(mouseX);
    ofSetColor(0);
    for (int i = 0; i < 50; i++){
        for (int j = 0; j < 50; j++){
            float x = ofMap(i, 0, 49, 50, 750);
            float y = ofMap(j, 0, 49, 50, 750);
            
            ofPushMatrix();
            ofTranslate(x,y);
            ofRotateZ(ofRandom(0,360));
            
            float noise = ofNoise(i*0.07, j*0.07, mouseY*0.1);
            if (noise > .15) ofLine(0-15, 0, 0+15, 0);
            
            ofPopMatrix();
            //ofDrawCircle(x,y,5);
        }
    }
    
    
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
