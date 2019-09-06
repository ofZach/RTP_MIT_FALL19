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
    
    // xorig, yorig, radius, angle
    
    float time = ofGetElapsedTimef();
    float xOrig = 400;
    float yOrig = 400;
    float radius = 200; //ofMap(sin(time*10), -1, 1, 100, 300);
    float angle = ofGetElapsedTimef()*2;
    
    float x = xOrig + radius * cos(angle*4.435);
    float y = yOrig + radius * sin(angle*1.124);
    
    ofDrawCircle(x,y,10);
    
    line.addVertex(x,y);
    line.draw();
    
    if (line.size() > 500){
        line.getVertices().erase(line.getVertices().begin());
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
