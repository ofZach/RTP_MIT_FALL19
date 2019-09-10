#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    font.load("framd.ttf", 200, true, true, true);
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0);
    
    //font.drawString("hello", 200,200);
    vector < ofPath > paths = font.getStringAsPoints("hello");
    ofPushMatrix();
    ofTranslate(300,300);
    for (int i = 0; i < paths.size(); i++){
        ofPath path = paths[i];
        vector < ofPolyline > lines = path.getOutline();
        
        for (int j = 0; j < lines.size(); j++){
            
            ofPolyline line = lines[j];
            line = line.getResampledBySpacing(6);
            line = line.getSmoothed(MAX(mouseX, 1));
            
            for (int k = 0; k < line.size(); k++){
                ofDrawCircle(line[k], 2);
            }
            
            //lines[j].draw();
        }
        
    }
    ofPopMatrix();
    
    
    
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
