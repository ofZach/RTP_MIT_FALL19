#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    grabber.setup(640, 480);
     tracker.setup();
}

//--------------------------------------------------------------
void ofApp::update(){

    grabber.update();
    
    if (grabber.isFrameNew()){
        tracker.update(grabber);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    // debug:
    //grabber.draw(0,0);
    //tracker.drawDebug();
   
    
    if (tracker.size() > 0){
        ofPolyline leftEye = tracker.getInstances()[0].getLandmarks().getImageFeature(ofxFaceTracker2Landmarks::LEFT_EYE);
        
        //leftEye.draw();
        
        ofPoint leftAvg;
        for (int i = 0; i < leftEye.size(); i++){
            leftAvg += leftEye[i];
        }
        leftAvg /= leftEye.size();
        //
        
        
        ofPolyline rightEye = tracker.getInstances()[0].getLandmarks().getImageFeature(ofxFaceTracker2Landmarks::RIGHT_EYE);
        
        //leftEye.draw();
        
        ofPoint rightAvg;
        for (int i = 0; i < rightEye.size(); i++){
            rightAvg += rightEye[i];
        }
        rightAvg /= rightEye.size();
        
        ofPoint diff = rightAvg - leftAvg;
        float angle = atan2(diff.y, diff.x);
        
        float scale = 200 / diff.length();
        
        ofPushMatrix();
        ofTranslate(200,200);
        ofScale(scale, scale);
        ofRotateZ(-angle * RAD_TO_DEG);
        grabber.setAnchorPoint(leftAvg.x, leftAvg.y);
        grabber.draw(0,0);
        ofPopMatrix();
        //ofCircle(rightAvg, 3);
        //ofCircle(leftAvg, 3);
        //ofDrawLine(leftAvg, rightAvg);
        
        
        
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
