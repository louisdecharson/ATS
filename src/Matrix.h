//
//  Matrix.h
//  ATS
//
//  Created by Louis de Charsonville on 21/02/2013.
//
//

#ifndef __ATS__Matrix__
#define __ATS__Matrix__

#include <iostream>
#include "ofMain.h"
#include "Equalizer.h"
#include "Controler.h"

class Matrix {
    public:
        void setup(int bufferSize);
        void draw();
        void audioIn(vector <float> input, int bufferSize, int nChannels);
    
    vector <vector<bool> >  GetIsBlack(){return m_Black;};
    vector <vector<bool> >  GetIsWhite(){return m_White;};
    
    Matrix();
    Equalizer myEqualizer;
    
    private:
    vector <vector<bool> >  m_Black;
    vector <vector<bool> >  m_White;
    vector <bool> m_fillVector;
};

#endif /* defined(__ATS__Matrix__) */
