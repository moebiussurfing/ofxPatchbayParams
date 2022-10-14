//
//  ofxPatchbay.h
//  mondrian
//
//  Created by Mayank Sanganeria on 2/29/20.
//
//  This is modified version by moebiusSurfing
//	* removed all input controllers
//	* adde new ofParameter>float> controller

#ifndef ofxPatchbay_h
#define ofxPatchbay_h

#include "ofMain.h"
#include "ofxPatchbayInput.h"

class ofxPatchbay {

public:

	ofxPatchbay(){};
	~ofxPatchbay(){};

	void update();

	void connect1f(string controller, string controllable);
	void disconnect1f(string controller, string controllable);

	void disconnectAll();
	void disconnectAll1f();

	void registerControllable1f(string, function<void(float)>);
	void registerController1f(string, function<float()>);

	void print();
	void printConnections();
	void print1f();

	//--

	// ofParameters
	
	//--------------------------------------------------------------
	void addParameter(ofParameter<float>& param) {
	//void addParameter(ofAbstractParameter& param) {
		input.addParameter(param);
	}

	//--------------------------------------------------------------
	void setupParameters() {
		input.registerParams(this);
	}

protected:

	map<string, set<string>> connections1f;
	map<string, set<string>> connections2f;

	map<string, function<void(float)>> controllable1f;
	map<string, function<float()>> controller1f;

	ofxPatchbayInput input;

	//--

	//vector<ofAbstractParameter> paramsControllers;
	//vector<ofAbstractParameter> paramsTargets;

	vector<ofParameter<float>> paramsControllers;
	vector<ofParameter<float>> paramsTargets;

	//--

public:

	//--------------------------------------------------------------
	void addController(ofParameter<float>& p)
	//void addController(ofAbstractParameter& p)
	{
		paramsControllers.push_back(p);

		addParameter(p);
	}

	//--------------------------------------------------------------
	//void addTarget(ofAbstractParameteofParameter<float>r& p)
	void addTarget(ofParameter<float>& p)
	{
		paramsTargets.push_back(p);

		// define and name outputs

		/*
		if (p.type() == typeid(ofParameter<float>).name())
		{
			ofParameter<float> pm = p.cast<float>();

			registerControllable1f(pm.getName(), [&](float value) {
				pm.set(value);
				});
		}
		*/

		registerControllable1f(p.getName(), [&](float value) {
			p.set(value);
			});
	}

	//--

	//--------------------------------------------------------------
	void link(int indexControlller, int indexTarget) {
		if (indexControlller > paramsControllers.size() - 1 || indexTarget > paramsTargets.size() - 1)
		{
			ofLogError(__FUNCTION__) << "Out of range index for controller or target";
			return;
		}

		connect1f(paramsControllers[indexControlller].getName(), paramsTargets[indexTarget].getName());
	}

	//--------------------------------------------------------------
	void unlink(int indexControlller, int indexTarget) {
		if (indexControlller > paramsControllers.size() - 1 || indexTarget > paramsTargets.size() - 1)
		{
			ofLogError(__FUNCTION__) << "Out of range index for controller or target";
			return;
		}

		disconnect1f(paramsControllers[indexControlller].getName(), paramsTargets[indexTarget].getName());
	}
};

#endif /* ofxPatchbay_h */
