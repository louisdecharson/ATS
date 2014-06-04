//
//  Circles.h
//  ATS
//
//  Created by Louis de Charsonville on 21/02/2013.
//
//

#ifndef __ATS__Circles__
#define __ATS__Circles__

#include <iostream>
#include "ofMain.h"
#include "Equalizer.h"

class Circles {
public:
    
    // Classic methods
    void setup(int bufferSize);
    void draw();
    void audioIn (vector <float> input, int bufferSize, int nChannels);
    
    void keyPressed(int key);
    void keyReleased(int key);

    Equalizer myEqualizer;
    
    // Constructor
    Circles();

private:
    float radius;
};

#endif /* defined(__ATS__Circles__) */
