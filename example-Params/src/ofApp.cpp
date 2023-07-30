#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	// controllers
	gControllers.add(pController0);
	gControllers.add(pController1);
	gControllers.add(pController2);
	gControllers.add(pController3);
	gControllers.add(pController4);
	gControllers.add(pController5);

	// targets
	gTargets.add(pTarget0);
	gTargets.add(pTarget1);
	gTargets.add(pTarget2);
	gTargets.add(pTarget3);
	gTargets.add(pTarget4);
	gTargets.add(pTarget5);

	// define controllers
	patchbay.addController(pController0);
	patchbay.addController(pController1);
	patchbay.addController(pController2);
	patchbay.addController(pController3);
	patchbay.addController(pController4);
	patchbay.addController(pController5);

	// define targets
	patchbay.addTarget(pTarget0);
	patchbay.addTarget(pTarget1);
	patchbay.addTarget(pTarget2);
	patchbay.addTarget(pTarget3);
	patchbay.addTarget(pTarget4);
	patchbay.addTarget(pTarget5);

	//patchbay.setupParameters();
	patchbay.setupRegister();

	// connect
	patchbay.link(0, 0);
	patchbay.link(1, 1);
	patchbay.link(2, 2);
	patchbay.link(3, 3);
	patchbay.linkInt(4, 4);
	patchbay.linkInt(5, 5);

	str2 = "PRESET\n";
	str2 += "0 -> 0\n";
	str2 += "1 -> 1\n";
	str2 += "2 -> 2\n";
	str2 += "3 -> 3\n";
	str2 += "4 -> 4\n";
	str2 += "5 -> 5";

	//-

	// gui
	guiControllers.setup("Controls");
	guiControllers.add(gControllers);
	guiTargets.setup("Targets");
	guiTargets.add(gTargets);

	rect = ofRectangle(0, 0, 100, 100);
}

//--------------------------------------------------------------
void ofApp::update() {
	patchbay.update();

	guiControllers.setPosition(10, 10);
	guiTargets.setPosition(ofGetWidth() - 200 - 10, 10);
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofPushMatrix();
	ofTranslate(ofGetWidth() / 2 * pTarget0, ofGetHeight() / 2 * pTarget1);
	scale = pTarget2;
	ofBackground(32);
	ofSetColor(color.r, color.g, color.b, 255 * pTarget3);
	ofDrawRectangle(rect.x - scale * rect.width / 2, rect.y - scale * rect.height, scale*rect.width, scale*rect.height);
	ofPopMatrix();

	// help
	string str1 = "";
	str1 += "RETURN       : PRINT CONNECTIONS\n";
	str1 += "BACKSPACE    : DISCONNECT ALL\n";
	str1 += "KEYS 1-2-3-4 : PATCHBAY LINKS PRESETS";
	ofDrawBitmapStringHighlight(str1, 20, ofGetHeight() - 100);

	// patching preset
	ofDrawBitmapStringHighlight(str2, ofGetWidth() - 70, ofGetHeight() - 100);

	guiControllers.draw();
	guiTargets.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

	// set configurations

	if (key == OF_KEY_RETURN) patchbay.printConnections();

	if (key == OF_KEY_BACKSPACE)
	{
		patchbay.disconnectAll();	
		str2 = "PRESET\n";
		str2 += "0    0\n";
		str2 += "1    1\n";
		str2 += "2    2\n";
		str2 += "3    3";
		str2 += "4    4";
		str2 += "5    5";
	}

	if (key == '1')
	{
		patchbay.disconnectAll();
		patchbay.link(0, 0);
		patchbay.link(1, 1);
		patchbay.link(2, 2);
		patchbay.link(3, 3);
		patchbay.linkInt(4, 4);
		patchbay.linkInt(5, 5);

		str2 = "PRESET\n";
		str2 += "0 -> 0\n";
		str2 += "1 -> 1\n";
		str2 += "2 -> 2\n";
		str2 += "3 -> 3\n";
		str2 += "4 -> 4\n";
		str2 += "5 -> 5";
	}
	if (key == '2')
	{
		patchbay.disconnectAll();
		patchbay.link(0, 3);
		patchbay.link(1, 2);
		patchbay.link(2, 1);
		patchbay.link(3, 0);
		patchbay.linkInt(4, 5);
		patchbay.linkInt(5, 4);

		str2 = "PRESET\n";
		str2 += "0 -> 3\n";
		str2 += "1 -> 2\n";
		str2 += "2 -> 1\n";
		str2 += "3 -> 0\n";
		str2 += "4 -> 5\n";
		str2 += "5 -> 4";
	}
	if (key == '3')
	{
		patchbay.disconnectAll();
		patchbay.link(0, 3);
		patchbay.link(1, 1);
		patchbay.link(2, 2);
		patchbay.linkInt(3, 0);
		patchbay.linkInt(4, 5);

		str2 = "PRESET\n";
		str2 += "0 -> 3\n";
		str2 += "1 -> 1\n";
		str2 += "2 -> 2\n";
		str2 += "3 -> 0\n";
		str2 += "4 -> 5\n";
		str2 += "5    4";
	}
	if (key == '4')
	{
		patchbay.disconnectAll();
		patchbay.link(0, 2);
		patchbay.link(1, 3);
		patchbay.link(2, 0);
		patchbay.linkInt(3, 1);
		patchbay.linkInt(5, 5);

		str2 = "PRESET\n";
		str2 += "0 -> 2\n";
		str2 += "1 -> 3\n";
		str2 += "2 -> 0\n";
		str2 += "3 -> 1\n";
		str2 += "4    4\n";
		str2 += "5 -> 5";
	}
}