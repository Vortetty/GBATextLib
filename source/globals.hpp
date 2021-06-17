#ifndef globals
#define globals
    #include <math.h>
    #include <climits>
    #include <cstring>
    #include <initializer_list>

    #define color uint16_t
    #define colorSet std::initializer_list<uint16_t>

    unsigned short* videoBuffer = (unsigned short*)0x06000000;
    
    struct Vector2 {
        uint_fast32_t x;
        uint_fast32_t y; 
    };

    int Vec2Int(Vector2 vec2, uint_fast32_t width){ // 2D position to 1d index
        return vec2.x + vec2.y * width;
    }
    uint_fast32_t Vec2Int(uint_fast32_t x, uint_fast32_t y, uint_fast32_t width){ // 2D position to 1d index
        return x + y * width;
    }

    Vector2 int2Vec(uint_fast32_t idx, uint_fast32_t width){ // 1D index to 2D position
        return {
            idx % width,
            idx / width
        };
    }

    unsigned short randint(unsigned short a, unsigned short b){ // Random integer
        float random = ((float) rand()) / (float) RAND_MAX;
        float diff = b - a;
        float r = random * diff;
        return (unsigned short)(a + r);
    }

    unsigned short RGBToColor(unsigned short r, unsigned short g, unsigned short b){ // RGB to gba color
        return b/8*1024 + g/8*32 + r/8;
    }

    unsigned short RGBToColor(int rgb){ // hex to gba color
        unsigned short r = (rgb >> 16) & 0xff;
        unsigned short g = (rgb >> 8) & 0xff;
        unsigned short b = rgb & 0xff;
        return b/8*1024 + g/8*32 + r/8;
    }

    void drawNxN(unsigned short xoffset, unsigned short yoffset, unsigned short width, unsigned short height, unsigned short color){ // Draw a rectangle at position, position is top left corner
        for (unsigned short x = 0; x < width; x++){
            for (unsigned short y = 0; y < height; y++){
                videoBuffer[(xoffset+x)+(yoffset+y)*240] = color;
            }
        }
    }

    void setPixel(unsigned short x, unsigned short y, unsigned short color){ // Set a single pixel
        videoBuffer[x+y*240] = color;
    }

    bool isPressed(unsigned short keys, unsigned short key){ // Check if a key is pressed given a uint16_t containing pressed keys, meant to be used with mgba
        return (keys & key) == key;
    }

    bool inRange(int low, int high, int x) //  https://www.geeksforgeeks.org/how-to-check-whether-a-number-is-in-the-rangea-b-using-one-comparison/
    {
        return (low <= x) && (x <= high);
    }

    int wrapInt(int x, int x_min, int x_max){ // wrap integer around to stay in range, https://stackoverflow.com/a/14416133
        return (((x - x_min) % (x_max - x_min)) + (x_max - x_min)) % (x_max - x_min) + x_min;
    }

    void sleep(uint_fast32_t ms){ // Sleep but in a hacky way since no sleep command exists
        for (int i = 0; i < ms; i++){
            uint_fast64_t goal = 16800;
            uint_fast64_t counter = 0;
            
            while (counter < goal){
                counter += 22;
                asm("");
            }
        }
    }
#endif