//
//  ofxPatchbay.h
//  mondrian
//
//  Created by Mayank Sanganeria on 2/29/20.
//
//  This is modified version by moebiusSurfing
//	* removed all input controllers
//	* adde new ofParameter>float> controller

#pragma once

#include "ofMain.h"
#include "ofxPatchbayInput.h"

class ofxPatchbay
{

public:

	ofxPatchbay() {};
	~ofxPatchbay() {};

	void setupRegister();
	void update();

	void connect1f(string controller, string controllable);
	void disconnect1f(string controller, string controllable);

	void disconnectAll();
	void disconnectAll1f();

	void registerControllable1f(string, function<void(float)>);
	void registerController1f(string, function<float()>);

	void registerControllableB(string, function<void(bool)>);
	void registerControllerB(string, function<bool()>);

	//--

	void print();
	void printConnections();
	void print1f();

	//--

protected:

	map<string, set<string>> connections1f;
	//map<string, set<string>> connections2f;

	map<string, function<void(float)>> controllable1f;
	map<string, function<float()>> controller1f;

	map<string, function<void(bool)>> controllableB;
	map<string, function<bool()>> controllerB;

	ofxPatchbayInput input;

	//--

	// Using float
	///*
protected:

	vector<ofAbstractParameter> paramsControllers;
	vector<ofAbstractParameter> paramsTargets;

	vector<ofParameter<float>> paramsControllers_Float;
	vector<ofParameter<float>> paramsTargets_Float;

	vector<ofParameter<bool>> paramsControllers_Bool;
	vector<ofParameter<bool>> paramsTargets_Bool;

public:

	//--------------------------------------------------------------
	void addParameter(ofParameter<float>& param) {
		input.addParameter(param);
	}
	//--------------------------------------------------------------
	void addParameter(ofParameter<bool>& param) {
		input.addParameter(param);
	}

	//--------------------------------------------------------------
	void addController(ofParameter<float>& p)
	{
		paramsControllers_Float.push_back(p);
		addParameter(p);
	}
	//--------------------------------------------------------------
	void addController(ofParameter<bool>& p)
	{
		paramsControllers_Bool.push_back(p);
		addParameter(p);
	}

	//--------------------------------------------------------------
	void addTarget(ofParameter<float>& p)
	{
		paramsTargets_Float.push_back(p);

		// define and name outputs
		registerControllable1f(p.getName(), [&](float value) {
			p.set(value);
			});
	}
	//--------------------------------------------------------------
	void addTarget(ofParameter<bool>& p)
	{
		paramsTargets_Bool.push_back(p);

		// define and name outputs
		registerControllableB(p.getName(), [&](bool value) {
			p.set(value);
			});
	}

	//--

	// Using abstract
	/*
protected:

	vector<ofAbstractParameter> paramsControllers_Float;
	vector<ofAbstractParameter> paramsTargets_Float;

public:

	//--------------------------------------------------------------
	void addParameter(ofAbstractParameter& p) {
		input.addParameter(p);
	}

	//--------------------------------------------------------------
	void addController(ofAbstractParameter& p)
	{
		paramsControllers_Float.push_back(p);

		addParameter(p);
	}

	//--------------------------------------------------------------
	void addTarget(ofAbstractParameter& p)
	{
		paramsTargets_Float.push_back(p);

		// define and name outputs
		if (p.type() == typeid(ofParameter<float>).name())
		{
			ofParameter<float> pm = p.cast<float>();

			registerControllable1f(pm.getName(), [&](float value) {
				pm.set(value);
				});
		}
	}
	*/

	//--

	// Links

	//--------------------------------------------------------------
	void link(int iCont, int iTar) {
		if (iCont > paramsControllers_Float.size() - 1 || iTar > paramsTargets_Float.size() - 1)
		{
			ofLogError(__FUNCTION__) << "Out of range index for controller or target";
			return;
		}

		connect1f(paramsControllers_Float[iCont].getName(), paramsTargets_Float[iTar].getName());
	}

	//--------------------------------------------------------------
	void unlink(int iCont, int iTar) {
		if (iCont > paramsControllers_Float.size() - 1 || iTar > paramsTargets_Float.size() - 1)
		{
			ofLogError(__FUNCTION__) << "Out of range index for controller or target";
			return;
		}

		disconnect1f(paramsControllers_Float[iCont].getName(), paramsTargets_Float[iTar].getName());
	}
};
