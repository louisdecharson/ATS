//
//  WhitePower.h
//  ATS
//
//  Created by Louis de Charsonville on 07/03/2013.
//
//

#ifndef __ATS__WhitePower__
#define __ATS__WhitePower__

#include <iostream>
#include "ofMain.h"
#include "Equalizer.h"
#include "Controler.h"

class WhitePower {
public:
    //Classic OF methods
    void setup(int bufferSize);
    void draw();
    void audioIn(vector <float> input, int bufferSize, int nChannels);
    void keyPressed(int key);
    void keyReleased(int key);
    
    //Constructor
    
    WhitePower();
    
    Equalizer myEqualizer;
    Controler myControler;

    // Get methods
    int GetRythm(){return c_rythm;};
    bool GetAuto(){return c_auto;};
    
    //Initiate methods
    void initRythm(){c_rythm=120;};
    void initCompt(){c_compt=0;};
    void TrueAuto(){c_auto=true;};
    void FalseAuto(){c_auto=false;};
    
    //Inc methods
    void incRythm(){c_rythm+=1;};
    void incCompt(){c_compt++;};
    
private:
    
    int c_rythm;
    bool c_auto;
    int c_compt;
    int c_rythmconv;
    vector <int> c_WPVector; //(when auto activated) vector with compt value when WP should be activated according to Rythm
    
    
    
};

#endif /* defined(__ATS__WhitePower__) */
