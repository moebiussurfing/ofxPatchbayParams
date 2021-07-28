
#ifndef ofxParameter_h
#define ofxParameter_h

#include "ofMain.h"

//  This is modified version by moebiusSurfing
//	* removed all input controllers
//	* adde new ofParameter>float> controller

class ofxParameterFloats {
public:
	ofxParameterFloats();
	~ofxParameterFloats();

	vector<ofParameter<float>> parameters;
	void addParameter(ofParameter<float>& param);

	ofParameterGroup params{ "Params" };
	void Changed_params(ofAbstractParameter &e);

	int getSize() {
		return parameters.size();
	}
};


#endif /* ofxParameter_h */
