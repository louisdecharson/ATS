//
//  Controler.cpp
//  ATS
//
//  Created by Louis de Charsonville on 04/03/2013.
//
//

#include "Controler.h"

Controler::Controler(){};

void Controler::setup(){
    initSens();
    initBoolSens();
    initControler();
    initWP();
}

void Controler::draw(){
    ofDrawBitmapString(ofToString(ofGetHeight()), 300, 300);
    ofDrawBitmapString(ofToString(ofGetWidth()), 200, 300);

    ofDrawBitmapString("Controler",10,620);
    ofDrawBitmapString("----------",10,630);
    ofDrawBitmapString("Quit controler : x",10, 640);
    ofDrawBitmapString("Launch controler : w",10, 660);
    ofDrawBitmapString("Press 'e' for the equalizer (64)",200,640);
    ofDrawBitmapString("Press 's' for the small equalizer (32)",200,660);
    ofDrawBitmapString("Press 'l' for the broken lines effect",200,680);
    ofDrawBitmapString("Press 'b' for the horizontal lines effects",200,700);
    ofDrawBitmapString("Press 'c' for the circle effects",200,720);
    ofDrawBitmapString("Press 'm' for the matrix effect",200,740);
    ofDrawBitmapString("Press 'v(p)' for the (auto) white power",200,760);
    ofDrawBitmapString("Press 'a' to increase sensitivity",800,640);
    ofDrawBitmapString("Press 'q' to decrease sensitivity",800,660);

}

void Controler::keyPressed(int key){
    if( key == 'e' ){ // equalizer
		c_launchor=1;
	}
    if (key== 'b'){ // broken lines
        c_launchor=2;
    }
    if (key== 'c'){ // circles
        c_launchor=3;
    }
    if (key== 'm'){ // matrix
        c_launchor=4;
    }
    if (key == 's'){ // small equalizer
        c_launchor=5;
    }
    if (key=='l'){ //lines
        c_launchor=6;
    }
    if (key=='p'){ //auto White Power
        c_launchor=7;
    }
    if (key=='a'){ //increase sensitivity
        c_boolsens=true;
        incSens();
    }
    if (key=='q'){ //decrease sensitivity
        c_boolsens=true;
        decSens();
    }
    if (key=='x'){
        c_controler=false;
    }
    if (key=='w'){
        c_controler=true;
    }
    if (key=='v'){ // replace v by scape
        c_WP=true;
    }
}

void Controler::keyReleased(int key){
    if (key=='a'){ //increase sensitivity
        c_boolsens=false;
    }
    if (key=='q'){ //increase sensitivity
        c_boolsens=false;
    }
    if (key=='v'){ // replace v by scape
        c_WP=false;
    }
}



