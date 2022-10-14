//
//  ofxPatchbayInput.cpp
//  mondrian
//
//  Created by Mayank Sanganeria on 2/29/20.

#include "ofxPatchbayInput.h"
#include "ofxPatchbay.h"

//--

// float 
///*
void ofxPatchbayInput::registerParams(ofxPatchbay* patchbay)
{
	for (int i = 0; i < parameters.size(); ++i)
	{
		auto& p = parameters[i];
		string name = p.getName();

		patchbay->registerController1f(name,
			[&, i] {
				return parameters[i].get();
			});
	}
}
//*/

/*
// abstract
void ofxPatchbayInput::registerParams(ofxPatchbay* patchbay)
{
	for (int i = 0; i < parameters.size(); ++i)
	{
		auto& p = parameters[i];
		string name = p.getName();

		if (p.type() == typeid(ofParameter<float>).name())
		{
			ofParameter<float> pm = p.cast<float>();
			ofLogNotice() << " type:float value:" << pm.get();

			patchbay->registerController1f(name, [&, i] {
				return pm.get();
				});
		}
	}
}
*/