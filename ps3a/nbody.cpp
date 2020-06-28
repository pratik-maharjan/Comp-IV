#include "nbody.hpp"
using namespace std;
using namespace sf;

//default constructor
nbody::nbody()
{
  return;
}

//constructor
nbody::nbody(double xpos, double ypos, double xvel, double yvel, double mass, double radius, string filename)
{
  _xpos = xpos;
  _ypos = ypos;
  _xvel = xvel;
  _yvel = yvel;
  _mass = mass;
  _filename = filename;

  if (!image.loadFromFile(filename))
  {
    return;
  }

  texture.loadFromImage(image);
  sprite.setTexture(texture);
  sprite.setPosition(Vector2f(_xpos, _ypos));
}


//radius
void nbody::radius(float radius)
{
  _radius = radius;
  return;
}


//position
void nbody::position()
{
  double halfHeight = height/2;
  double halfWidth = width/2;
  double sfmlPos_x = ((_xpos/_radius) * halfWidth);     // get the SFML position by dividing the pos by the radius
  double sfmlPos_y = ((_ypos/_radius) * halfHeight);    // and then multipling it by half of height or width depending
  _xpos = sfmlPos_x + halfWidth;                        // on the x or y position. Then add the half of height or width 
  _ypos = sfmlPos_y + halfHeight;                       // so it's aligned at to the center

  sprite.setPosition(Vector2f(_xpos, _ypos));
}

//drawable
void nbody::draw(RenderTarget& target, RenderStates states) const
{
  target.draw(sprite);
}

//operator >>
istream& operator>> (istream &input, nbody &b)
{
  input >> b._xpos >> b._ypos;
  input >> b._yvel >> b._yvel;
  input >> b._mass >> b._filename;
  if (!b.image.loadFromFile(b._filename)) 
  {
    return input;
  }
  b.texture.loadFromImage(b.image);
  b.sprite.setTexture(b.texture);
  b.sprite.setPosition(Vector2f(b._xpos, b._ypos)); //intial

  return input;
}


int main(int argc, char* argv[])
{
  string num, radius;

  cin >> num;
  cin >> radius;

  int numOfPlanets = atoi(num.c_str()); // convert into int and float
  float radiusOfUni = atof(radius.c_str());

  vector<nbody> planetVector;

  for(int i = 0; i < numOfPlanets; i++)
  {
    nbody* objects = new nbody();
    cin >> *objects;
    objects->radius(radiusOfUni);
    objects->position();
    planetVector.push_back(*objects);
  } // loop through the number of planets and create the bodies and push it into the vector.

  RenderWindow window(VideoMode(width, height), "The Solar System");
  window.setFramerateLimit(1);

  // Background
  Image backgroundImage;

  if (!backgroundImage.loadFromFile("starfield.jpg"))
  {
    return -1;
  }

  Texture backgroundTexture;
  backgroundTexture.loadFromImage(backgroundImage);

  Sprite backgroundSprite;
  backgroundSprite.setTexture(backgroundTexture);

  backgroundSprite.setPosition(Vector2f(0,0));

  // Window loop
  while (window.isOpen())
  {
    Event event;
    while(window.pollEvent(event))
    {
      if (event.type == Event::Closed)
      {
        window.close();
      }
      else if (Keyboard::isKeyPressed(Keyboard::Escape))
      {
        window.close();
      }
    }
    window.clear();

    window.draw(backgroundSprite);

    for(auto const& a: planetVector){
        window.draw(a);
    }
    window.display();
  }
  return 0;
}
