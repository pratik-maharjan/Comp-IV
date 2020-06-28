#ifndef RINGBUFFER_HPP
#define RINGBUFFER_HPP 

#include <stdint.h>
#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include <stdexcept>
#include <vector>

class RingBuffer {
 public:
   explicit RingBuffer(int capacity); // create an empty ring buffer, with given max capacity
   int size();                        // return number of items currently in the buffer
   bool isEmpty();                    // is the buffer empty (size equals zero)?
   bool isFull();                     // is the buffer full (size equals capacity)?
   void enqueue(int16_t x);           // add item x to the end
   int16_t dequeue();                 // delete and return item from the front
   int16_t peek();                    // return (but do not delete) item from the front
   void output();

 private:
  std::vector<int16_t> buf;
  int fir; //first
  int las; //last
  int cap; //capacity
  int s; //size
};
#endif