/**********************************************************************
 *  N-Body Simulation ps3a-readme.txt template
 **********************************************************************/

Name: Pratik Maharjan 
OS: Mac
Text editor: Visual Studios Code
Hours to complete assignment: about 6 hours maybe

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
The assignment was to load and display a static universe. We were provided
with images and input files that we used to create the universe. The program
took in inputs from a file using cin to read the file. I overloaded the 
>> operator as instucted. 

-----> make
-----> ./NBody < planets.txt


  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
So, finding the postions of the planets was important. I took in the 
pos from the input and then divided it by the radius to make the large
numbers smaller and easier to work with. I then multiplied it by either 
the height or the width, depending on the x or y position,
in order to get the postion in SFML coordinate system. Because in SFML,
0,0 is top left and not the middle. 
I also overloaded the >> operator which used istream to take input from 
cin and pass it into the variables. 


/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/
So, as mentioned above, I did this to get the postion, I created a seperate
method to get the postion.

    double halfHeight = height/2;
    double halfWidth = width/2;
    double sfmlPos_x = ((_xpos/_radius) * halfWidth);     
    double sfmlPos_y = ((_ypos/_radius) * halfHeight);    
    _xpos = sfmlPos_x + halfWidth;                       
    _ypos = sfmlPos_y + halfHeight;

Also, for overloading the >> operator, I did
    input >> b._xpos >> b._ypos;
to take the input and pass it into the variables.
I did,
    cin >> num;
    cin >> radius;
to get the number of objects and radius and then did 
created a vector<nbody> to store the planets. 

/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
I used the link provided in the instuction file understand how to 
overload the >> operator correctly.

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
n/a

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
 Added backgound image as well for extra credit and it also make the 
 output look much more asthetic. 
