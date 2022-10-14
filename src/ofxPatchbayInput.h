//
//  ofxPatchbayInput.h
//  mondrian
//
//  Created by Mayank Sanganeria on 2/29/20.
//
//  This is modified version by moebiusSurfing
//	* removed all input controllers
//	* adde new ofParameter>float> controller

#ifndef ofxPatchbayInput_h
#define ofxPatchbayInput_h

#include <iostream>

#include "ofxParameter.h"

using namespace std;

class ofxPatchbay;

class ofxPatchbayInput
{
public:

	void registerParams(ofxPatchbay* patchbay);

	//void addParameter(ofAbstractParameter& param)
	void addParameter(ofParameter<float>& param)
	{
		parameters.addParameter(param);
	}

protected:

	ofxParameterFloats parameters;
};

#endif /* ofxPatchbayInput_h */
