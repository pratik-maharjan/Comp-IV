#include <iostream>
#include <thread>
#include <condition_variable>

#include "AirportServer.h"

/**
*  Called by an Airplane when it wishes to land on a runway
*/
void AirportServer::reserveRunway(int airplaneNum, AirportRunways::RunwayNumber runway)
{
	// Acquire runway(s)
	{ // Begin critical region

		unique_lock<mutex> runwaysLock(runwaysMutex);

		{
			std::unique_lock<mutex> lk(AirportRunways::checkMutex);
			while (AirportRunways::getNumLandingRequests() >= 6)
			{
				condVar.wait(lk);
				cout << "Airplane #" << airplaneNum << " is acquiring any needed runway(s) for landing on Runway " << AirportRunways::runwayName(runway) << endl;
			}
			AirportRunways::incNumLandingRequests();
		}

		/**
		 *  ***** Add your synchronization here! *****
		 */

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

			condVar.wait(lock15L, [=] {
				bool available4L = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4L] == 0);
				bool available15L = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15L] == 0);
				bool available15R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15R] == 0);
				if (available4L && available15L && available15R)
					return true;
				else
					return false;
			});
			condVar.wait(lock15R, [=] {
				bool available4L = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4L] == 0);
				bool available15L = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15L] == 0);
				bool available15R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15R] == 0);
				if (available4L && available15L && available15R)
				{
					return true;
				}
				else
				{
					return false;
				}
			});
			break;

		case AirportRunways::RUNWAY_4R:
			condVar.wait(lock4R, [=] {
				bool available4R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4R] == 0);
				bool available15L = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15L] == 0);
				bool available15R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15R] == 0);
				bool available9 = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_9] == 0);
				if (available4R && available15L && available15R && available9)
					return true;
				else
					return false;
			});
			condVar.wait(lock15L, [=] {
				bool available4R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4R] == 0);
				bool available15L = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15L] == 0);
				bool available15R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15R] == 0);
				bool available9 = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_9] == 0);
				if (available4R && available15L && available15R && available9)
					return true;
				else
					return false;
			});
			condVar.wait(lock15R, [=] {
				bool available4R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4R] == 0);
				bool available15L = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15L] == 0);
				bool available15R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15R] == 0);
				bool available9 = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_9] == 0);
				if (available4R && available15L && available15R && available9)
					return true;
				else
					return false;
			});
			condVar.wait(lock9, [=] {
				bool available4R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4R] == 0);
				bool available15L = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15L] == 0);
				bool available15R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15R] == 0);
				bool available9 = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_9] == 0);
				if (available4R && available15L && available15R && available9)
					return true;
				else
					return false;
			});
			break;

		case AirportRunways::RUNWAY_15R:
			condVar.wait(lock4L, [=] {
				bool available4L = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4L] == 0);
				bool available4R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4R] == 0);
				bool available15R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15R] == 0);
				bool available9 = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_9] == 0);
				if (available4L && available4R && available15R && available9)
					return true;
				else
					return false;
			});
			condVar.wait(lock4R, [=] {
				bool available4L = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4L] == 0);
				bool available4R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4R] == 0);
				bool available15R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15R] == 0);
				bool available9 = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_9] == 0);
				if (available4L && available4R && available15R && available9)
					return true;
				else
					return false;
			});
			condVar.wait(lock15R, [=] {
				bool available4L = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4L] == 0);
				bool available4R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4R] == 0);
				bool available15R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15R] == 0);
				bool available9 = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_9] == 0);
				if (available4L && available4R && available15R && available9)
					return true;
				else
					return false;
			});
			condVar.wait(lock9, [=] {
				bool available4L = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4L] == 0);
				bool available4R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4R] == 0);
				bool available15R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15R] == 0);
				bool available9 = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_9] == 0);
				if (available4L && available4R && available15R && available9)
					return true;
				else
					return false;
			});
			break;

		case AirportRunways::RUNWAY_15L:
			condVar.wait(lock4L, [=] {
				bool available4L = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4L] == 0);
				bool available4R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4R] == 0);
				bool available15L = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15L] == 0);
				if (available4L && available4R && available15L)
					return true;
				else
					return false;
			});
			condVar.wait(lock4R, [=] {
				bool available4L = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4L] == 0);
				bool available4R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4R] == 0);
				bool available15L = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15L] == 0);
				if (available4L && available4R && available15L)
					return true;
				else
					return false;
			});
			condVar.wait(lock15L, [=] {
				bool available4L = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4L] == 0);
				bool available4R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4R] == 0);
				bool available15L = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15L] == 0);
				if (available4L && available4R && available15L)
					return true;
				else
					return false;
			});
			break;

		case AirportRunways::RUNWAY_9:
			condVar.wait(lock4R, [=] {
				bool available4R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4R] == 0);
				bool available15R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15R] == 0);
				bool available9 = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_9] == 0);
				if (available4R && available15R && available9)
					return true;
				else
					return false;
			});
			condVar.wait(lock15R, [=] {
				bool available4R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4R] == 0);
				bool available15R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15R] == 0);
				bool available9 = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_9] == 0);
				if (available4R && available15R && available9)
					return true;
				else
					return false;
			});
			condVar.wait(lock9, [=] {
				bool available4R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_4R] == 0);
				bool available15R = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_15R] == 0);
				bool available9 = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_9] == 0);
				if (available4R && available15R && available9)
					return true;
				else
					return false;
			});
			break;

		case AirportRunways::RUNWAY_14:
			condVar.wait(lock4L, [=] {
				bool available14 = (AirportRunways::runwayInUse[AirportRunways::RUNWAY_14] == 0);
				if (available14)
					return true;
				else
					return false;
			});
			break;
		}
		AirportRunways::checkAirportStatus(runway);

		

	} // End critical region

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);

	std::uniform_int_distribution<int> taxiTimeDistribution(1, MAX_TAXI_TIME);
	int taxiTime = taxiTimeDistribution(generator);

	{
		lock_guard<mutex> lk(AirportRunways::checkMutex);

		cout << "Airplane #" << airplaneNum << " is taxiing on Runway " << AirportRunways::runwayName(runway)
			 << " for " << taxiTime << " milliseconds\n";
	}

	std::this_thread::sleep_for(std::chrono::milliseconds(taxiTime));

} // end AirportServer::reserveRunway()

/**
  *  Called by an Airplane when it is finished landing
  */
void AirportServer::releaseRunway(int airplaneNum, AirportRunways::RunwayNumber runway)
{
	{ // Begin critical region
		{
			lock_guard<mutex> lk(AirportRunways::checkMutex);

			cout << "Airplane #" << airplaneNum << " is releasing any needed runway(s) after landing on Runway "
				 << AirportRunways::runwayName(runway) << endl;
		}

		switch (runway)
		{
		case AirportRunways::RUNWAY_4L:
			rw_4L.unlock();
			rw_15L.unlock();
			rw_15R.unlock();
			break;

		case AirportRunways::RUNWAY_4R:
			rw_4R.unlock();
			rw_15L.unlock();
			rw_15R.unlock();
			rw_9.unlock();
			break;

		case AirportRunways::RUNWAY_9:
			rw_4R.unlock();
			rw_15R.unlock();
			rw_9.unlock();
			break;

		case AirportRunways::RUNWAY_15R:
			rw_4L.unlock();
			rw_4R.unlock();
			rw_15R.unlock();
			rw_9.unlock();
			break;

		case AirportRunways::RUNWAY_15L:
			rw_4L.unlock();
			rw_4R.unlock();
			rw_15L.unlock();
			break;

		case AirportRunways::RUNWAY_14:
			rw_14.unlock();
			break;
		}

		AirportRunways::finishedWithRunway(runway);
		AirportRunways::decNumLandingRequests();
		condVar.notify_one();

	} 

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);

	std::uniform_int_distribution<int> waitTimeDistribution(1, MAX_WAIT_TIME);
	int waitTime = waitTimeDistribution(generator);

	{
		lock_guard<mutex> lk(AirportRunways::checkMutex);

		cout << "Airplane #" << airplaneNum << " is waiting for " << waitTime << " milliseconds before landing again\n";
	}

	std::this_thread::sleep_for(std::chrono::milliseconds(waitTime));

} 
