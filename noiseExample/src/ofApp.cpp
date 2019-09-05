#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    
    
    ofBackground(0);
//    ofSeedRandom(mouseX);
//    for (int i = 0; i < 800; i++){
//
//        //ofRandom();
//        //ofNoise();
//
//        ofDrawCircle(i, 400 + ofNoise(i*0.01)*200, 1);
//    }
    
    float time = ofGetElapsedTimef();
    for (int i = 0; i < 300; i++){
        for (int j = 0; j < 300; j++){
            ofSetColor( ofNoise(i*0.01, j*0.01, time)*255);
            ofDrawRectangle(i,j,1,1);
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
