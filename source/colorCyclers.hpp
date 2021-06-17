#ifndef colorCyclers
#define colorCyclers
    #include "./globals.hpp"
    #include <vector>

    std::vector<color> rainbowColorSet = {RGBToColor(0xff0000), 
                                          RGBToColor(0xff7f00), 
                                          RGBToColor(0xffff00), 
                                          RGBToColor(0x00ff00), 
                                          RGBToColor(0x0000ff), 
                                          RGBToColor(0x4b0082), 
                                          RGBToColor(0x9400d3)};

    int rainbowOffset = 0;

    color rainbowGenerator(int index, char character){
        if (character == ' ') rainbowOffset += 1;
        return rainbowColorSet[wrapInt(index-rainbowOffset, 0, 7)];
    }

    color allBlackGenerator(int index, char character){
        return 0x0000;
    }
#endif