#include "model.ih"


void Model::render(sf::Image &img)
{
    Vector2 size = img.getSize();
    # pragma omp parallel for
    for (size_t y = 0; y < size.y; ++y)
    {
        for (size_t x = 0; x < size.y; ++x)
        {
            // img.setPixel(x, y, sf::Color{ static_cast<sf::Uint8>(cos(double(x) / (size.x % 30)) * 255),  
            //                               static_cast<sf::Uint8>(0),
            //                               static_cast<sf::Uint8>(0) }); // uint8
            img.setPixel(x, y, sf::Color{ static_cast<sf::Uint8>((double(x) / double(size.x)) * 255),  
                                    static_cast<sf::Uint8>(0),
                                    static_cast<sf::Uint8>(0); // uint8
        }        
    }
}
