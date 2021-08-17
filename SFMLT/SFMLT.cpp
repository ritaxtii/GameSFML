#include <SFML\Graphics.hpp>
#include <bits/stdc++.h>
#include "Animetion.h"
using namespace std;
int main()
{
    
    sf::RenderWindow window(sf::VideoMode(512,512), "Osss" ,sf::Style::Close | sf::Style::Resize);
    sf::RectangleShape player(sf::Vector2f(100.0f, 150.0f));
    //player.setFillColor(sf::Color::Red);
    player.setPosition(256.0f, 256.0f);
    sf::Texture playerTexture;
    playerTexture.loadFromFile("ttt.png");
    player.setTexture(&playerTexture);

    Animetion animation(&playerTexture, sf::Vector2u(17, 92), 0.3f);

    float deltaTime = 0.0f;
    sf::Clock clock;


    /*sf::Vector2u textureSize = playerTexture.getSize();
    textureSize.x /= 17;
    textureSize.y /= 92;
    player.setTextureRect(sf::IntRect(0, 0, textureSize.x, textureSize.y));*/

    //player.setOrigin(50.0f, 50.0f);
    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            switch (evnt.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            /*case sf::Event::Resized:
                cout << " w " << evnt.size.width << " h " << evnt.size.height << endl;
                break;
            case sf::Event::TextEntered:
                if (evnt.text.unicode < 128)
                {
                    printf("%c", evnt.text.unicode);
                }
                    

            }
            if (evnt.type == evnt.Closed)
            {
                window.close();
            }*/
        }
            
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            player.move(-0.1f, 0.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            player.move(0.1f, 0.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            player.move(0.0f, -0.1f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        {
            player.move(0.0f, 0.1f);
        }
        
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i mousePos=sf::Mouse::getPosition(window);
            player.setPosition((float)mousePos.x, static_cast<float>(mousePos.y));
        }
            animation.Update(0, deltaTime);
            player.setTextureRect(animation.uvRect);
        window.clear(sf::Color(150,150,150));
        window.draw(player);
        window.display();
    }

    

    return 0;
}