/**********************************************************************
 *  readme.txt template                                                   
 *  Guitar Hero: RingBuffer implementation with unit tests and exceptions
 **********************************************************************/

Name: Pratik Maharjan

Hours to complete assignment: ~ 5 hrs

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
The assignment was to write a program to simulate plucking a guitar string 
using the Karplus-Strong algorithm and learn about cpplint while using 
Unit testing and exceptions. I was able to complete the assignment as 
intended.


  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
I used a main function to move the Ring Buffer around and test random edge cases. 
I used Boost to check the Ring Buffer and tested cases of invalid inputs.



/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/
invalid_argument
    used when negative numbers are passed in and since RingBuffer can't
    have negative inputs

    if (isFull()){
        throw std::runtime_error("enqueue: can't enqueue to a full ring");
    }

runtime_error 
    used when attempts to enqueue or dequeue the RingBuffer when it can't
    like when its full or empty

    if (isEmpty()){
        throw std::runtime_error("dequeue: can't dequeue an empty ring");
    }

/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
Yes, completed successfully and passed the tests


/**********************************************************************
 *  Does your RingBuffer implementation pass the unit tests?
 *  Indicate yes or no, and explain how you know that it does or does not.
 **********************************************************************/
Yes, it does.

/**********************************************************************
 *  Explain the time and space performance of your RB implementation
**********************************************************************/
For this assignment, I used a vector, which is less efficient than array
but since the vector is a set size and we can use the resize method to make
it work like an array. Vectors also take up more space because of the things
they keep track of, unlike arrays. So, if there was a lot of RingBuffer 
then it would have some impact. 


/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/
n/a


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
n/a


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
n/a