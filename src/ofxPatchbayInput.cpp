//
//  ofxPatchbayInput.cpp
//  mondrian
//
//  Created by Mayank Sanganeria on 2/29/20.

#include "ofxPatchbayInput.h"
#include "ofxPatchbay.h"

/*
void ofxPatchbayInput::registerInputs(ofxPatchbay *patchbay, bool bparam) {

	//if (bparam) {
	//	registerParam(patchbay);
	//}
}
*/

// ofParameters
void ofxPatchbayInput::registerParams(ofxPatchbay *patchbay)
{
	for (int i = 0; i < parameters.getSize(); ++i) 
	{
		auto& p = parameters.parameters[i];

		string name = p.getName();
		//string name = "param-" + ofToString(i + 1);

		if (p.type() == typeid(ofParameter<float>).name())
		{
			ofParameter<float> pm = p.cast<float>();
			ofLogNotice() << " type:float value:" << pm.get();

			patchbay->registerController1f(name, [&, i] {
				return pm.get();
				});
		}

		//patchbay->registerController1f(name, [&, i] {
		//	return parameters.parameters[i].get();
		//});
	}
}