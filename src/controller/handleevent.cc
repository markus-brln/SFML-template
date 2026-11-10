#include "controller.ih"

void Controller::handleEvent(sf::Event &event)
{
    // Check for the Window Closed event subtype
    if (event.is<sf::Event::Closed>())
    {
        d_viewsf.close();
    }

    // Check for and extract data from the KeyPressed event subtype
    if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>())
    {
        switch (keyPressed->code)
        {
        case sf::Keyboard::Key::Space:
            // code
            break;

        default:
            break;
        }
    }
}
// for closing and reset, events that should just happen once -> not live input
