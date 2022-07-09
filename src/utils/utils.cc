#include "utils.h"

bool FULL_SCREEN = false;
bool SHOW_FPS = true;
int SIZE_X = 1000;
int SIZE_Y = 1000;
string FONT_PATH = "";
size_t FONT_SIZE = 10;
sf::Color FONT_COLOR = sf::Color::White;


void parseConfig(const string &filename)
{
    ifstream infile{ filename };

    if (!infile) 
        throw runtime_error("Could not open input file for reading.");

    json jsonscene;
    infile >> jsonscene;

    FULL_SCREEN = jsonscene["FULL_SCREEN"];
    SHOW_FPS = jsonscene["SHOW_FPS"];
    SIZE_X = jsonscene["SIZE_X"];
    SIZE_Y = jsonscene["SIZE_Y"];
    FONT_PATH = jsonscene["FONT_PATH"];
    FONT_SIZE = jsonscene["FONT_SIZE"];
    unsigned int color = jsonscene["FONT_COLOR"];  // 32 bit, so white RGBA == ffffffff == 4294967295
    FONT_COLOR =  sf::Color{ color };
}