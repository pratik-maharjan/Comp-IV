#ifndef GUITARSTRING_HPP
#define GUITARSTRING_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <iostream>
#include <string> 
#include <vector>
#include "RingBuffer.hpp"

const int SAMPLING_RATE = 44100;
const double ENERGY_DECAY_FACTOR = 0.996;

class GuitarString {
 public:
  explicit GuitarString(double frequency);

  explicit GuitarString(std::vector<sf::Int16> init);

  void pluck();
  void tic();              // advance the simulation one time step
  sf::Int16 sample();      // return the current sample
  int time();              // return number of times tic was called so far
 private:
  RingBuffer buff;
  int num;
  int tictic;
};
#endif