#include "viewsf.ih"


void ViewSF::draw()
{
    // If the image size changes, re-allocate the texture; otherwise, just stream the new pixel data.
    if (d_texture.getSize() != d_img.getSize())
    {
        if (!d_texture.loadFromImage(d_img))
        {
            throw runtime_error("Could not load from image.");
        }
        // CRITICAL FIX: Pass 'true' to adjust the sprite's clipping rect to the new texture size
        d_sprite.setTexture(d_texture, true);
    }
    else
    {
        d_texture.update(d_img);
    }

    d_window.clear();
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
