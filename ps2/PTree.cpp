#include <cmath>
#include "PTree.hpp"

PTree::PTree(){}

PTree::PTree(int length, int depth) {
    vectorOne.x = 6 * length/2 - length/2;
	vectorTwo.x = 6 * length/2 + length/2;
    vectorOne.y = 4 * length;
    vectorTwo.y = 4 * length;

    this->depth = depth;
    square.setPointCount(4);
    pTree(vectorOne, vectorTwo, depth);
}

void PTree::pTree (Vector2f vectorOne, Vector2f vectorTwo, int depth) {

    if(depth > 0) {
        Vector2f vectorThree;
        Vector2f vectorFour;
        Vector2f vectorFive;
        vectorThree.x = vectorTwo.x - (vectorOne.y -  vectorTwo.y);
        vectorThree.y = vectorTwo.y - (vectorTwo.x - vectorOne.x);

        vectorFour.x = vectorOne.x - (vectorOne.y -  vectorTwo.y);
        vectorFour.y = vectorOne.y - (vectorTwo.x - vectorOne.x);

        vectorFive.x = vectorFour.x +  ( vectorTwo.x - vectorOne.x - (vectorOne.y -  vectorTwo.y) ) / 2;
        vectorFive.y = vectorFour.y -  ( vectorTwo.x - vectorOne.x + vectorOne.y -  vectorTwo.y ) / 2;

        square.setPoint(0, vectorOne);
        square.setPoint(1, vectorTwo);
        square.setPoint(2, vectorThree);
        square.setPoint(3, vectorFour);
        square.setFillColor(sf::Color(128,255, vectorOne.x));
        squareVector.push_back(square);

        pTree(vectorFour, vectorFive, depth - 1);
        pTree(vectorFive, vectorThree, depth - 1);
    }
}

void PTree::draw(RenderTarget& target, RenderStates states) const {
    for(int i = 0; i < squareVector.size(); i++) {
        target.draw(squareVector.at(i));
    }
}
