/**********************************************************************
 *  Linear Feedback Shift Register (part B) ps1b-readme.txt template
 **********************************************************************/

Name: Pratik Maharjan
OS: Window
Machine (e.g., Dell Latitude, MacBook Pro):
Text editor: VS Code
Hours to complete assignment: ~ 3 hrs
/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/

---> make
---> ./PhotoMagic input.png output.png 01101000010100010000 16      #input
---> ./PhotoMagic output.png input.png 01101000010100010000 16      #output
---> make clean

For this assignment, 
I built on the previous assignment and wrote PhotoMagic.cpp. I used my previous
LFSR class to encode and decode the input image to get the output image that we 
wanted. By performing XOR to the color components (red, blue, green). When I run
the code from command line, it will show the input file or the source file and 
the encrypted file. I used the SFML for displaying the image. 

/**********************************************************************
 *  If you did any implementation for extra credit, describe it
 *  here and why it is interesting.
 **********************************************************************/

--- N/A ---


/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
www.sfml-dev.org/tutorials/2.5/start-vc.php

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
I didn't save the encrypted file at first, so I was having trouble 
doing the reverse. 

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/





