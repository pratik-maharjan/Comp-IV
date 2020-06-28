#include <iostream>
#include <string>
#include <sstream>

#include "LFSR.hpp"   

using namespace std;

int main(){
  LFSR test("01101000010", 8);  //test 1
  cout << "\nTest case 1" << endl;
  for(int l = 0; l < 10; l++) {  
    int bit = test.step();    
    cout << test << " " << bit << endl;
  }

  LFSR test2("01101000010", 8);  //test2
  cout << "\n\nTest case 2" << endl;
  for(int l = 0; l < 10; l++) {  
    int roll = test2.generate(5);   
    cout << test2 << " " << roll << endl;
  }

  LFSR test3("0101", 2);   //test3
  int number = test3.generate(2);   
  cout << test3 << " " << number <<  endl;

  LFSR test4("0011010010", 3);   //test4
  int number2 = test4.generate(4);  
  cout << number2 << "\n";

  return 0;
}
