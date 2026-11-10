#include "utils.h"

bool FULL_SCREEN = false;
bool SHOW_FPS = true;
sf::Vector2u WINDOW_SIZE(1000, 1000);
string FONT_PATH;
size_t FONT_SIZE = 10;
sf::Color FONT_COLOR = sf::Color::White;


void parseConfig(const string &filename)
{
    ifstream infile{ filename };

    if (!infile) 
        throw runtime_error("Could not open input file for reading.");

    json json_data = json::parse(infile);

    FULL_SCREEN = json_data["FULL_SCREEN"];
    SHOW_FPS = json_data["SHOW_FPS"];
    WINDOW_SIZE.x = json_data["SIZE_X"];
    WINDOW_SIZE.y = json_data["SIZE_Y"];
    FONT_PATH = json_data["FONT_PATH"];
    FONT_SIZE = json_data["FONT_SIZE"];
    unsigned int color = json_data["FONT_COLOR"];  // 32 bit, so white RGBA == ffffffff == 4294967295
    FONT_COLOR =  sf::Color{ color };

    cout << "Json file data" << json_data.dump(4) << endl;
}
