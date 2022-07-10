#include "controller.ih"


void Controller::run()
{
    Event event;

    while (d_viewsf.isOpen())
    {
        while (d_viewsf.pollEvent(event))
            handleEvent(event);         // closing, reset (single events between renders)
        handleKeyPresses();             // live input

        d_model.render(d_viewsf.img()); //
        
        d_viewsf.draw();
    }
}
// main event+render loop
