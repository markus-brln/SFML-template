#include "viewsf.ih"


void ViewSF::draw()
{
    d_texture.loadFromImage(d_img);     // Load Texture from image
    d_sprite.setTexture(d_texture);
    
    d_window.clear();               // when not the entire screen is refreshed
    d_window.draw(d_sprite);
    
    if (d_showFps)
    {
        d_fpsText.setString("fps: " + to_string(1000 / d_clock.getElapsedTime().asMilliseconds()));
        d_clock.restart();
        d_window.draw(d_fpsText);
    }
    d_window.display();
}