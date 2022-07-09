#include "viewsf.ih"


ViewSF::ViewSF()
:
    d_window(RenderWindow{ VideoMode(SIZE_X, SIZE_Y), "Default window" }),
    d_fullScreen(FULL_SCREEN),
    d_showFps(SHOW_FPS)
{
    d_window.setFramerateLimit(60);

    d_font.loadFromFile(FONT_PATH);
    d_fpsText.setFont(d_font);
    d_fpsText.setCharacterSize(FONT_SIZE);
    d_fpsText.setFillColor(FONT_COLOR);
    d_img.create(SIZE_X, SIZE_Y);
}
