/*
 *
 * This file is licenced under the Apache 2.0 
 * https://www.apache.org/licenses/LICENSE-2.0.txt
 *
 * ©2021 Vortetty/Tæmt modʒiɹæ/Winter
 *
 */


#define DEBUG_DRAW false

#include <bitset>
#include <gba_input.h>
#include <vector>
#include "./font.hpp"
#include "./globals.hpp"

#define WHITE 0xffff
#define BLACK 0x0000

struct WindowRenderer {
    bool (*func)(Vector2, Vector2, uint16_t);
    std::string name; 
    uint16_t barColor; 
    uint16_t textColor; 
    bool renderBar; 
};

int main(){
    // ✧ Setup ✧
    // ------------------------------------------------------------------------
    *(unsigned short*)0x04000000 = 0x0403; // Set mode, idk why but only this one works
    font_5x8::init();

    drawNxN(0, 0, 240, 160, BLACK); // Clear Back
    font_5x8::testFullImage(); // Draw the bitmap to the screen
    sleep(5000);

    drawNxN(0, 0, 240, 160, BLACK); // Clear Back
    font_5x8::helloWorld(0, 0); // Draw "Hello World!" at 0, 0
    sleep(2500);

    drawNxN(0, 0, 240, 160, BLACK); // Clear Back
    font_5x8::drawString(0, 0, "Hello, World!\nI was printed on the gba!"); // Draw "Hello, World!\nI was printed on the gba!" at 0, 0
    sleep(2500);

    drawNxN(0, 0, 240, 160, BLACK); // Clear Back
    font_5x8::drawString(0, 0, "Hello, World!\nI was printed on the gba!", 1, false); // Draw "Hello, World!\nI was printed on the gba!" at 0, 0 but don't convert newlines
    sleep(2500);

    drawNxN(0, 0, 240, 160, BLACK); // Clear Back
    font_5x8::drawString(0, 0, "Hello, World! I am here to test the auto-break feature!", 1, false); // Test auto-break
    sleep(2500);

    drawNxN(0, 0, 240, 160, BLACK); // Clear Back
    font_5x8::drawString(0, 0, "Hello, World! I am here to test clipping of text!", 1, false, false); // Test clipping
    sleep(2500);

    drawNxN(0, 0, 240, 160, BLACK); // Clear Back
    font_5x8::testAllChars(); // Test all the characters
    sleep(2500);

    uint8_t page = 0; // Page we are on
    unsigned short keys;
    // ------------------------------------------------------------------------

    // ✧ The game ✧
    // ------------------------------------------------------------------------
    while (true){ // Run until game should exit
        scanKeys(); // Populate keys pressed
        keys = keysDown(); // Gets pressed keys 
        if (isPressed(keys, KEYPAD_BITS::KEY_L)) page--; // if left bumper is pressed decrement page
        if (isPressed(keys, KEYPAD_BITS::KEY_R)) page++; // if right bumper is pressed increment page


    }
    // ------------------------------------------------------------------------

    return 0; // Have to return 0
}
