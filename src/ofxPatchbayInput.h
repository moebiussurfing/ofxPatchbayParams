//
//  ofxPatchbayInput.h
//  mondrian
//
//  Created by Mayank Sanganeria on 2/29/20.

#pragma once

#include "ofMain.h"

class ofxPatchbay;

class ofxPatchbayInput
{
public:

	void registerParams(ofxPatchbay* patchbay);
	 
	//--

	// abstract
	/*
	void addParameter(ofAbstractParameter& p)
	{
		parameters.push_back(p);
	}

protected:

	vector<ofAbstractParameter> parameters;
	*/

	//--

	// float
	///*
public:

	void addParameter(ofParameter<float>& p)
	{
		parameters.push_back(p);
	}

protected:

	vector<ofParameter<float>> parameters;
	//*/
};
