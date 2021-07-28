#include "ofxParameter.h"

ofxParameterFloats::ofxParameterFloats() {
	ofAddListener(params.parameterChangedE(), this, &ofxParameterFloats::Changed_params); // setup()
}

ofxParameterFloats::~ofxParameterFloats() {
	ofRemoveListener(params.parameterChangedE(), this, &ofxParameterFloats::Changed_params); // exit()
}

void ofxParameterFloats::addParameter(ofParameter<float>& param) {
	parameters.push_back(param);

	params.add(param);
}

void ofxParameterFloats::Changed_params(ofAbstractParameter &e)
{
	string name = e.getName();
	ofLogNotice() << "Changed: " << name << " : " << e;

	//if (name == p.getName())
	//{
	//}
}