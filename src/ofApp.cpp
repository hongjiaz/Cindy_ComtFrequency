//
//  ofApp.cpp
//  Frequency
//
//  Created by Andreasmuller on 15-4-29.
//
//

#include<ofApp.h>

void ofApp:: setup()
//At the begining of the program, to define the basic code condition.
{
    fontSmall.loadFont("Fonts/DIN.otf", 8 );
    
}

void ofApp::draw()

{
    ofBackgroundGradient( ofColor(55), ofColor(0), OF_GRADIENT_CIRCULAR );
    //background color
    
    ofEnableAlphaBlending();
    
    // As we are feeding values measured in pixels, the frequency value will be pretty small
    float frequency = ofMap( ofGetMouseX(),  0, ofGetWidth(),  0.0001, 0.05 );
    
    // Draw ticks at each unit edge
    int numTicks = ceil(ofGetWidth() * frequency);
    float areaCovered = numTicks;
    //draw the ticks
    if( numTicks <= 5 ) { numTicks *= 10; }
    //the number of ticks
    
    for( int i = 0; i < numTicks; i++ )
        //to put the max and start number
    {
        float noisePos = ofMap( i, 0, numTicks, 0, areaCovered);
        //new define of noise
        float screenX = noisePos * (1.0/frequency);
        //the secreen x
        ofVec2f top( screenX, 0);
        //vector top
        ofVec2f bot( screenX, ofGetHeight());
        //vector bot
        
        // Brighter white lines at unit edges (0,1,2) and less bright at fractionals (0.1,0.2, etc), but only if we are zoomed in enough
        if( (abs(fmodf(noisePos, 1.0)) <= 0) && areaCovered < 18 )  { ofSetColor( ofColor::white, 90 ); } else { ofSetColor( ofColor::white, 30 );  }
        
        ofLine( top, bot);
        //line top and bot
        
        ofVec2f textPos = top + ofVec2f(4,20);
        //vector's position
        fontSmall.drawString( ofToString(noisePos), textPos.x, textPos.y );
        //draw the string
    }
    
    // Compute a noise position for each pixels x position, taking a frequency value into account
    float noiseMagnitude = 300;
    ofMesh mesh;
    //define of mesh
    mesh.setMode( OF_PRIMITIVE_LINE_STRIP );
    //put a new file into the mesh
    int res = ofGetWidth();
    //give a name of width
    for( int i = 0; i < res; i++ )
        //set up the max and min res
    {
        ofVec2f pos = ofVec2f( ofMap( i, 0, res, 0, ofGetWidth() ), ofGetHeight() * 0.5f );
        //vector's position
        
        float noisePos = (pos.x * frequency);
        //define the noise position
        float noiseValue = ofSignedNoise( noisePos ); // ofSignedNoise gives us a value -1..1
        //define noise value
        
        ofVec2f drawPos = pos + ofVec2f(0,noiseValue * noiseMagnitude);
        //draw the position
        
        mesh.addVertex( drawPos );
        //add more vectors
    }
    
    ofSetColor( ofColor::white );
    //set up colors
    mesh.draw();
    //finish the draw
}


void ofApp::keyPressed( int _key )
//Keyboard control setup.
{
    if( _key == ' ' )
    {
    }
}
