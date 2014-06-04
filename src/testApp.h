#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "Equalizer.h"
#include "BrokenLines.h"
#include "Circles.h"
#include "Matrix.h"
#include "SmallEqualizer.h"
#include "Lines.h"
#include "Controler.h"
#include "WhitePower.h"
#include "ofxSyphon.h"

class testApp : public ofBaseApp{
	
	public:
		
        //  Basic Operations using infinity loops
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
        void keyReleased(int key);
        void audioIn(float * input, int bufferSize, int nChannels);
    
        // sound input vector
        vector <float> m_input;
        int m_classLaunch;
    
        // adding instances of other classes 
        ofSoundStream soundStream;
        Equalizer myEqualizer;
        BrokenLines myBrokenLines;
        Circles myCircles;
        Matrix myMatrix;
        SmallEqualizer mySmallEqualizer;
        Lines myLines;
        Controler myControler;
        WhitePower myWhitePower;
    
        // addons
        ofTexture tex;

        ofxSyphonServer mainOutputSyphonServer;
        ofxSyphonServer individualTextureSyphonServer;
	
        ofxSyphonClient mClient;
    
    
    
    
};

#endif	

