#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    grabber.setup(640,480);
    img.allocate(grabber.getWidth(),
                 grabber.getHeight(),
                 OF_IMAGE_COLOR);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    grabber.update();
    
    
//    for (int i = 0; i < grabber.getWidth(); i++){
//        if ((int)ofGetFrameNum() % (int)grabber.getWidth() == i){
//            for (int j = 0; j < grabber.getHeight(); j++){
//
//                ofColor color = grabber.getPixels().getColor(i,j);
//                img.setColor(i,j, color);
//            }
//        }
//    }
    
    
     for (int j = 0; j < grabber.getHeight(); j++){
        if ((int)ofGetFrameNum() % (int)grabber.getHeight() == j){
            for (int i = 0; i < grabber.getWidth(); i++){
                
                ofColor color = grabber.getPixels().getColor(i,j);
                img.setColor(i,j, color);
            }
        }
    }

    img.update();
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    grabber.draw(0,0);
    
    img.draw(grabber.getWidth(),0);
    
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
