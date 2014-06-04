//
//  equalizer.cpp
//  ATS
//
//  Created by Louis de Charsonville on 20/02/2013.
//
//

#include "Equalizer.h"
#include "complex.h"
#include "fft.h"
Equalizer::Equalizer(){};

void Equalizer::setup(int bufferSize){
    m_nbSubbands=64;

    //initialisation of attributes
    m_left.assign(bufferSize, 0.0);
    m_right.assign(bufferSize,0.0);
    m_spectrum.assign(m_nbSubbands,0.0);
    m_smallSpectrum.assign(m_nbSubbands/2,0.0);
    m_boolBeat.assign(m_nbSubbands,false);
    m_avBeatVector.assign(m_nbSubbands,0.0);
    
    //initialisation of matrix
    m_fillVector.assign(43,0.0);
    for (int i=0; i<m_nbSubbands; i++){
        m_beatHistory.push_back(m_fillVector);
    }
    
    //indexation of frequencies in subbands
    m_comptFreq.assign(65,0);
    for (int i=2; i<15; i++){
        for (int j=0; j<5; j++){
            m_comptFreq[5*(i-2)+j]=i;
        }
    }
    
    //initiate of some attributes
    InitFreqMax();
    
    //setup du controler
    myControler.setup();
    

}

void Equalizer::audioIn(vector <float> input, int bufferSize, int nChannels){
    complex *pSignal = new complex[bufferSize];
    
    for (int i= 0; i < bufferSize; i++){
        m_left[i]= input[i*2]*0.5;
        m_right[i]=input[i*2+1]*0.5;
        pSignal[i]= complex(m_left[i], m_right[i]);
    }
    
    // Spectrum
    
    float *pInstantEnergy = new float[m_nbSubbands];
    float *pAmplitude = new float[bufferSize];
    
    CFFT::Forward(pSignal, bufferSize); // Cooley-Tucker Algorithm
    
    for (int i=0; i<bufferSize; i++){
        pAmplitude[i]=((pSignal[i].re())*(pSignal[i].re()))+((pSignal[i].im())*(pSignal[i].im()));
    }
    
    // Energy
    ResetCompt();
    for (int j=0; j<m_nbSubbands; j++){
        for (int i=0; i<m_comptFreq[j]; i++){
            pInstantEnergy[j]=pAmplitude[GetCompt()+i]+pAmplitude[bufferSize-GetCompt()-i];
        }
        incCompt(m_comptFreq[j]);
        pInstantEnergy[j]*=float(m_nbSubbands)/float(bufferSize);
        m_spectrum[j]=pInstantEnergy[j]*(myControler.GetSens()+1);
    }

    
    delete[] pSignal;
    delete[] pInstantEnergy;
    delete[] pAmplitude;
    
    // mise à jour du vecteur beathistory & more
    for (int i=0; i<m_nbSubbands; i++){
        ResetAvBeat();
        for(int j=0; j<43; j++){
            m_avBeat+=m_beatHistory[i][j];
        }
        NormalizeAvBeat();
        
        //frequency maximum
        if ((i>10)&&(i<20)) {  // we focus on low-frequency to detect beat
            if (GetAvBeat()>m_freqmax){
            m_freqmax=i;
            }
        }
        //beat history
        for (int j=42; j>0; j--){
            m_beatHistory[i][j]=m_beatHistory[i][j-1];
        }
        m_beatHistory[i][0]=m_spectrum[i];
        
        //average beat
        m_avBeatVector[i]=GetAvBeat();
        
        //boolbeat
        if (m_spectrum[i]>10*GetAvBeat()){
            m_boolBeat[i]=true;
        }
        else{m_boolBeat[i]=false;}
    }
    
    //Small Equalizer
    for (int i=0; i<(m_nbSubbands/2-1); i++){
        m_smallSpectrum[i]=m_spectrum[i];
    }
    ResetCompt();
    for (int i=(m_nbSubbands/2-1); i<m_nbSubbands; i++){
        incCompt(m_spectrum[i]);
    }
    m_smallSpectrum[(m_nbSubbands/2-1)]=GetCompt();
}

void Equalizer::draw(){
    ofNoFill();
    ofSetColor(0,0,0);
    for (int i=0; i< m_nbSubbands; i++){
        ofSetColor(255-7*i,0,7*i);
        ofFill();
        if ((m_spectrum[i]<200)&&(m_spectrum[i]>0)){ //avoid exhuberant values
            ofRect((ofGetScreenWidth()/m_nbSubbands)*(i+10), 600, (ofGetScreenWidth()/m_nbSubbands),m_spectrum[i]*-20);
            if (GetAvBeatVector()[i]>1.0){ 
                ofSetColor(255,255,255);
                ofRect((ofGetScreenWidth()/m_nbSubbands)*(i+10),600-(GetAvBeatVector()[i]*20),(ofGetScreenWidth()/m_nbSubbands),3);
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
void Equalizer::keyPressed(int key){
    myControler.keyPressed(key);
}

void Equalizer::keyReleased(int key){
    myControler.keyReleased(key);
}
