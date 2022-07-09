#include "viewsf.ih"


void ViewSF::resize()
{
    // cout << d_window.getSize().x << d_img.getSize().x;
    Vector2f window_size{ d_window.getSize() };
    Vector2f image_size{ d_img.getSize() };


    if (window_size != image_size)
    {
        d_fpsText.scale(image_size.x / window_size.x, image_size.y / window_size.y);

        Image new_image = Image();
        new_image.create(window_size.x, window_size.y);
        d_img = new_image;
        
    }
    // d_img.create
}