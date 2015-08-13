#include <cstdlib>
#include <iostream>
#include <string>

#include <SFML\Graphics.hpp>

int main(int argc, char *argv[])
{

    bool quit = false;
    sf::RenderWindow *screen = new sf::RenderWindow(sf::VideoMode(800,600,32), "SFML");

    while(!quit)
    {
        screen->clear();

        sf::Event event;

        while(screen->pollEvent(event))
        {
            if(event.type == sf::Event::Closed) quit = true;
            else if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Escape) quit = true;
            }
        }

        //update

        //draw


        //display
        screen->display();
    }

    return 0;
}
