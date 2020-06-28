#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

//window size.
const int height = 500;
const int width = 500;

class nbody: public Drawable
{
public:
  nbody(); // Default Constructor

  nbody(double xpos, double ypos, double xvel, double yvel, double mass, double radius, string filename); // Constructor


  void radius(float radius);
  void position();

  friend istream& operator>> (istream &input, nbody &b);

private:

  void virtual draw(RenderTarget& target, RenderStates states) const;

  double _xpos, _ypos;
  double _xvel, _yvel;
  double _mass;
  double _radius;
  string _filename;

  Image image;
  Sprite sprite;
  Texture texture;
};
