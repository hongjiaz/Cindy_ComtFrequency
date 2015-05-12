//  Created by Andreasmuller in 2015.

#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp
//public class
{
public:
    //public
    
    // --------------------------------
    void setup();
    
    // --------------------------------
    void draw();
    
    // --------------------------------
    void keyPressed( int _key );
    
    ofTrueTypeFont fontSmall;       //hand out fontSmall
};
