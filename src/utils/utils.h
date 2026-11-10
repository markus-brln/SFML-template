#ifndef UTILS_H
#define UTILS_H

#include "json.hpp"

#include <SFML/Graphics.hpp>

#include <exception>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
using nlohmann::json;


extern bool FULL_SCREEN;
extern bool SHOW_FPS;
extern sf::Vector2u WINDOW_SIZE;
extern string FONT_PATH;
extern size_t FONT_SIZE;
extern sf::Color FONT_COLOR;



void parseConfig(const string &filename = "assets/config.json");

#endif

