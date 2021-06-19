#ifndef FONT_5x8_HPP
#define FONT_5x8_HPP
    #include "./fontBitmap.hpp"
    #include "./globals.hpp"
    #include <vector>
    #include <variant>
    #include <stdexcept>
    #include <functional>
    #include <cerrno>

    #define colorProvider std::function<color(int,char,bool)>

    namespace font_5x8 {
        std::string author = "Vortetty/Winter"; // The author of the font
        Vector2 charSize = {5, 8}; // Size of the characters
        Vector2 charSizeOnBitmap = {7, 10}; // Size of the characters on the bitmap (if they have padding you would include that here)
        Vector2 bitmapCharsDimensions = {16, 16}; // How many columns and rows

        struct string_draw_return_type {
            Vector2 newPos; // The new position to start drawing
            int drawnChars; // 
        };
        typedef string_draw_return_type string_draw_return;

        colorProvider genSingleColorProvider(color c){
                colorProvider colorGenerator = [c](int index, char character, bool skipSpaces=true){
                    return c;
                };

                return colorGenerator;
        }

        colorProvider genCyclingColorProvider(colorSet c){
                int colorOffset = 0;

                colorProvider colorGenerator = [c, &colorOffset](int index, char character, bool skipSpaces=true){
                    if (character == ' ' && skipSpaces) colorOffset += 1;
                    return c[wrapInt(index-colorOffset, 0, (int)c.size())];
                };

                return colorGenerator;
        }

        // Initialize things that need to be
        void init(){
            initFont();
        }

        // Draw bitmap to the screen for testing
        void testFullImage(){
            for(uint_fast32_t x = 0; x < bitmapDimensions.x; x++){
                for(uint_fast32_t y = 0; y < bitmapDimensions.y && y < 160; y++){
                    setPixel(x, y, fontBitmap[x+y*bitmapDimensions.x] ? 0xffff : 0x0000);
                }
            }
        }

        // Draw a character from the bitmap
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

        // Draw a string on the screen
        string_draw_return drawString(int drawx, int drawy, std::string str, std::function<color(int,char,bool)> fg, std::function<color(int,char,bool)> bg, int charSpacing=1, bool convertNewlines=true, bool autoBreakAtEnd=true, bool skipSpacesWhenChangingFgColor=true, bool skipSpacesWhenChangingBgColor=true){
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
                    drawCharacter(origx, drawy, chr, fg(counter, chr, skipSpacesWhenChangingFgColor), bg(counter, chr, skipSpacesWhenChangingBgColor));
                    drawnChars = 1;
                    counter++;
                } else {
                    drawCharacter(drawx, drawy, chr, fg(counter, chr, skipSpacesWhenChangingFgColor), bg(counter, chr, skipSpacesWhenChangingBgColor));
                    drawNxN(drawx+charSize.x, drawy, charSpacing, charSize.y, bg(counter, chr, skipSpacesWhenChangingBgColor));
                    drawNxN(drawx, drawy+charSize.y, charSize.x+1, charSpacing, bg(counter, chr, skipSpacesWhenChangingBgColor));
                    drawx += charSize.x+charSpacing;
                    drawnChars++;
                    counter++;
                }
            }
            
            return {{drawx, drawy}, drawnChars};
        }

        string_draw_return drawString(int drawx, int drawy, std::string str, std::variant<int, color, colorSet> fg=0xffff, std::variant<int, color, colorSet> bg=0x0000, int charSpacing = 1, bool convertNewlines = true, bool autoBreakAtEnd = true){
            colorProvider fg_func;
            colorProvider bg_func;

            switch (fg.index()){
                case 0:
                    fg_func = genSingleColorProvider(std::get<int>(fg));
                    break;
                case 1:
                    fg_func = genSingleColorProvider(std::get<color>(fg));
                    break;
                case 2:
                    fg_func = genCyclingColorProvider(std::get<colorSet>(fg));
                    break;
                default:
                    #ifdef __cpp_exceptions
                        throw std::invalid_argument("");
                    #else
                        exit(EINVAL);
                    #endif
            }

            switch (bg.index()){
                case 0:
                    bg_func = genSingleColorProvider(std::get<int>(bg));
                    break;
                case 1:
                    bg_func = genSingleColorProvider(std::get<color>(bg));
                    break;
                case 2:
                    bg_func = genCyclingColorProvider(std::get<colorSet>(bg));
                    break;
                default:
                    #ifdef __cpp_exceptions
                        throw std::invalid_argument("");
                    #else
                        exit(EINVAL);
                    #endif
            }

            string_draw_return ret = drawString(drawx, drawy, str, fg_func, bg_func, charSpacing, convertNewlines, autoBreakAtEnd);;
            
            return ret;
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
#endif
