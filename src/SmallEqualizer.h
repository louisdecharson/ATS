//
//  SmallEqualizer.h
//  ATS
//
//  Created by Louis de Charsonville on 22/02/2013.
//
//

#ifndef __ATS__SmallEqualizer__
#define __ATS__SmallEqualizer__

#include <iostream>
#include "ofMain.h"
#include "Equalizer.h"

class SmallEqualizer {
    public :
        //   Classic methods
        void setup(int bufferSize);
        void draw();
        void audioIn(vector <float> input, int bufferSize, int nChannels);
    
        void keyPressed(int key);
        void keyReleased(int key);
    
        Equalizer myEqualizer;
    
        //Constructor
        SmallEqualizer();
    
    
    private:
    int m_nbSubbands2;
    
    
};


#endif /* defined(__ATS__SmallEqualizer__) */
