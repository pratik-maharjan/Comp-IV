#include "LFSR.hpp"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

LFSR::LFSR(string seed, int t)
{
	sbits = seed;
	tapPos = t;
}

ostream &operator<<(ostream &out, LFSR &dLFSR)
{
	out << dLFSR.sbits;
	return out;
}

int LFSR::step()
{
	int bitResult;
	int tapPosition = sbits.length() - tapPos - 1; //tap postion = size() -tap -1
	bitResult = sbits[0] ^ sbits[tapPosition];

	string::size_type i; // move to left
	ostringstream ostring;

	for (i = 0; (unsigned)i < sbits.length() - 1; i++)
	{
		ostring << sbits[i + 1];
	}

	ostring << bitResult;
	sbits = ostring.str(); //save and update
	return bitResult;	  //Return result
}

int LFSR::generate(int k)
{
	int x = 0;
	for (int i = 0; i < k; i++)
	{
		x = (x * 2) + step();
	}

	return x;
}
