#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    player.load("input.mov");
    player.play();
}

//--------------------------------------------------------------
void ofApp::update(){

    player.update();
    if (player.isFrameNew()){
        finder.setMinArea(10);
        finder.setSortBySize(true);
        finder.findContours(player);
        if (finder.size() > 0){
            
            ofPolyline line = finder.getPolyline(0);
            
            line = line.getSmoothed(5);
            lines.push_back(line);
            if (lines.size() > 100){
                lines.erase(lines.begin());
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    ofSetColor(255);
    
    player.draw(player.getWidth(),0);
    //finder.draw();
    
    ofPushMatrix();
    ofScale(3,3);
    for (int i = 0; i< lines.size(); i++){
        
        ofSetColor(  sin(i * 0.1) * 127 + 127);
        ofBeginShape();
        for (int j = 0; j < lines[i].size(); j++){
            ofPoint ptToAdd = lines[i][j] + ofPoint(i * 3, 0);
            ofVertex(ptToAdd);
        }
        ofEndShape();
        //lines[i].draw();
    }
    ofPopMatrix();
    
    ofSetColor(255);
    
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
