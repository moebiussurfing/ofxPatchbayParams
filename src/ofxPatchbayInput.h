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
	void addParameter(ofAbstractParameter& p)
	{
		if (p.type() == typeid(ofParameter<float>).name()) addParameter_Float(p.cast<float>());
		else if (p.type() == typeid(ofParameter<bool>).name()) addParameter_Bool(p.cast<bool>());
	}

protected:

	void addParameter_Float(ofParameter<float>& p)
	{
		parameters_Float.push_back(p);
	}
	void addParameter_Bool(ofParameter<bool>& p)
	{
		parameters_Bool.push_back(p);
	}

protected:

	vector<ofParameter<float>> parameters_Float;
	vector<ofParameter<bool>> parameters_Bool;
	//*/
};
