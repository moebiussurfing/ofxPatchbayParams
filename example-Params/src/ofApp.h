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

	// NOTE: input/output naming could be wrong...
	// We can use controller > target instead.

	// input params (controllers)
	ofParameter<float>pi1{ "pi1", 0, 0, 1 };
	ofParameter<float>pi2{ "pi2", 0, 0, 1 };
	ofParameter<float>pi3{ "pi3", 0, 0, 1 };
	ofParameter<float>pi4{ "pi4", 0, 0, 1 };

	// output params (targets)
	ofParameter<float>po1{ "po1", 0, 0, 1 };
	ofParameter<float>po2{ "po2", 0, 0, 1 };
	ofParameter<float>po3{ "po3", 0, 0, 1 };
	ofParameter<float>po4{ "po4", 0, 0, 1 };

	// gui
	ofxPanel guiInput;
	ofxPanel guiOutput;
	ofParameterGroup gInput{ "gInput" };
	ofParameterGroup gOutput{ "gOutput" };
	
	// scene
	ofRectangle rect;
	float scale;
	ofColor color = ofColor(255, 0, 0);

	string str2 = "";
};
