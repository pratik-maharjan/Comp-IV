/**********************************************************************
 *  Linear Feedback Shift Register (part A) ps1a-readme.txt template
 **********************************************************************/

Name:Pratik Maharjan
Hours to complete assignment: ~ 5 Hours


/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
The assignment was to write a data type that simulates the operation
of a LFSR. I successfully wrote the linear feedback shift register(LFSR) 
class. I was also able to successfully implement the unit tests using 
the boost test framework.


/**********************************************************************
 *  Explain the representation you used for the register bits 
 *  (how it works, and why you selected it)
 **********************************************************************/
The representation I used for the register bits was strings. I used 
this because strings are easy to work with. You can use the string 
operations to get certain bits and to get the seed then just shift
the string to the left with a loop. 
 

/**********************************************************************
 * Discuss what's being tested in your two additional Boost unit tests
  **********************************************************************/
The two additional tests are testing the edge cases on the constructor 
and << (shift left) operator and two types seed, -long seed and -small seed


/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
N/A 


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
I struggled on the LFSR.cpp before trying string which was suggested by 
a classmate. 


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
