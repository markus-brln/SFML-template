#include "controller.ih"


void Controller::run()
{
    Event event;

    while (d_viewsf.isOpen())
    {
        while (d_viewsf.pollEvent(event))
            handleEvent(event);         // closing, reset (single events between renders)
        handleKeyPresses();             // live input
        // cout << "E " << d_viewsf.img().getSize().x << '\n';
        d_viewsf.resize();
        // cout << d_viewsf.img().getSize().x << '\n';
        d_model.render(d_viewsf.img()); //
        
        d_viewsf.draw();
    }
}
// main event+render loop
