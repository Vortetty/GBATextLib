#include <iostream>
#include <bitset>
#include <fstream>

#define LODEPNG_NO_COMPILE_ZLIB
//#define LODEPNG_NO_COMPILE_DECODER
#define LODEPNG_NO_COMPILE_ENCODER
#define LODEPNG_COMPILE_CPP
#include "./lodepng.h"


int main(int argc, char* argv[]){
    std::string filename = "font.png";

    std::vector<unsigned char> image; //the raw pixels
    unsigned width, height;

    //decode
    unsigned error = lodepng::decode(image, width, height, filename.c_str());

    //if there's an error, display it
    if(error) std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;

    uint32_t data[width*height/32];



    std::ofstream outFile;
    outFile.open("font.hpp");


    outFile << "#include <bitset>\n";
    outFile << "#include \"./globals.hpp\"\n\n";

    outFile << "namespace font {\n";
    outFile << "    Vector2 bitmapDimensions = {" << width << ", " << height << "};\n";
    outFile << "    std::bitset<" << width*height << "> fontBitmap;\n\n";

    outFile << "    void initFont(){\n";
    outFile << "        unsigned long data[" << width*height/32 << "] = {\n";

    outFile << std::hex;
    for (int i = 0; i < width*height/32; i++){ // For this to work the image MUST have at least 1 dimension that is a multiple of 32
        std::bitset<32> tmp = 0;
        for (int x = 0; x < 32; x++){
            tmp[x] = ((image[(i*32+x)*4] == 0 && image[(i*32+x)*4+1] == 0 && image[(i*32+x)*4+2] == 0) ? 1 : 0);
        }
        outFile << "            (unsigned long)0x" << tmp.to_ulong() << ",\n";
    }
    outFile << std::dec;

    outFile << "        };\n\n";
    outFile << "        for (int i = 0; i < " << width*height/32 << "; i++){\n";
    outFile << "            std::bitset<32> tmp(data[i]);\n";
    outFile << "            for (int pos = 0; pos < 32; pos++){\n";
    outFile << "                fontBitmap.set(i*32+pos, tmp[pos]);\n";
    outFile << "            }\n";
    outFile << "        }\n";
    outFile << "    }\n";
    outFile << "}\n";
}