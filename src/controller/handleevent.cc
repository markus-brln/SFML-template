#include "controller.ih"


void Controller::handleEvent(Event &event)
{
    if (event.type == sf::Event::Closed)
        d_viewsf.close();

    if (event.type == sf::Event::EventType::KeyPressed)
    {
        switch (event.key.code)
        {
        case (sf::Keyboard::Space):                 
            // code
            break;

        default:
            break;
        }
    }
}
// for closing and reset, events that should just happen once -> not live input

