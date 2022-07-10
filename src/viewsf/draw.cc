#include "viewsf.ih"


void ViewSF::draw()
{
    d_texture.loadFromImage(d_img, IntRect{ Vector2i{ 0, 0 }, Vector2i{ d_img.getSize() } });     // Load Texture from image
    d_sprite.setTexture(d_texture);
    
    d_window.clear();                   // when not the entire screen is refreshed
    d_window.draw(d_sprite);
    
    if (d_showFps)
    {
        d_fpsText.setString("fps: " + to_string(1000 / d_clock.getElapsedTime().asMilliseconds()) + 
                            " img: " + to_string(d_img.getSize().x) + " " + to_string(d_img.getSize().y) + " " + 
                                     to_string(d_window.getSize().x) + " " + to_string(d_window.getSize().y));
        d_clock.restart();
        d_window.draw(d_fpsText);
    }
    d_window.display();

}