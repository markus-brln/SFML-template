#include "main.ih"

using namespace std;

int main()
{
    parseConfig("assets/config.json");

    Model model;                        // MVC pattern
    ViewSF viewsf;
    Controller controller{ model, viewsf };
    
    controller.run();                   // start the window loop

    return 0;
}
