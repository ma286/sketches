#pragma once

#include "baseScene.h"
#include "ofMain.h"
#include "angleLengthLine2.h"

class endlessLineScene : public baseScene {

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        ofPolyline line;
        angleLengthLine2 angleLine;
    
        vector < float > angleDiffs;
        vector < float > distances;
    
        ofPolyline total;
    
        float angle;
        float angleSmooth;
    
        ofPoint catchPoint;
    
        int prevMouseX, prevMouseY;
    
       // float prevAngle;
    
        vector < ofPolyline > oldLines;
    
};
