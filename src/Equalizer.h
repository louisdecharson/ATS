//
//  equalizer.h
//  ATS
//
//  Created by Louis de Charsonville on 20/02/2013.
//
//

#ifndef __ATS__equalizer__
#define __ATS__equalizer__

#include <iostream>
#include "ofMain.h"
#include "Controler.h"

class Equalizer {
public:
    //   Classic methods
    void setup(int bufferSize);
    void draw();
    void audioIn(vector <float> input, int bufferSize, int nChannels);
    void keyPressed(int key);
    void keyReleased(int key);
    
    // about the counter
    int GetCompt(){return m_compt;};
    void incCompt(){m_compt++;};
    void incCompt(int entier){m_compt+=entier;};
    void ResetCompt(){m_compt =0;};
    
    
    //Inititiate methods
    void InitFreqMax(){m_freqmax=0;};
    
    // Get methods
    float GetAvBeat(){return m_avBeat;};
    void ResetAvBeat(){m_avBeat =0.0;};
    void NormalizeAvBeat(){m_avBeat/=float(43);};
    
    vector <float> GetBoolBeat(){return m_boolBeat;};
    vector <float> GetSpectrum(){return m_spectrum;};
    vector <float> GetSmallSpectrum(){return m_smallSpectrum;};
    vector <float> GetAvBeatVector(){return m_avBeatVector;};
    int GetSubBands (){return m_nbSubbands;};
    int GetFreqMax(){return m_freqmax;};
    
    Controler myControler;
    
    //   Constructor
    Equalizer();    
    
private:
    vector <float> m_left; // left sound intensity
    vector <float> m_right; // right sound intensity
    int m_nbSubbands; // number of subbands
    int m_compt; // 
    vector <int> m_comptFreq; // used for the indexation of the 1024 frequencies in 64 subbands
    vector <float> m_spectrum; // 64-subbands spectrum
    vector <float> m_smallSpectrum; // 32-subbands spectrum
    vector <vector<float> > m_beatHistory; // energy of frequency i in sample j
    vector <float> m_fillVector; // used to fill the above matrix
    float m_avBeat; // mean of frequency energy
    vector <float> m_avBeatVector; // vector of mean of frequency energy
    vector <float> m_boolBeat; // boolean vector detecting a beat in subbands
    int m_freqmax; // frequency where the maximum energy is detected during the last minute;
    
};



#endif /* defined(__ATS__equalizer__) */
