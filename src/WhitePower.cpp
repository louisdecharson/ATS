//
//  WhitePower.cpp
//  ATS
//
//  Created by Louis de Charsonville on 07/03/2013.
//
//

#include "WhitePower.h"

WhitePower::WhitePower(){};

void WhitePower::setup(int bufferSize){
    
    myEqualizer.setup(bufferSize);
    
    initRythm();
    initCompt();
    c_rythmconv=floor(GetRythm()/60);
}

void WhitePower::draw(){
    ofSetColor(255,255,255);
    if (c_auto){
        
        //ofDrawBitmapString("Auto Activated",780,780);
        //ofDrawBitmapString(ofToString(myEqualizer.GetFreqMax()),700,700);
         //ofDrawBitmapString(ofToString(myEqualizer.GetAvBeatVector()[myEqualizer.GetFreqMax()]),700,720);
        
        if ((myEqualizer.GetFreqMax()>0)&&(myEqualizer.GetSpectrum()[myEqualizer.GetFreqMax()]>3*myEqualizer.GetAvBeatVector()[myEqualizer.GetFreqMax()])){
            ofFill();
            ofRect(0,0,1280,800);
        }
    }
    else {
        ofRect(0,0,1280,800);
    }
}

void WhitePower::audioIn(vector <float> input, int bufferSize, int nChannels){
    myEqualizer.audioIn(input, bufferSize, nChannels);
}

void WhitePower::keyPressed(int key){
    myControler.keyPressed(key);
}

void WhitePower::keyReleased(int key){
    myControler.keyReleased(key);
}
