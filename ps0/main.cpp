//Pratik Maharjan


#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main()
{
  // window size
  RenderWindow window(VideoMode(600, 600), "skier skiing");

  // framerate
  window.setFramerateLimit(70);

  // Load image
  sf::Texture texture;
    if (!texture.loadFromFile("sprite.png"))
	return EXIT_FAILURE;

texture.setSmooth(true);

Sprite skier;
skier.setTexture(texture);
skier.scale(.25f, .25f);
skier.setOrigin(125,125);
skier.move(125,100);

  while (window.isOpen()){
    Event skiing;
    while(window.pollEvent(skiing)){
      if (skiing.type == Event::Closed){
        window.close();
      }

      else if(skiing.type == sf::Event::KeyPressed){
	 if (Keyboard::isKeyPressed(Keyboard::Left)){
          skier.move(-20, 0); // move left
        }
        else if (Keyboard::isKeyPressed(Keyboard::Right)){
          skier.move(20, 0); // move right
        }
        else if (Keyboard::isKeyPressed(Keyboard::Up)){
          skier.move(0, -20); // move up
        }
        else if (Keyboard::isKeyPressed(Keyboard::Down)){
          skier.move(0, 20); // move down
     	}
	else if (Keyboard::isKeyPressed(Keyboard::Space)){
          skier.rotate(120); // addtional feature
        }
      }
    }

    window.clear();
    window.draw(skier);
    window.display();
  }

  return 0;
}
