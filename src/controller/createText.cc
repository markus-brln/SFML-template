#include "controller.ih"

sf::Text Controller::createText()
{
    // select the font
    sf::Font font;
    if (!font.openFromFile(FONT_PATH))
    {
        throw runtime_error("Could not find the font file in Controller::createText");
    }
    // text.setFont(font); // font is a sf::Font

    sf::Text text(font, "", 10);
    // set the character size
    text.setCharacterSize(10); // in pixels, not points!

    // set the color
    text.setFillColor(sf::Color::Black);

    // set the text style
    //text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    return text;
}

