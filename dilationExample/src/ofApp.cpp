#include "ofApp.h"



void dilate( ofImage & imgA, ofImage & imgB){

    
    for (int i = 0; i < imgA.getWidth(); i++){
        for (int j = 0; j < imgA.getHeight(); j++){
            
            ofColor nw = imgA.getColor( ofClamp(i-1, 0, imgA.getWidth()-1),
                                       ofClamp(j-1, 0, imgA.getHeight()-1));
            ofColor n_ = imgA.getColor( ofClamp(i, 0, imgA.getWidth()-1),
                                       ofClamp(j-1, 0, imgA.getHeight()-1));
            ofColor ne = imgA.getColor( ofClamp(i+1, 0, imgA.getWidth()-1),
                                       ofClamp(j-1, 0, imgA.getHeight()-1));
            ofColor e_ = imgA.getColor( ofClamp(i+1, 0, imgA.getWidth()-1),
                                       ofClamp(j, 0, imgA.getHeight()-1));
            ofColor se = imgA.getColor( ofClamp(i+1, 0, imgA.getWidth()-1),
                                       ofClamp(j+1, 0, imgA.getHeight()-1));
            ofColor s_ = imgA.getColor( ofClamp(i, 0, imgA.getWidth()-1),
                                       ofClamp(j+1, 0, imgA.getHeight()-1));
            ofColor sw = imgA.getColor( ofClamp(i-1, 0, imgA.getWidth()-1),
                                       ofClamp(j+1, 0, imgA.getHeight()-1));
            ofColor w_ = imgA.getColor( ofClamp(i-1, 0, imgA.getWidth()-1),
                                       ofClamp(j, 0, imgA.getHeight()-1));
            
            
            ofColor color = imgA.getColor(i,j);
            if (color.getBrightness() < 127){
                if (nw.getBrightness() > 127 ||
                    n_.getBrightness() > 127 ||
                    ne.getBrightness() > 127 ||
                    e_.getBrightness() > 127 ||
                    se.getBrightness() > 127 ||
                    s_.getBrightness() > 127 ||
                    sw.getBrightness() > 127 ||
                    w_.getBrightness() > 127){
                    imgB.setColor(i,j, ofColor(255));
                } else {
                    imgB.setColor(i,j, ofColor(0));
                }
                    
            } else {
                imgB.setColor(i,j,color);
            }
            //imgB.setColor(i,j,color);
        }
    }
    
    
}


//--------------------------------------------------------------
void ofApp::setup(){

    ken.load("Knowlton-Ken.jpg");
    ken.setImageType(OF_IMAGE_GRAYSCALE);
    
    ken2.allocate(ken.getWidth(), ken.getHeight(), OF_IMAGE_GRAYSCALE);
    ken3.allocate(ken.getWidth(), ken.getHeight(), OF_IMAGE_GRAYSCALE);
    
    for (int i = 0; i < ken.getWidth(); i++){
        for (int j = 0; j < ken.getHeight(); j++){
            ofColor color = ken.getColor(i,j);
            if (color.getBrightness() > 150){
                ken.setColor(i, j, ofColor(255));
            } else {
                ken.setColor(i,j,ofColor(0));
            }
        }
    }
    ken.update();
    
    dilate(ken, ken2);
    ken2.update();
    
}

//--------------------------------------------------------------
void ofApp::update(){

    dilate(ken2, ken3);
    ken2.setFromPixels(ken3.getPixels());
    //dilate(ken3, ken2);
    //ken2.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

  
    ken.draw(0,0);
    ken2.draw(ken.getWidth(), 0);
    
    ofDrawBitmapStringHighlight("press any key to reset", ofPoint(20,20));
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    dilate(ken, ken2);
    ken2.update();
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
