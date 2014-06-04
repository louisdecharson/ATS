//
//  Lines.h
//  ATS
//
//  Created by Louis de Charsonville on 01/03/2013.
//
//

#ifndef __ATS__Lines__
#define __ATS__Lines__
#include <iostream>
#include "ofMain.h"
#include "Equalizer.h"

class Lines {

public:
    
    // Classic OF methods
    void setup(int bufferSize);
    void draw();
    void audioIn(vector <float> input, int bufferSize, int nChannels);
    
    void keyPressed(int key);
    void keyReleased(int key);
    
    //Specific methods
    float  GetModulator(int indice){return c_modulator[indice];};
    
    Equalizer myEqualizer;
    
    // Constructor
    Lines ();
    
private:
    vector <float> c_modulator; // améliore le rendu visuel en modulant l'intensité du spectre
    
    
};

#endif /* defined(__ATS__Lines__) */
