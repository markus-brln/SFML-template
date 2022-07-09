#ifndef VIEW_H
#define VIEW_H

#include <SFML/Graphics.hpp>
#include "../utils/utils.h"
#include "../model/model.h"
#include "../viewsf/viewsf.h"


class Controller
{
    Model &d_model;
    ViewSF &d_viewsf;

    public:
        Controller() = delete;
        Controller(Model &model, ViewSF &viewsf);   // 1.cc

        void run();
        void handleEvent(sf::Event &event);
        void handleKeyPresses();

        sf::Text createText();
};

#endif

