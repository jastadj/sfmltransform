#include <cstdlib>
#include <iostream>
#include <string>

#include <SFML\Graphics.hpp>

int main(int argc, char *argv[])
{

    bool quit = false;
    sf::RenderWindow *screen = new sf::RenderWindow(sf::VideoMode(800,600,32), "SFML");

    //graphics
    sf::Texture texture;
    sf::Sprite sprite;

    //load graphic
    texture.loadFromFile("crate.png");
    sprite.setTexture(texture);

    //graphic properties
    sf::Vector2f pos;
    float scale = 1;
    float rot = 0;

    //params
    float scale_units = 0.1;
    float rot_units = 10.0;
    int move_units = 10;


    while(!quit)
    {
        screen->clear();

        sf::Event event;

        //get mouse pos
        sf::Vector2f mousepos = sf::Vector2f(sf::Mouse::getPosition(*screen));





        //transform
        sf::Transform t;
        //move image
        t.translate(pos);

        //scale image
        //move to center of image
        t.translate(sprite.getLocalBounds().width/2, sprite.getLocalBounds().height/2);
        t.scale(scale, scale);
        //rotate image
        t.rotate(rot);
        //move back to top left corner
        t.translate(-sprite.getLocalBounds().width/2, -sprite.getLocalBounds().height/2);






        while(screen->pollEvent(event))
        {
            if(event.type == sf::Event::Closed) quit = true;
            else if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Escape) quit = true;
                else if(event.key.code == sf::Keyboard::W) pos.y -= move_units;
                else if(event.key.code == sf::Keyboard::S) pos.y += move_units;
                else if(event.key.code == sf::Keyboard::A) pos.x -= move_units;
                else if(event.key.code == sf::Keyboard::D) pos.x += move_units;
                else if(event.key.code == sf::Keyboard::Q) scale -= scale_units;
                else if(event.key.code == sf::Keyboard::E) scale += scale_units;
            }
            else if(event.type == sf::Event::MouseButtonPressed)
            {
                //if mouse clicked in graphic
                if(t.transformRect(sprite.getGlobalBounds()).contains(mousepos) )
                {
                    std::cout << "sprite clicked\n";
                }

            }
            else if(event.type == sf::Event::MouseWheelMoved)
            {
                if(event.mouseWheel.delta > 0)
                {
                    rot += rot_units;
                }
                else if(event.mouseWheel.delta < 0)
                {
                    rot -= rot_units;
                }

            }
        }

        //update

        //draw
        screen->draw(sprite, t);

        //display
        screen->display();
    }

    return 0;
}
