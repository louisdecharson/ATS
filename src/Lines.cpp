//
//  Lines.cpp
//  ATS
//
//  Created by Louis de Charsonville on 01/03/2013.
//
//

#include "Lines.h"

Lines::Lines(){};

void Lines::setup(int bufferSize){
    myEqualizer.setup(bufferSize);
    
    c_modulator.assign(64, 0.0);
}

void Lines::audioIn(vector <float> input, int bufferSize, int nChannels){
    myEqualizer.audioIn(input, bufferSize, nChannels);
    
    for (int i=0; i<64; i++){
        c_modulator[i]=myEqualizer.GetSpectrum()[i]*myEqualizer.GetSpectrum()[i]*(0.3*i);
        if (c_modulator[i]>300){
            c_modulator[i]=300;
            if (i>2){
                c_modulator[i-1]=c_modulator[i]*0.7;
                c_modulator[i-2]=c_modulator[i]*0.5;
            }
        }
    }
    
    
}

void Lines::keyPressed(int key){
    myEqualizer.keyPressed(key);
}

void Lines::keyReleased(int key){
    myEqualizer.keyReleased(key);
}

void Lines::draw(){
    
    ofSetColor(255,255,255);
    
    for (int i=0; i<64; i++ ){
        ofSetColor(255,255,255);
        ofNoFill();
        
        ofBeginShape();
        ofVertex(0,400);
        ofVertex(ofGetScreenWidth()/myEqualizer.GetSubBands()*10,400);
        ofEndShape();
        
        if (i&1){
            ofBeginShape();
            ofVertex(ofGetScreenWidth()/myEqualizer.GetSubBands()*(i+10),400);
            ofVertex(ofGetScreenWidth()/myEqualizer.GetSubBands()*(i+0.5+10),400-GetModulator(i));
            ofVertex(ofGetScreenWidth()/myEqualizer.GetSubBands()*(i+11),400);
            ofEndShape();
            
            
             //ofCurve(ofGetScreenWidth()/64*i,200+10*GetModulator(i),ofGetScreenWidth()/64*i,200,ofGetScreenWidth()/64*(i+1),200,ofGetScreenWidth()/64*(i+1),200+10*GetModulator(i));
             
        }
        else {
            
            ofBeginShape();
            ofVertex(ofGetScreenWidth()/myEqualizer.GetSubBands()*(i+10),400);
            ofVertex(ofGetScreenWidth()/myEqualizer.GetSubBands()*(i+10.5),400+GetModulator(i));
            ofVertex(ofGetScreenWidth()/myEqualizer.GetSubBands()*(i+11),400);
            ofEndShape();
            
            
             //ofCurve(ofGetScreenWidth()/64*i,200-10*GetModulator(i),ofGetScreenWidth()/64*i,200,ofGetScreenWidth()/64*(i+1),200,ofGetScreenWidth()/64*(i+1),200-10*GetModulator(i));
             
        }
               
        /*
        ofCurve(ofGetScreenWidth()/64*i,400.0+10*myEqualizer.GetSpectrum()[i],ofGetScreenWidth()/64*i,400.0,ofGetScreenWidth()/64*(i+1),400.0,ofGetScreenWidth()/64*(i+1),400.0+10*myEqualizer.GetSpectrum()[i]);
        */
    }
    /*
     void ofCurve(float x0, float y0, float x1, float y1, float x2, float y2, float x3, float y3)
     Draws a curve from point (x1, y1) to point (x2, y2). The curve is shaped by the two control points (x0,y0) and (x3,y3)
     The tangent to the curve at the start point is parallel to the line between control point one and the end of the curve. 
     The tangent to the curve at the end point is parallel to the line between the start point and control point 2.     
     */
}