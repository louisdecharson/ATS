//
//  Matrix.cpp
//  ATS
//
//  Created by Louis de Charsonville on 21/02/2013.
//
//

#include "Matrix.h"
#include <stdlib.h> 

Matrix::Matrix() {};

void Matrix::setup(int bufferSize){
    myEqualizer.setup(bufferSize);
    m_fillVector.assign(40, false);
    for (int i=0; i<64; i++){
        m_Black.push_back(m_fillVector);
        m_White.push_back(m_fillVector);
    }
    
}

void Matrix::draw(){
    for (int i=0; i<64; i++){
        for (int j=40; j>-1; j--){
            if (j==0){
                if (floor(rand()%10)>6){
                    m_Black[i][0]=true;
                    m_White[i][0]=false;
                    ofSetColor(0,0,0);
                }
                else{
                    m_Black[i][0]=false;
                    m_White[i][0]=false;
                    ofSetColor(0,255,0);
                }
            }
            else{
                if (m_Black[i][j-1]){
                    m_Black[i][j]=true;
                    m_White[i][j]=false;
                    ofSetColor(0,0,0);
                }
                else if (m_Black[i][j]){
                    m_White[i][j]=true;
                    m_Black[i][j]=false;
                    ofSetColor(255,255,255);
                }
                else if (0==0){
                    ofSetColor(0,255,0);
                    m_White[i][j]=false;
                    m_Black[i][j]=false;
                
                }
            }
            ofDrawBitmapString(ofToString(floor(rand()%10)),10+20*i,10+20*j);
        }
    }
}

void Matrix::audioIn(vector <float> input, int bufferSize, int nChannels){
}