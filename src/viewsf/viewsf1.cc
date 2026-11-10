#include "viewsf.ih"


ViewSF::ViewSF()
    :
    d_window(RenderWindow{VideoMode(WINDOW_SIZE, 1), "Default window"}),
    d_sprite(d_texture),
    d_fullScreen(FULL_SCREEN),
    d_fpsText(d_font),
    d_showFps(SHOW_FPS)
{
    d_window.setFramerateLimit(60);

    if (!d_font.openFromFile(FONT_PATH))
    {
        throw runtime_error("Could not the find font file to instantiate fpsText font");
    }
    d_fpsText.setFont(d_font);
    d_fpsText.setCharacterSize(FONT_SIZE);
    d_fpsText.setFillColor(FONT_COLOR);
    d_img = Image{WINDOW_SIZE, Color::Black};
}
