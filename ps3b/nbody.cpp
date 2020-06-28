#include "nbody.hpp"
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
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

//force
void nbody::forces(double xForce, double yForce)
{
  _xforce = xForce;
  _yforce = yForce;
}

// Force between 2 objects
double xForce(nbody &first, nbody &second)
{
  // Force = (G * M1 * M2)/r^2
  double x = second._xpos - first._xpos;
  double y = second._ypos - first._ypos;
  double rSquared = pow(x, 2) + pow(y, 2);
  double R = sqrt(rSquared);
  double force = (gravity * first._mass * second._mass) / rSquared;
  double x_force = force * (x / R);

  return x_force;
}

double yForce(nbody &first, nbody &second)
{
  // Force = (G * M1 * M2)/r^2
  double x = second._xpos - first._xpos;
  double y = second._ypos - first._ypos;
  double rSquared = pow(x, 2) + pow(y, 2);
  double R = sqrt(rSquared);
  double force = (gravity * first._mass * second._mass) / rSquared;
  double y_force = force * (y / R);

  return y_force;
}

void nbody::act(double time_t)
{
  // Force = mass * acc.
  // rearrange them to get
  // acc = force / mass
  _xacc = _xforce / _mass;
  _yacc = _yforce / _mass;

  // using kinematic eqs. v = u + a * t
  _xvel = _xvel + (_xacc * time_t);
  _yvel = _yvel + (_yacc * time_t);

  _xpos = _xpos + (_xvel * time_t);
  _ypos = _ypos + (_yvel * time_t);
}

//position
void nbody::position()
{
  double xpos = ((_xpos / _radius) * (width / 2)) + (height / 2);
  double ypos = ((_ypos / _radius) * (width / 2)) + (height / 2);

  sprite.setPosition(sf::Vector2f(ypos, xpos));
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
  input >> b._xvel >> b._yvel;
  input >> b._mass >> b._filename;
  if (!b.image.loadFromFile(b._filename)) 
  {
    return input;
  }
  b.texture.loadFromImage(b.image);
  b.sprite.setTexture(b.texture);
  b.sprite.setPosition(Vector2f(b._xpos, b._ypos)); //intial

  b._xacc = 0;
  b._yacc = 0;
  b._xforce = 0;
  b._yforce = 0;
  
  return input;
}


int main(int argc, char *argv[])
{
  // Get the simulation time / time step from the command line arguments
	std::string sim(argv[1]);
	std::string step(argv[2]);
	std::string::size_type sz;

  // Convert these strings to doubles
  double simulation = 0;
  double simulationTime = std::stod(sim, &sz);
  double stepTime = std::stod(step, &sz);

  string num, radius;

  cin >> num;
  cin >> radius;

  int numOfPlanets = atoi(num.c_str()); // convert into int and float
  float radiusOfUni = atof(radius.c_str());

  vector<nbody> planetVector;

  for (int i = 0; i < numOfPlanets; i++)
  {
    nbody *objects = new nbody();
    cin >> *objects;
    objects->radius(radiusOfUni);
    objects->position();
    planetVector.push_back(*objects);
  } // loop through the number of planets and create the bodies and push it into the vector.

  // SFML Window
  RenderWindow window(VideoMode(width, height), "The Planets");
  window.setFramerateLimit(60);

  // Background image
  Image backgroundImage;
  if (!backgroundImage.loadFromFile("starfield.jpg"))
  {
    return -1;
  }

  // Font for the time
  Font font4time;
  font4time.loadFromFile("Georgia Italic.ttf");

  // display time
  Text t;
  t.setFont(font4time);      // font type
  t.setCharacterSize(20);    // size
  t.setColor(sf::Color::Yellow); // color

  // Music
  Music music;
  if (!music.openFromFile("2001.wav"))
  {
    return -1;
  }
  music.play();

  Texture backgroundTexture;
  backgroundTexture.loadFromImage(backgroundImage);

  Sprite backgroundSprite;
  backgroundSprite.setTexture(backgroundTexture);

  vector<nbody>::iterator it;
  vector<nbody>::iterator x, y;

  while (window.isOpen())
  {
    Event event;

    while (window.pollEvent(event))
    {
      if (event.type == Event::Closed)
      {
        window.close();
      }
    }

    window.clear();

    window.draw(backgroundSprite);

    t.setString("Elapsed time: " + std::to_string(simulation));

    window.draw(t);

    x = planetVector.begin();
    double force_x, force_y;

    for (int a = 0; a < numOfPlanets; a++)
    { // update net force on all the objects
      y = planetVector.begin();
      force_x = 0;
      force_y = 0;

      for (int b = 0; b < numOfPlanets; b++)
      { // update current object forces
        if (a != b)
        {
          force_x += xForce(*x, *y);
          force_y += yForce(*x, *y);
        }
        y++;
      }
      x->forces(force_x, force_y);
      x++;
    }

    // Display
    for (it = planetVector.begin(); it != planetVector.end(); it++)
    {
      window.draw(*it);
      it->act(stepTime);
      it->position();
    }

    window.display();
    simulation ++;
    if (simulation == simulationTime)
    {
      break;
    }
  }

  return 0;
}
