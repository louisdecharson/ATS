//
//  Circles.cpp
//  ATS
//
//  Created by Louis de Charsonville on 21/02/2013.
//
//

#include "Circles.h"
#include "math.h"

Circles::Circles(){};

void Circles::setup(int bufferSize){
    myEqualizer.setup(bufferSize);
}

void Circles::draw(){
    for (int i =0; i<myEqualizer.GetSubBands(); i++){
        //ofSetColor(255/(1+floor(myEqualizer.GetSpectrum()[i])),255/(1+floor(myEqualizer.GetSpectrum()[i])),255);
        //ofSetColor(floor(rand()*255),floor(rand()*255),floor(rand()*255));
        ofSetColor(255,255,255);
        ofFill();
        if(i<8){ofCircle(80+160*i,50,20+myEqualizer.GetSpectrum()[i]*5);}
        else if((i>7)&&(i<16)){ofCircle(80+160*(i-8),150,20+myEqualizer.GetSpectrum()[i]*5);}
        else if ((i>15)&&(i<24)){ofCircle(80+160*(i-16),250,20+myEqualizer.GetSpectrum()[i]*5);}
        else if ((i>23)&&(i<32)){ofCircle(80+160*(i-24),350,20+myEqualizer.GetSpectrum()[i]*5);}
        else if ((i>31)&&(i<40)){ofCircle(80+160*(i-32),450,20+myEqualizer.GetSpectrum()[i-32]*5);}
        else if ((i>39)&&(i<48)){ofCircle(80+160*(i-40),550,20+myEqualizer.GetSpectrum()[i-36]*5);}
        else if ((i>47)&&(i<56)){ofCircle(80+160*(i-48),650,20+myEqualizer.GetSpectrum()[i-45]*5);}
        else if ((i>55)&&(i<64)){ofCircle(80+160*(i-56),750,20+myEqualizer.GetSpectrum()[i-23]*5);}
    }
}

void Circles::audioIn(vector <float> input, int bufferSize, int nChannels){
    myEqualizer.audioIn(input, bufferSize, nChannels);
}

void Circles::keyPressed(int key){
    myEqualizer.keyPressed(key);
}
void Circles::keyReleased(int key){
    myEqualizer.keyReleased(key);
}