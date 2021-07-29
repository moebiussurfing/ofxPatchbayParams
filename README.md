# ofxPatchbay

This is modified version by **moebiusSurfing** from https://github.com/e7mac/ofxPatchbay.  

* Removed all input controllers (keys, mouse and MIDI).  
* Added new ```ofParameter<float>``` controller.  
* A simplified API.

Thanks @**e7mac**!  

### Example Code:

ofApp.h
```.c++
ofxPatchbay patchbay;

// controllers
ofParameter<float>pController0{ "pController0", 0, 0, 1 };
ofParameter<float>pController1{ "pController1", 0, 0, 1 };
ofParameter<float>pController2{ "pController2", 0, 0, 1 };
ofParameter<float>pController3{ "pController3", 0, 0, 1 };

// targets
ofParameter<float>pTarget0{ "pTarget0", 0, 0, 1 };
ofParameter<float>pTarget1{ "pTarget1", 0, 0, 1 };
ofParameter<float>pTarget2{ "pTarget2", 0, 0, 1 };
ofParameter<float>pTarget3{ "pTarget3", 0, 0, 1 };
```

ofApp.cpp
```.c++
// controllers
gControllers.add(pController0);
gControllers.add(pController1);
gControllers.add(pController2);
gControllers.add(pController3);

// targets
gTargets.add(pTarget0);
gTargets.add(pTarget1);
gTargets.add(pTarget2);
gTargets.add(pTarget3);

// define controllers
patchbay.addController(pController0);
patchbay.addController(pController1);
patchbay.addController(pController2);
patchbay.addController(pController3);

// define targets
patchbay.addTarget(pTarget0);
patchbay.addTarget(pTarget1);
patchbay.addTarget(pTarget2);
patchbay.addTarget(pTarget3);

// initialize
patchbay.setupParameters();

//-

// disconnect
patchbay.disconnectAll();	

// connect
patchbay.link(0, 3);
patchbay.link(1, 1);
patchbay.link(2, 2);
patchbay.link(3, 0);
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
