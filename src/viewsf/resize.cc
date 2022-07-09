#include "viewsf.ih"


void ViewSF::resize()
{
    // cout << d_window.getSize().x << d_img.getSize().x;

    if (d_window.getSize().x != d_img.getSize().x || d_window.getSize().y != d_img.getSize().y)
    {
        SIZE_X = d_window.getSize().x;
        SIZE_Y = d_window.getSize().y;
        Image new_image = Image();
        new_image.create(SIZE_X, SIZE_Y);
        d_img = new_image;
        
    }
    // d_img.create
}