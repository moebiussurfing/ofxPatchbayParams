//
//  ofxPatchbay.h
//  mondrian
//
//  Created by Mayank Sanganeria on 2/29/20.
//	This is modified version by moebiusSurfing.
//	removed all input controllers (key/mouse/midi).
//	adding new ofParameter controllers.


/*

	TODO

	think on main vector to store different types.
	abstractParams? map like @daandelange nodes?

	from ofApp patchbay/patcher
	split Node system. merge with added params!

*/


//----


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

	void connect1i(string controller, string controllable);
	void disconnect1i(string controller, string controllable);

	void disconnectAll();
	void disconnectAll1f();
	void disconnectAll1i();

	void registerControllable1f(string, function<void(float)>);
	void registerController1f(string, function<float()>);
	//void registerController1f(string, function<int()>);

	void registerControllable1i(string, function<void(int)>);
	void registerController1i(string, function<int()>);
	//void registerController1i(string, function<int()>);

	void registerControllableB(string, function<void(bool)>);
	void registerControllerB(string, function<bool()>);

	//--

	void print();
	void printConnections();
	void print1f();
	void print1i();

	//--

protected:

	//map<string, set<string>> connections2f;

	map<string, set<string>> connections1f;
	map<string, function<void(float)>> controllable1f;
	map<string, function<float()>> controller1f;
	//map<string, function<int()>> controller1i;

	map<string, set<string>> connections1i;
	map<string, function<void(int)>> controllable1i;
	map<string, function<int()>> controller1i;
	//map<string, function<int()>> controller1i;

	map<string, set<string>> connectionsB;
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

	vector<ofParameter<int>> paramsControllers_Int;
	vector<ofParameter<int>> paramsTargets_Int;

	vector<ofParameter<bool>> paramsControllers_Bool;
	vector<ofParameter<bool>> paramsTargets_Bool;

public:

	//--------------------------------------------------------------
	void addParameter(ofParameter<float>& param) {
		input.addParameter(param);
	}

	//--------------------------------------------------------------
	void addParameter(ofParameter<int>& param) {
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
	void addController(ofParameter<int>& p)
	{
		paramsControllers_Int.push_back(p);
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
	void addTarget(ofParameter<int>& p)
	{
		paramsTargets_Int.push_back(p);

		// define and name outputs
		registerControllable1i(p.getName(), [&](int value) {
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

	//--------------------------------------------------------------
	void linkInt(int iCont, int iTar) {
		if (iCont > paramsControllers_Int.size() - 1 || iTar > paramsTargets_Int.size() - 1)
		{
			ofLogError(__FUNCTION__) << "Out of range index for controller or target";
			return;
		}

		connect1i(paramsControllers_Int[iCont].getName(), paramsTargets_Int[iTar].getName());
	}
	//--------------------------------------------------------------
	void unlinkInt(int iCont, int iTar) {
		if (iCont > paramsControllers_Int.size() - 1 || iTar > paramsTargets_Int.size() - 1)
		{
			ofLogError(__FUNCTION__) << "Out of range index for controller or target";
			return;
		}

		disconnect1i(paramsControllers_Int[iCont].getName(), paramsTargets_Int[iTar].getName());
	}
};
