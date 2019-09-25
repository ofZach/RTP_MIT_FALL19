#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    grabber.setup(640,480);

}

//--------------------------------------------------------------
void ofApp::update(){
    grabber.update();
    
    
    if (grabber.isFrameNew()){
        
        finder.setMinArea(100);
        finder.setThreshold(mouseX);
        finder.setSortBySize(true);
        finder.setInvert(true);
        finder.findContours(grabber);
        
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0);
    grabber.draw(grabber.getWidth(),0);
    
    //finder.draw();
    if (finder.size() > 0){
        ofPolyline line = finder.getPolyline(0);
        
        //line.draw();
        
        //line = line.getSmoothed(MAX(mouseY, 1));
        line.draw();
        
        ofPoint top;
        for (int i = 0; i < line.size(); i++){
            if (i == 0) top = line[i];
            else {
                if (line[i].y < top.y){
                    top = line[i];
                }
            }
        }
        ofSetColor(255,0,0);
        ofCircle(top,5);
        
        catchTop = 0.9 * catchTop + 0.1 * top;
        ofSetColor(0,255,0);
        ofCircle(catchTop, 5);
        
        catchLine.addVertex(catchTop);
        if (catchLine.size() > 80){
            catchLine.getVertices().erase(catchLine.getVertices().begin());
        }
        
        
        ofSetColor(255);
        catchLine.draw();
        
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
