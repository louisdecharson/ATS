//
//  Controler.h
//  ATS
//
//  Created by Louis de Charsonville on 04/03/2013.
//
//

#ifndef __ATS__Controler__
#define __ATS__Controler__

#include <iostream>
#include "ofMain.h"


class Controler {
public:
    
    // classic OF methods
    void setup();
    void keyPressed(int key);
    void keyReleased(int key);
    void draw();
    
    // Constructor
    Controler();
    
    // Get methods
    int GetLaunchor(){return c_launchor;};
    float GetSens(){return c_sensitivity;};
    bool GetBoolSens(){return c_boolsens;};
    bool GetControler(){return c_controler;};
    bool GetWP(){return c_WP;};
    
    //initiate
    void initSens(){c_sensitivity=0.0;};
    void initBoolSens(){c_boolsens=false;};
    void initControler(){c_controler=true;};
    void initWP(){c_WP=false;};
    
    //inc/dec methods;
    void incSens(){c_sensitivity+=0.5;};
    void decSens(){if(c_sensitivity >0){c_sensitivity-=0.5;}};

private:
    int c_launchor; // associate a integer to a keypressed by the user
    float c_sensitivity; // control the sensitivity
    bool c_boolsens; // the sensitivity buttons has been (des)activated
    bool c_controler; //draw the controler help    
    bool c_WP; // white Power
   
};
#endif /* defined(__ATS__Controler__) */
