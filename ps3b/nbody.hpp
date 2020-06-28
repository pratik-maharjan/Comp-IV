#include <iostream>
#include <ostream>
#include <string>
#include <math.h>
#include <fstream>
#include <vector>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

//window size.
const int height = 500;
const int width = 500;

const double gravity = 6.67e-11;

class nbody: public Drawable
{
public:
  nbody(); // Default Constructor

  nbody(double xpos, double ypos, double xvel, double yvel, double mass, double radius, string filename); // Constructor


  void radius(float radius);
  void position();

  friend istream& operator>> (istream &input, nbody &b);

  friend double xForce(nbody &first, nbody &second);
  friend double yForce(nbody &first, nbody &second);
  //friend double getR(nbody &first, nbody &second);
  void forces(double xForce, double yForce);

  void act(double time_t);

private:

  void virtual draw(RenderTarget& target, RenderStates states) const;

  double _xpos, _ypos;
  double _xvel, _yvel;
  double _xforce, _yforce;
  double _xacc, _yacc;
  double _mass;
  double _radius;
  string _filename;

  Image image;
  Sprite sprite;
  Texture texture;
};
