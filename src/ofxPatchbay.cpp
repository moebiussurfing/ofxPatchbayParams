//
//  ofxPatchbay.cpp
//  mondrian
//
//  Created by Mayank Sanganeria on 2/29/20.

#include "ofxPatchbay.h"

//--

void ofxPatchbay::registerControllable1f(string name, function<void(float)> func)
{
	controllable1f[name] = func;
}
void ofxPatchbay::registerController1f(string name, function<float()> func)
{
	controller1f[name] = func;
}

void ofxPatchbay::registerControllableB(string name, function<void(bool)> func)
{
	controllableB[name] = func;
}
void ofxPatchbay::registerControllerB(string name, function<bool()> func)
{
	controllerB[name] = func;
}

//--

void ofxPatchbay::setupRegister() {
	input.registerParams(this);
}

//--

void ofxPatchbay::connect1f(string controller, string controllable)
{
	if (controller1f.find(controller) == controller1f.end())
	{
		ofLog(OF_LOG_WARNING, "Controller: " + controller + " not registered as yet");
	}
	connections1f[controller].insert(controllable);
}

void ofxPatchbay::disconnect1f(string controller, string controllable)
{
	if (controller1f.find(controller) == controller1f.end())
	{
		ofLog(OF_LOG_WARNING, "Controller: " + controller + " not registered as yet");
	}
	connections1f[controller].erase(controllable);
}

//--

void ofxPatchbay::disconnectAll()
{
	disconnectAll1f();
}

void ofxPatchbay::disconnectAll1f()
{
	connections1f.clear();
}

//--

void ofxPatchbay::update()
{
	///*
	for (auto& connection : connections1f)
	{
		auto controller = controller1f[connection.first];

		if (controller == NULL)
		{
			ofLog(OF_LOG_WARNING, "process(): Controller " + connection.first + " not found");
		}
		else
		{
			auto value = controller();
			for (auto& controllableName : connection.second)
			{
				auto controllable = controllable1f[controllableName];
				if (controllable == NULL)
				{
					ofLog(OF_LOG_WARNING, "process(): Controllable " + controllableName + " not found");
				}
				else
				{
					controllable(value);
				}
			}
		}
	}
	//*/
}

//--

// Print

void ofxPatchbay::print() {
	print1f();
}
void ofxPatchbay::print1f() {
	cout << "\nControllable 1fs:" << endl;
	for (auto& item : controllable1f) {
		cout << item.first << endl;
	}
	cout << "\nController 1fs:" << endl;
	for (auto& item : controller1f) {
		cout << item.first << endl;
	}
	cout << "\nConnection 1fs:" << endl;
	for (auto& item : connections1f) {
		cout << item.first << ": [";
		for (auto& to : item.second) {
			cout << to << ", ";
		}
		cout << "]" << endl;
	}
}
void ofxPatchbay::printConnections() {
	cout << "\nConnection 1fs:" << endl;
	for (auto& item : connections1f) {
		cout << item.first << ": [";
		for (auto& to : item.second) {
			cout << to << ", ";
		}
		cout << "]" << endl;
	}
	//cout << "\nConnection 2fs:" << endl;
	//for (auto& item : connections2f) {
	//	cout << item.first << ": [";
	//	for (auto& to : item.second) {
	//		cout << to << ", ";
	//	}
	//	cout << "]" << endl;
	//}
}
