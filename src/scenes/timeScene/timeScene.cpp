#include "timeScene.h"

//--------------------------------------------------------------
void timeScene::setup(){

	ofSetVerticalSync(true);

	ofBackground(255, 255, 255);
	TPR.setup();
	playbackStartTime = 0;
    
	loopingSound.loadSound("drawbar_c4_a.caf");
	loopingSound.setVolume(0);
	loopingSound.setLoop(true);
	loopingSound.play();
    
    bGetMousePressed = false;
	
   
}


//--------------------------------------------------------------
void timeScene::update(){

    
    if (bGetMousePressed){
        
        ofPoint vel = ofPoint(mouseX, mouseY) - prevPos;
        
        // since velocity is a line, we want to know how long it is. 
        float lengthOfVel = ofDist(0,0,vel.x, vel.y);
        
        float soundVolume = ofMap(lengthOfVel, 0,40, 0,1);
        float mixVol = 0.1 * soundVolume + 0.9 * loopingSound.getVolume();
		loopingSound.setVolume(mixVol);
        
        float pitch = ofMap(mouseY, 0, (float)ofGetHeight(), 2.5, 0.1);
        float mixPitch = 0.1 * loopingSound.getSpeed() + 0.9 * pitch;
		loopingSound.setSpeed(mixPitch);
		
    }

    
     prevPos.set(mouseX, mouseY);
}

//--------------------------------------------------------------
void timeScene::draw(){

    
	// -------------------------- draw the line
	TPR.draw();
	
	// -------------------------- draw the point at the current time
	if (TPR.bHaveADrawing()){			// if we have a drawing to work with
		
		// figure out what time we are at, and make sure we playback cyclically (!)
		// use the duration here and make sure our timeToCheck is in the range of 0 - duration
		float timeToCheck = ofGetElapsedTimef() - playbackStartTime;
		while (timeToCheck > TPR.getDuration() && TPR.getDuration() > 0){
			timeToCheck -= TPR.getDuration();
		}
		
		// get the position and velocity at timeToCheck
		ofPoint pos = TPR.getPositionForTime(timeToCheck);
		ofPoint vel = TPR.getVelocityForTime(timeToCheck);
		
		// since velocity is a line, we want to know how long it is. 
		float lengthOfVel = ofDist(0,0,vel.x, vel.y);
		
		float soundVolume = ofMap(lengthOfVel, 0,40, 0,1);
        float mixVol = 0.1 * soundVolume + 0.9 * loopingSound.getVolume();
		loopingSound.setVolume(mixVol);
		
		float pitch = ofMap(pos.y, 0, (float)ofGetHeight(), 2.5, 0.1);
        float mixPitch = 0.1 * loopingSound.getSpeed() + 0.9 * pitch;
		loopingSound.setSpeed(mixPitch);
		
		
		ofFill();
		ofSetColor(255,0,0);
		ofCircle(pos.x, pos.y, 2 + lengthOfVel/5.0);
		
		
	}
	
}

//--------------------------------------------------------------
void timeScene::keyPressed(int key){

    if (key == 'f') ofToggleFullscreen();
    

}

//--------------------------------------------------------------
void timeScene::keyReleased(int key){

}

//--------------------------------------------------------------
void timeScene::mouseMoved(int x, int y ){

}


//--------------------------------------------------------------
void timeScene::mouseDragged(int x, int y, int button){
	TPR.addPoint(x,y);
    mouseX = x;
    mouseY = y;
       
}

//--------------------------------------------------------------
void timeScene::mousePressed(int x, int y, int button){
	TPR.startDrawing(x,y);
    mouseX = x;
    mouseY = y;
    bGetMousePressed = true;
    
    
}

//--------------------------------------------------------------
void timeScene::mouseReleased(int x, int y, int button){
	TPR.endDrawing();
	playbackStartTime = ofGetElapsedTimef();
    mouseX = x;
    mouseY = y;
     bGetMousePressed = false;
}

//--------------------------------------------------------------
void timeScene::windowResized(int w, int h){

}



