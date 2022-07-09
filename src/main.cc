#include "main.ih"


int main()
{
    parseConfig();

    Model model;                        // MVC pattern
    ViewSF viewsf;
    Controller controller{ model, viewsf };
    
    controller.run();                   // start the window loop

    return 0;
}
