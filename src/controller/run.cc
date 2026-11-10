#include "controller.ih"


void Controller::run()
{
    while (d_viewsf.isOpen())
    {
        while (true)
        {
            if (optional<Event> event = d_viewsf.pollEvent())
            {
                handleEvent(*event);
            } else
            {
                break;
            }
            handleKeyPresses();             // live input
        }

        Model::render(d_viewsf.img());
        
        d_viewsf.draw();
    }
}
// main event+render loop
