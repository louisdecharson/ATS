//
//  SmallEqualizer.cpp
//  ATS
//
//  Created by Louis de Charsonville on 22/02/2013.
//
//

#include "SmallEqualizer.h"
SmallEqualizer::SmallEqualizer(){};

void SmallEqualizer::setup(int bufferSize){
    m_nbSubbands2=32;
    myEqualizer.setup(bufferSize);
}

void SmallEqualizer::draw(){
    ofNoFill();
    ofSetColor(0,0,0);
    for (int i=0; i< m_nbSubbands2; i++){
        ofSetColor(255-7*i,0,7*i);
        ofFill();
        if ((myEqualizer.GetSmallSpectrum()[i]<200)&&(myEqualizer.GetSmallSpectrum()[i]>0)){
            ofRect((ofGetScreenWidth()/m_nbSubbands2)*i, 600, (ofGetScreenWidth()/m_nbSubbands2),myEqualizer.GetSmallSpectrum()[i]*-20);
            if (myEqualizer.GetAvBeatVector()[i]>(1.0)){
                ofSetColor(255,255,255);
                ofRect((ofGetScreenWidth()/m_nbSubbands2)*i,600-(myEqualizer.GetAvBeatVector()[i]*20),(ofGetScreenWidth()/m_nbSubbands2),3);
            }
        }
        /* detect sream overflow */
        else{
            ofSetColor(255,255,255);
            ofFill();
            if(i<8){ofRect(1000,700+6*i,5,5);}
            else if((i>7)&&(i<16)){ofRect(1006,700+6*(i-8),5,5);}
            else if ((i>15)&&(i<24)){ofRect(1012,700+6*(i-16),5,5);}
            else if ((i>23)&&(i<32)){ofRect(1018,700+6*(i-24),5,5);}
            else if ((i>31)&&(i<40)){ofRect(1024,700+6*(i-32),5,5);}
            else if ((i>39)&&(i<48)){ofRect(1030,700+6*(i-40),5,5);}
            else if ((i>47)&&(i<56)){ofRect(1036,700+6*(i-48),5,5);}
            else if ((i>55)&&(i<64)){ofRect(1042,700+6*(i-56),5,5);}
        }
    }
}

void SmallEqualizer::audioIn(vector <float> input, int bufferSize, int nChannels){
    myEqualizer.audioIn(input, bufferSize, nChannels);
}

void SmallEqualizer::keyPressed(int key){
    myEqualizer.keyPressed(key);
}

void SmallEqualizer::keyReleased(int key){
    myEqualizer.keyReleased(key);
}