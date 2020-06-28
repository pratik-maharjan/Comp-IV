/**********************************************************************
 *  N-Body Simulation ps3b-readme.txt template
 **********************************************************************/

Name: Pratik Maharjan 
OS: Mac
Text editor: VS Code
Hours to complete assignment: 7 hours

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
 This assignment was built up on the previous assigment. The assignment 
 was to load and display a static universe. We were provided
with images and input files that we used to create the universe like the 
last assignment, in addition we were to add simulation so the planets
behave like planets. 

----> make
----> ./NBody 157788000.0 25000.0 < planets.txt

  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
Using the lecture and the information of the assignment page, I used the
formulas given to get the right equations in order to compute the forces,
velocity and accelaration. I divided the forces into x and y and later put 
it together to get the net forces. 
I used pow() and sqrt() to get the R. 



/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/
I used kinematic equations like v = u + a * t to get 
_xvel = _xvel + (_xacc * time_t) for the steps and loaded all the files
and images correctly while going through the vector to update the 
planets' properties.



/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
n/a

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
 I added the time escaped and the music. 