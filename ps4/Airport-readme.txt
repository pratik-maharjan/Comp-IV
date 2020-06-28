/**********************************************************************
 *  Airport-readme template                                                   
 *  Airport Simulation (C++11 Concurrency)                       
 **********************************************************************/

Your name: Pratik Maharjan

Operating system you're using (Linux, OS X, or Windows): OS X

If Windows, which solution?:

Text editor or IDE you're using: VS Code

Hours to complete assignment: A long time. 18 Hours

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
The assignment was to fix the airport synchronization problems using 
mutex and condition variables.

 /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
Used switch statements, mutex locks and condition variables
Plane would choose a runway and then the switch statements
would work after that.


/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/
Plane would choose a runway and then the switch statements
would work after that and unlock the correct mutex after landing

switch (runway)
		{
		case AirportRunways::RUNWAY_4L:
			condVar.wait(lock4L, [=] {
				bool available4L = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4L] == 0);
				bool available15L = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15L] == 0);
				bool available15R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15R] == 0);
				if (available4L && available15L && available15R)
					return true;
				else
					return false;
			});


 /**********************************************************************
 *  Briefly explain what you learned in the assignment.
 **********************************************************************/
I learned how to use mutex locks and condition variables


/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
n/a


/**********************************************************************
 *  Describe any serious problems you encountered.  
 *  If you didn't complete any part of any assignment, 
 *  the things that you didn't do, or didn't get working.                  
 **********************************************************************/
Changed runwaysInUse in public


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
 n/a