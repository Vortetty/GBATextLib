#ifndef colorCyclers
#define colorCyclers
    #include "./globals.hpp"
    #include <vector>
    #include "./font.hpp"

    std::vector<color> rainbowColorSet = {RGBToColor(0xff0000), 
                                          RGBToColor(0xff7f00), 
                                          RGBToColor(0xffff00), 
                                          RGBToColor(0x00ff00), 
                                          RGBToColor(0x0000ff), 
                                          RGBToColor(0x4b0082), 
                                          RGBToColor(0x9400d3)};

    colorProvider rainbowGenerator = font_5x8::genCyclingColorProvider(rainbowColorSet);
    colorProvider allBlackGenerator = font_5x8::genSingleColorProvider(0x0000);
#endif