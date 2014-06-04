//
//  BrokenLines.cpp
//  ATS
//
//  Created by Louis de Charsonville on 21/02/2013.
//
//

#include "BrokenLines.h"
BrokenLines::BrokenLines(){};

void BrokenLines::setup(int bufferSize){
    myEqualizer.setup(bufferSize);
    
}

void BrokenLines::draw(){
    for (int i=0; i<myEqualizer.GetSubBands(); i++){
        if (myEqualizer.GetBoolBeat()[i]){
            ofFill();
            ofSetColor(255,255,255);
            ofRect(0,i*10,ofGetScreenWidth(),10);
        }
    }
    
}

void BrokenLines::audioIn(vector <float> input, int bufferSize, int nChannels){
    myEqualizer.audioIn(input, bufferSize,nChannels);
}