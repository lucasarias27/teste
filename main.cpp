#include<iostream>
#include<SFML/Graphics.hpp>

int main()
{
    int i = 0, h1=0, h2=0;
    sf::Vector2i v2;
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!", sf::Style::Close | sf::Style::Resize);
    sf::RectangleShape shape(sf::Vector2f(100.f, 100.f));
    shape.setOrigin(50.f, 50.f);
    shape.setFillColor(sf::Color::Green);
    sf::Texture player;
    player.loadFromFile("default.png");
    sf::Texture imagem;
    //if (!imagem.loadFromFile("default.png")) return 0;
    player.(&player);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::Resized)
                std::cout << event.size.width << event.size.height << std::endl;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            shape.move(sf::Vector2f(0.1f,0.f));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            shape.move(sf::Vector2f(-0.1f, 0.f));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            shape.move(sf::Vector2f(0.f, +0.1f));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            shape.move(sf::Vector2f(0.f, -0.1f));
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            v2 = sf::Mouse::getPosition(window);
            shape.setPosition((float)v2.x, static_cast<float>(v2.y));
        }
        if (i > 100) {
            window.clear();
            i = 0;
        }
        i++;
        window.draw(play);
        window.display();
    }

    return 0;
}