#pragma once

#include "ofMain.h"
#include "ofxPro.h"

//  ADDONS
//
#include "ofxTimeline.h"
#include "ofxTLCameraTrack.h"

class ofxTimeline3DPro : public ofx3DPro {
  public:
	   
	ofxTimeline3DPro():timeline(NULL),cameraTrack(NULL),bUseCameraTrack(true),bEnableTimeline(true){};
	virtual ~ofxTimeline3DPro(){};

    //--------------------- VIRTUAL CLASSES TO EDIT
    //
    virtual string getSystemName(){ return "TIMELINE_ABSTRACT_3DPROJECT"; };
    
    virtual void selfSetupTimeline(){};
    virtual void selfSetupTimelineGui(){};
    virtual void selfTimelineGuiEvent(ofxUIEventArgs &e){};
    //---------------------


    // Interface functions
    //
    virtual void play();
	virtual void stop();
    
    ofxTimeline* getTimeline(){return timeline;};
    
	//  These events are registered to be call automatically
    //
	virtual void update(ofEventArgs & args);
	virtual void draw(ofEventArgs & args);
	virtual void exit(ofEventArgs & args);

	virtual void keyPressed(ofKeyEventArgs & args);
    
protected:
    
    //  CORE
    //
    virtual void setupCoreGuis();
    
    virtual void guiAllEvents(ofxUIEventArgs &e);
    virtual void guiLoad();
    virtual void guiLoadPresetFromPath(string presetPath);
    virtual void guiSave();
    virtual void guiSavePreset(string presetName);
    
    virtual void guiShow();
    virtual void guiHide();
    virtual void guiToggle();
    
    virtual bool cursorIsOverGUI();
    
    //  TimeLine
    //
    virtual void setupTimeline();
    virtual void setupTimelineGui();
    virtual void setupTimeLineParams();
    
    virtual void timelineBangEvent(ofxTLBangEventArgs& args);
    virtual void guiTimelineEvent(ofxUIEventArgs &e);
    virtual void setTimelineTrackCreation(bool state);
    virtual void setTimelineTrackDeletion(bool state);
    
    virtual void updateTimelineUIParams();
    virtual void saveTimelineUIMappings(string path);
    virtual void loadTimelineUIMappings(string path);
    
    virtual void resetTimeline();
	virtual void bindWidgetToTimeline(ofxUIWidget* widget);
    virtual void unBindWidgetFromTimeline(ofxUIWidget* widget);
    
    ofxTimeline*        timeline;
    ofxTLCameraTrack*   cameraTrack;
	ofxTLFlags*         introOutroTrack;
    UIReference         tlGui;
	
    map<ofxTLBangs*, ofxUIButton*>          tlButtonMap;
    map<ofxUIToggle*, ofxTLSwitches*>       tlToggleMap;
    map<ofxUISlider*, ofxTLCurves*>         tlSliderMap;
    map<ofxUINumberDialer*, ofxTLCurves*>   tlDialerMap;
    
    float   timelineDuration;
    float   secondsRemaining;
    
	bool    bUseCameraTrack;
    bool    bShowTimeline;
    bool    bEnableTimeline;
    bool    bDeleteTimelineTrack;
    bool    bTimelineIsIndefinite;
    bool    bEnableTimelineTrackCreation;
};
