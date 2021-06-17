#include "./fontBitmap.hpp"
#include "./globals.hpp"
#include <vector>

namespace font_5x8 {
    std::string author = "Vortetty/Winter";
    Vector2 charSize = {5, 8};
    Vector2 charSizeOnBitmap = {7, 10};

    struct string_draw_return {
        Vector2 newPos;
        int drawnChars;
    };

    void init(){
        initFont();
    }

    void testFullImage(){
        for(uint_fast32_t x = 0; x < bitmapDimensions.x; x++){
            for(uint_fast32_t y = 0; y < bitmapDimensions.y && y < 160; y++){
                setPixel(x, y, fontBitmap[x+y*bitmapDimensions.x] ? 0xffff : 0x0000);
            }
        }
    }

    void drawCharacter(int drawx, int drawy, uint8_t c, color fg=0xffff, color bg=0x0000){
        Vector2 pos = int2Vec(c, 16);

        for (int x = 0; x < charSize.x; x++){
            for (int y = 0; y < charSize.y; y++){
                if (inRange(0, 240-1, drawx+x) && inRange(0, 160-1, drawy+y)){
                    setPixel(drawx+x, drawy+y, fontBitmap[
                        Vec2Int(
                            (x+1) + pos.x*charSizeOnBitmap.x,
                            (y+1) + pos.y*charSizeOnBitmap.y,
                            bitmapDimensions.x
                        )
                    ] ? fg : bg);
                }
            }
        }
    }

    string_draw_return drawString(int drawx, int drawy, std::string str, color fg=0xffff, color bg=0x0000, int charSpacing = 1, bool convertNewlines = true, bool autoBreakAtEnd = true){
        int origx = drawx;
        int drawnChars = 0;
        for (auto &chr : str){
            if (chr == '\n' && convertNewlines){
                drawy += charSize.y + charSpacing;
                drawx = origx;
                drawnChars = 0;
            } else if (drawnChars >= (std::floor(240.0/(charSize.x+charSpacing))) && autoBreakAtEnd){
                drawy += charSize.y + charSpacing;
                drawx = origx + charSize.x+charSpacing;
                drawCharacter(origx, drawy, chr, fg, bg);
                drawnChars = 1;
            } else {
                drawCharacter(drawx, drawy, chr, fg, bg);
                drawNxN(drawx+charSize.x, drawy, charSpacing, charSize.y, bg);
                drawNxN(drawx, drawy+charSize.y, charSize.x+1, charSpacing, bg);
                drawx += charSize.x+charSpacing;
                drawnChars++;
            }
        }

        return {{drawx, drawy}, drawnChars};
    }

    string_draw_return drawString(int drawx, int drawy, std::string str, std::vector<color> fg, std::vector<color> bg, int charSpacing = 1, bool convertNewlines = true, bool autoBreakAtEnd = true){
        int origx = drawx;
        int drawnChars = 0;
        int counter = 0;
        for (auto &chr : str){
            if (chr == '\n' && convertNewlines){
                drawy += charSize.y + charSpacing;
                drawx = origx;
                drawnChars = 0;
            } else if (drawnChars >= (std::floor(240.0/(charSize.x+charSpacing))) && autoBreakAtEnd){
                drawy += charSize.y + charSpacing;
                drawx = origx + charSize.x+charSpacing;
                drawCharacter(origx, drawy, chr, fg[counter], bg[counter]);
                drawnChars = 1;
                counter++;
            } else {
                drawCharacter(drawx, drawy, chr, fg[counter], bg[counter]);
                drawNxN(drawx+charSize.x, drawy, charSpacing, charSize.y, bg[counter]);
                drawNxN(drawx, drawy+charSize.y, charSize.x+1, charSpacing, bg[counter]);
                drawx += charSize.x+charSpacing;
                drawnChars++;
                counter++;
            }
        }
        
        return {{drawx, drawy}, drawnChars};
    }

    string_draw_return drawString(int drawx, int drawy, std::string str, color(*fg)(int,char), color(*bg)(int,char), int charSpacing = 1, bool convertNewlines = true, bool autoBreakAtEnd = true){
        int origx = drawx;
        int drawnChars = 0;
        int counter = 0;
        for (auto &chr : str){
            if (chr == '\n' && convertNewlines){
                drawy += charSize.y + charSpacing;
                drawx = origx;
                drawnChars = 0;
            } else if (drawnChars >= (std::floor(240.0/(charSize.x+charSpacing))) && autoBreakAtEnd){
                drawy += charSize.y + charSpacing;
                drawx = origx + charSize.x+charSpacing;
                drawCharacter(origx, drawy, chr, fg(counter, chr), bg(counter, chr));
                drawnChars = 1;
                counter++;
            } else {
                drawCharacter(drawx, drawy, chr, fg(counter, chr), bg(counter, chr));
                drawNxN(drawx+charSize.x, drawy, charSpacing, charSize.y, bg(counter, chr));
                drawNxN(drawx, drawy+charSize.y, charSize.x+1, charSpacing, bg(counter, chr));
                drawx += charSize.x+charSpacing;
                drawnChars++;
                counter++;
            }
        }
        
        return {{drawx, drawy}, drawnChars};
    }

    void testAllChars(bool convertNewlines = false, color fg=0xffff, color bg=0x0000){
        std::string str = "";
        for (int i = 0; i < 256; i++){
            str.append({(char)i});
        }
        drawString(0, 0, str, fg, bg, 1, convertNewlines);
    }

    void helloWorld(int x, int y){
        drawCharacter(6*0, 0, 'H');
        drawCharacter(6*1, 0, 'e');
        drawCharacter(6*2, 0, 'l');
        drawCharacter(6*3, 0, 'l');
        drawCharacter(6*4, 0, 'o');
        drawCharacter(6*5, 0, ' ');
        drawCharacter(6*6, 0, 'W');
        drawCharacter(6*7, 0, 'o');
        drawCharacter(6*8, 0, 'r');
        drawCharacter(6*9, 0, 'l');
        drawCharacter(6*10, 0, 'd');
        drawCharacter(6*11, 0, '!');
    }
}