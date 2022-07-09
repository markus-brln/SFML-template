#ifndef VIEWSF_H
#define VIEWSF_H

#include <SFML/Graphics.hpp>
#include "../utils/utils.h"


class ViewSF
{
    sf::RenderWindow d_window;
    sf::Font d_font;
    sf::Texture d_texture;
    sf::Sprite d_sprite;
    sf::Image d_img;
    bool d_fullScreen;
    sf::Clock d_clock;                    // for frame rate
    sf::Text d_fpsText;
    bool d_showFps;

    public:
        // constructors
        ViewSF();                             // 1.cc

        // members
        sf::Image &img();
        void draw();
        void resize();

        // sf::RenderWindow wrapped members
        bool isOpen();
        bool pollEvent(sf::Event &event);
        void close();
};
// extendable wrapper for sf::RenderWindow


inline bool ViewSF::isOpen()
{
    return d_window.isOpen();
}


inline bool ViewSF::pollEvent(sf::Event &event)
{
    return d_window.pollEvent(event);
}

inline void ViewSF::close()
{
    d_window.close();
}

#endif
