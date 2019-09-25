#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    grabber.setup(640, 480);
    thresh.allocate(grabber.getWidth(), grabber.getHeight(), OF_IMAGE_GRAYSCALE);
    
    for (int i = 0; i < 100; i++){
        ofPoint pt;
        pt.set( ofMap(i, 0, 99, 0, 639), 0);
        pts.push_back(pt);
    }
}

//--------------------------------------------------------------
void ofApp::update(){

    grabber.update();
    
    if (grabber.isFrameNew()){
        
        for (int i = 0; i < grabber.getWidth(); i++){
            for (int j = 0; j < grabber.getHeight(); j++){
                ofColor color = grabber.getPixels().getColor(i,j);
                int brightness = color.getBrightness();
                if (brightness > mouseX){
                    thresh.setColor(i,j, ofColor::white);
                } else {
                    thresh.setColor(i,j, ofColor::black);
                }
            }
        }
        thresh.update();
    }
    
    for (int i = 0; i < pts.size(); i++){
        
        ofColor color = thresh.getColor(pts[i].x, pts[i].y);
        if (color.getBrightness() < 127){
            
            // let's search up
            // and see if we find white !!
            
            for (int j = pts[i].y; j >= 0; j--){
                ofColor color = thresh.getColor(pts[i].x, j);
                if (color.getBrightness() > 127){
                    // :)
                    pts[i].y = j;
                    break;
                }
                if (j == 0){
                    pts[i].y = 0;
                }
                
            }
            
            
        } else {
           
            pts[i].y += 1;
            if (pts[i].y >= grabber.getHeight()){
                pts[i].y = 0;
            }
        }
        // are we on a black pixel,
        // do nothing
        
        // else
        // move
        
        
    }
    
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(255);
    grabber.draw(0,0);
    thresh.draw(grabber.getWidth(),0);
    
    ofSetColor(255,0,0);
    for (int i = 0; i < pts.size(); i++){
        ofDrawCircle(pts[i], 2);
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
