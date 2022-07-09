#ifndef UTILS_H
#define UTILS_H

#include "../json/json.h"
#include <SFML/Graphics.hpp>
#include <exception>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
using json = nlohmann::json;


extern bool FULL_SCREEN;
extern bool SHOW_FPS;
extern int SIZE_X;
extern int SIZE_Y;
extern string FONT_PATH;
extern size_t FONT_SIZE;
extern sf::Color FONT_COLOR;



void parseConfig(const string &filename = "config.json");

#endif

