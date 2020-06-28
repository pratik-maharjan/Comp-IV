#ifndef LFSR_HPP
#define LFSR_HPP

#include <iostream>
#include <string>

using namespace std;

class LFSR {
public:

	LFSR(string seed, int t); 	// constructor to create LFSR with
								// the given initial seed and tap
	int step(); 				// simulate one step and return the
								// new bit as 0 or 1
  	int generate(int k); 		// simulate k steps and return
								// k-bit integer
	friend ostream &operator<<(ostream &out, LFSR &dLFSR);

private: 
	string sbits;
	int tapPos;

};
#endif
