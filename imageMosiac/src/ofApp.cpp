#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ken.load("Knowlton-Ken.jpg");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0);
    
    ofSetColor(255);
    ken.draw(ken.getWidth(),0);
    
    for (int i = 0; i < ken.getWidth(); i+=10){
        for (int j = 0; j < ken.getHeight(); j+=10){
            ofColor color = ken.getColor(i,j); // DISNEYLAND !!
            
            // ken.getPixels().getData()[(j * width + i)*3] DETROIT
            //ofSetColor(color);
            float brightness = color.getBrightness();
            float radius = ofMap(brightness, 0, 255, 0, 5);
            ofDrawCircle(i,j,radius);
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
