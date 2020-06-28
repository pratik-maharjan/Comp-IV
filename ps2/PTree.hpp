#ifndef PTREE_HPP
#define PTREE_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
using namespace sf;
class PTree : public Drawable
{
public:
	PTree();
	PTree(int len, int dep);
	void pTree (Vector2f vectorOne, Vector2f vectorTwo, int depth);
	void draw(RenderTarget& target, RenderStates states) const;
private:
	std::vector <ConvexShape> squareVector;
	sf::ConvexShape square;
	int depth;

	Vector2f vectorOne;
	Vector2f vectorTwo;

};

#endif
