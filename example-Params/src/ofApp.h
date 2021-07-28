#pragma once

#include "ofMain.h"

#include "ofxPatchbay.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);

    ofxPatchbay patchbay;
	
	// controllers
	ofParameter<float>pController0{ "pController0", 0, 0, 1 };
	ofParameter<float>pController1{ "pController1", 0, 0, 1 };
	ofParameter<float>pController2{ "pController2", 0, 0, 1 };
	ofParameter<float>pController3{ "pController3", 0, 0, 1 };

	// targets
	ofParameter<float>pTarget0{ "pTarget0", 0, 0, 1 };
	ofParameter<float>pTarget1{ "pTarget1", 0, 0, 1 };
	ofParameter<float>pTarget2{ "pTarget2", 0, 0, 1 };
	ofParameter<float>pTarget3{ "pTarget3", 0, 0, 1 };

	// gui
	ofxPanel guiControllers;
	ofxPanel guiTargets;
	ofParameterGroup gControllers{ "gControllers" };
	ofParameterGroup gTargets{ "gTargets" };
	
	// scene
	ofRectangle rect;
	float scale;
	ofColor color = ofColor(255, 0, 0);

	string str2 = "";
};
