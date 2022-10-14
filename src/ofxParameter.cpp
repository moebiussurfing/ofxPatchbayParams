#include "ofxParameter.h"

//void ofxParameterFloats::addParameter(ofAbstractParameter& param) {
void ofxParameterFloats::addParameter(ofParameter<float>& param) {
	parameters.push_back(param);

	params.add(param);
}