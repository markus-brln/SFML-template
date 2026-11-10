#include "model.ih"


void Model::render(Image& img)
{
    Vector2 size = img.getSize();

    cout << img.getSize().x << " " << img.getSize().y << '\n';
    #pragma omp parallel for collapse(2)
    for (size_t y = 0; y < size.y; ++y)
    {
        for (size_t x = 0; x < size.y; ++x)
        {
            img.setPixel(Vector2u(x, y), Color{
                             static_cast<std::uint8_t>(cos(static_cast<double>(x) / (size.x % 30)) * 255),
                             static_cast<std::uint8_t>(133),
                             static_cast<std::uint8_t>(22),
                              255
                         });
            // cout << x << " " << static_cast<std::uint8_t>(cos(static_cast<double>(x) / (size.x % 30)) * 255) << '\n';
            // img.setPixel(x, y, sf::Color{ static_cast<sf::Uint8>((double(x) / double(size.x)) * 255),
            //                               static_cast<sf::Uint8>(0),
            //                               static_cast<sf::Uint8>(0) }); // uint8
            // img.setPixel(x, y, sf::Color{ static_cast<sf::Uint8>(255),
            //                               static_cast<sf::Uint8>(0),
            //                               static_cast<sf::Uint8>(0) }); // uint8
        }
    }
}
