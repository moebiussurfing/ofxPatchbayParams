//
//  ofxPatchbayInput.cpp
//  mondrian
//
//  Created by Mayank Sanganeria on 2/29/20.
//
//  This is modified version by moebiusSurfing
//	* removed all input controllers
//	* adde new ofParameter>float> controller

#include "ofxPatchbayInput.h"
#include "ofxPatchbay.h"

void ofxPatchbayInput::registerInputs(ofxPatchbay *patchbay, bool bparam) {

	//if (bparam) {
	//	registerParam(patchbay);
	//}
}

// ofParameters
void ofxPatchbayInput::registerParams(ofxPatchbay *patchbay) {
	for (int i = 0; i < parameters.getSize(); ++i) {
		string name = parameters.parameters[i].getName();
		//string name = "param-" + ofToString(i + 1);
		patchbay->registerController1f(name, [&, i] {
			return parameters.parameters[i].get();
		});
	}
}