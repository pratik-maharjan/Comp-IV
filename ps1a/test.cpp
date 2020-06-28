#include <iostream>
#include <string>
#include <sstream>
#include "LFSR.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

using namespace std;

BOOST_AUTO_TEST_CASE(fiveBitsTapAtTwo)
{
  LFSR l("00111", 2);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);

  LFSR l2("00111", 2);
  BOOST_REQUIRE(l2.generate(8) == 198);
}

BOOST_AUTO_TEST_CASE(PrincetonExamples)
{
  // The simulate step test
  LFSR test("01101000010", 8);
  BOOST_REQUIRE(test.step() == 1);
  BOOST_REQUIRE(test.step() == 1);
  BOOST_REQUIRE(test.step() == 0);
  BOOST_REQUIRE(test.step() == 0);
  BOOST_REQUIRE(test.step() == 1);
  BOOST_REQUIRE(test.step() == 0);
  BOOST_REQUIRE(test.step() == 0);
  BOOST_REQUIRE(test.step() == 1);
  BOOST_REQUIRE(test.step() == 0);
  BOOST_REQUIRE(test.step() == 0);

  LFSR test2("01101000010", 8);
  BOOST_REQUIRE(test2.generate(5) == 25);
  BOOST_REQUIRE(test2.generate(5) == 4);
  BOOST_REQUIRE(test2.generate(5) == 30);
  BOOST_REQUIRE(test2.generate(5) == 27);
  BOOST_REQUIRE(test2.generate(5) == 18);
  BOOST_REQUIRE(test2.generate(5) == 26);
  BOOST_REQUIRE(test2.generate(5) == 28);
  BOOST_REQUIRE(test2.generate(5) == 24);
  BOOST_REQUIRE(test2.generate(5) == 23);
  BOOST_REQUIRE(test2.generate(5) == 29);
}

BOOST_AUTO_TEST_CASE(Constructor_Tests)
{

  LFSR test("110100", 5); //test 1
  stringstream buffer;
  buffer << test;                                    
  BOOST_REQUIRE(buffer.str().compare("110100") == 0); 

  LFSR test2("0", 1); //test 2
  buffer.str("");     
  buffer.clear();
  buffer << test2; 
  BOOST_REQUIRE(buffer.str().compare("0") == 0);

  LFSR test3("0010010111011011101010", 10); 
  buffer.str("");                           
  buffer.clear();
  buffer << test3;
  BOOST_REQUIRE(buffer.str().compare("0010010111011011101010") == 0);
}
