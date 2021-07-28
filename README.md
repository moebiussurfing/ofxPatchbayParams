# ofxPatchbay

This is modified version by **moebiusSurfing** from https://github.com/e7mac/ofxPatchbay.  
* Removed all input controllers (keys, mouse and MIDI).  
* Added new ofParameter<float> controller.  
Thanks @**e7mac**!  

ofApp.h
```.c++
ofxPatchbay patchbay;

// params controllers
ofParameter<float>pi1{ "pi1", 0, 0, 1 };
ofParameter<float>pi2{ "pi2", 0, 0, 1 };
ofParameter<float>pi3{ "pi3", 0, 0, 1 };
ofParameter<float>pi4{ "pi4", 0, 0, 1 };

// params targets
ofParameter<float>po1{ "po1", 0, 0, 1 };
ofParameter<float>po2{ "po2", 0, 0, 1 };
ofParameter<float>po3{ "po3", 0, 0, 1 };
ofParameter<float>po4{ "po4", 0, 0, 1 };
```

ofApp.cpp
```.c++
// define inputs
patchbay.addParameter(pi1);
patchbay.addParameter(pi2);
patchbay.addParameter(pi3);
patchbay.addParameter(pi4);
patchbay.setupParameters();

// define and name outputs
patchbay.registerControllable1f("po1", [&](float value) {
  po1.set(value);
});
patchbay.registerControllable1f("po2", [&](float value) {
  po2.set(value);
});
patchbay.registerControllable1f("po3", [&](float value) {
  po3.set(value);
});
patchbay.registerControllable1f("po4", [&](float value) {
  po4.set(value);
});

//-

// disconnect
patchbay.disconnectAll();

// connect
patchbay.connect1f("param-1", "po2");
patchbay.connect1f("param-2", "po1");
patchbay.connect1f("param-3", "po4");
patchbay.connect1f("param-4", "po3");
```
  
![image](docs/Capture.PNG?raw=true "image")

---------------------------------

Openframeworks addon that allows you to quickly and easily plug various controllers (MIDI controller, audio, mouse, keyboard) to parameters that you can define in your code.

## Usage

Let's say you want to control the size of a rectangle that you defined somewhere (`ofRectangle rect`). Register a lambda function with the patchbay, giving it a human-readable name. The closure should accept a parameter `value`, which will be a `float` in the range `[0,1]`

```
patchbay.registerControllable1f("rect-size", [&] (float value) {
    rect.setHeight(100 * value);
    rect.setWidth(100 * value);    
});
```

Now you can connect the x-position of the mouse to the registered parameter:

`patchbay.connect1f("mouse-x", "rect-size");`

You can disconnect them like this:

`patchbay.disconnect1f("mouse-x", "rect-size");`

And hook it up to a MIDI controller:

`patchbay.connect1f("midi-cc-10", "rect-size");`

Or even audio:

`patchbay.connect1f("audio-rms", "rect-size");`

## Installation

Define this object in ofApp.h

```
ofxPatchbay patchbay;
```

And add this line to `ofApp::update()`

`patchbay.update();`

## Dependencies

Uses [ofxMidi](https://github.com/danomatika/ofxMidi) for MIDI controller input.
Uses [BlackHole](https://github.com/ExistentialAudio/BlackHole) 16ch as the default Audio input. This can be changed in `ofxAudioInput.h`