#include "testApp.h"
const int width = 1280;
const int height = 800;

//--------------------------------------------------------------
void testApp::setup(){	 
	
	ofSetVerticalSync(true);
	ofSetCircleResolution(80);
    //ofSetFullscreen(1);
	ofBackground(0, 0, 0);
	
	// 0 output channels, 
	// 2 input channels
	// 44100 samples per second
	// 1024 samples per buffer
	// 4 num buffers (latency)
	
	soundStream.listDevices();
	
	
	int const bufferSize = 1024;
	
	m_input.assign(bufferSize*2, 0.0);
	

	soundStream.setup(this, 0, 2, 44100, bufferSize, 43); /*bool ofSoundStream::setup(ofBaseApp *app, int outChannels, int inChannels, int sampleRate, int bufferSize, int nBuffers) */
    
    // Class setup
    myEqualizer.setup(bufferSize);
    myBrokenLines.setup(bufferSize);
    myCircles.setup(bufferSize);
    myMatrix.setup(bufferSize);
    mySmallEqualizer.setup(bufferSize);
    myLines.setup(bufferSize);
    myControler.setup();
    myWhitePower.setup(bufferSize);
    
    // addons setup
    tex.allocate(width, height, GL_RGBA);

    mainOutputSyphonServer.setName("Screen Output");
	individualTextureSyphonServer.setName("Texture Output");
    
	mClient.setup();
    
    mClient.setApplicationName("Simple Server");
    mClient.setServerName("");
}

//--------------------------------------------------------------
void testApp::update(){
	}

//--------------------------------------------------------------
void testApp::draw(){
    
    if (myControler.GetLaunchor()==1){
        myEqualizer.draw();
        myWhitePower.FalseAuto();
    }
    else if (myControler.GetLaunchor()==2 ){
        myBrokenLines.draw();
        myWhitePower.FalseAuto();
    }
    else if (myControler.GetLaunchor() == 3){
        myCircles.draw();
        myWhitePower.FalseAuto();
    }
    else if (myControler.GetLaunchor()==4){
        myMatrix.draw();
        myWhitePower.FalseAuto();
    }
    else if (myControler.GetLaunchor()==5){
        mySmallEqualizer.draw();
        myWhitePower.FalseAuto();
    }
    else if (myControler.GetLaunchor()==6){
        myWhitePower.FalseAuto();
        myLines.draw();
    }
    else if (myControler.GetLaunchor()==7){
        myWhitePower.TrueAuto();
        myWhitePower.draw();
        
    }
    
    if (myControler.GetBoolSens()){
        ofSetColor(255,255,255);
        if (myControler.GetSens()>=0){
            ofDrawBitmapString("+"+ofToString(myControler.GetSens()),1200,100);
        }
        else{
            ofDrawBitmapString(ofToString(myControler.GetSens()),1200,100);
        }
    }
    if (myControler.GetControler()){
        ofSetColor(255,255,255);
        myControler.draw();
    }
    if (myControler.GetWP()){
        myWhitePower.draw();
    }
    
    // Syphon
    ofSetColor(255, 255, 255);
    ofEnableAlphaBlending();
    mClient.draw(50, 50);
    mainOutputSyphonServer.publishScreen();
    
    individualTextureSyphonServer.publishTexture(&tex);
}

//--------------------------------------------------------------
void testApp::audioIn(float * input, int bufferSize, int nChannels){	

	for (int i = 0; i < bufferSize*2; i++){
        m_input[i]=input[i];
	}
    mySmallEqualizer.audioIn(m_input,bufferSize,nChannels);
    myBrokenLines.audioIn(m_input,bufferSize,nChannels);
    myEqualizer.audioIn(m_input,bufferSize, nChannels);
    myCircles.audioIn(m_input,bufferSize,nChannels);
    myLines.audioIn(m_input,bufferSize,nChannels);
    myWhitePower.audioIn(m_input, bufferSize, nChannels);
    //myMatrix.audioIn(m_input, bufferSize, nChannels);
    
	
	
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
    
    myControler.keyPressed(key);
    myEqualizer.keyPressed(key);
    myWhitePower.keyPressed(key);
    myLines.keyPressed(key);
    mySmallEqualizer.keyPressed(key);
    myCircles.keyPressed(key);
	}

//--------------------------------------------------------------

void testApp::keyReleased(int key){
    myControler.keyReleased(key);
    myEqualizer.keyReleased(key);
    myWhitePower.keyReleased(key);
    myLines.keyReleased(key);
    mySmallEqualizer.keyReleased(key);
    myCircles.keyReleased(key);

}
