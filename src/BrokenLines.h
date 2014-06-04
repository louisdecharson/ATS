//
//  BrokenLines.h
//  ATS
//
//  Created by Louis de Charsonville on 21/02/2013.
//
//

#ifndef __ATS__BrokenLines__
#define __ATS__BrokenLines__

#include <iostream>
#include "ofMain.h"
#include "Equalizer.h"

class BrokenLines {
public:
    //   Classic methods
    void setup(int bufferSize);
    void draw();
    void audioIn(vector <float> input, int bufferSize, int nChannels);
    
    Equalizer myEqualizer;
    
    // Constructor
    BrokenLines();
    
    
private:
    
};


#endif /* defined(__ATS__BrokenLines__) */
