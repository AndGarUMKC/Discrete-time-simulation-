#include "PrintQueue.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

printQueue::printQueue() {
	waitTime = 0;
	serviceTime = 0;
}


int printQueue::processJob(jobsData job, vector<statistics>& stats, int currentTime) {
	serviceTime = round((job.getPages() * 1.0 / printCapacity) + 2.0);
	waitTime = currentTime - job.getArrivalTime();

    // Switch Cases for wait times and job handling
	switch(job.getCategory()) {

	case 'A':
        // increase tick for job handled
		stats.at(0).jobHandled();

        // add wait time to total
		stats.at(0).addWaitTime(waitTime);
				
		if (waitTime > stats.at(0).getMaxWaitTime()) {

            //update wait time
			stats.at(0).updateMaxWaitTime(waitTime);
		}
		break;

	case 'F':

        // increase tick for job handled
		stats.at(1).jobHandled();

        // add wait time to total
		stats.at(1).addWaitTime(waitTime);

		if (waitTime > stats.at(1).getMaxWaitTime()) {
            
            //update wait time
			stats.at(1).updateMaxWaitTime(waitTime);
		}
		break;

	case 'S':

        // increase tick for job handled
		stats.at(2).jobHandled();

        // add wait time to total
		stats.at(2).addWaitTime(waitTime);

		if (waitTime > stats.at(2).getMaxWaitTime()) {

            //update wait time
			stats.at(2).updateMaxWaitTime(waitTime);
		}
		break;
	}

    // nextAvailableTime
	return (currentTime + serviceTime);
}

// write stats
void printQueue::writeSummary(ofstream& out, vector<statistics>& stats, int categories) {
	int totalJobs = 0;
	int totalWait = 0;
	
	out << "Summary:\n\n";
		
	for (int i = 0; i < categories; i++) {
		totalJobs += stats.at(i).getJobsHandled();
		totalWait += stats.at(i).getWaitTime();

		switch (i) {

		case 0:
			out << "Administrators:\n";
			break;

		case 1:
			out << "Faculty:\n";
			break;

		case 2:
			out << "Students:\n";
			break;
		}

		out << stats.at(i).getJobsHandled() << " jobs handled." << endl;
		out << "Maximum wait ............. " << stats.at(i).getMaxWaitTime() << " minutes." << endl;
		out << "Total waiting time ....... " << stats.at(i).getWaitTime() << " minutes." << endl;
		out << "Average waiting time ..... " << (stats.at(i).getWaitTime() * 1.0 / stats.at(i).getJobsHandled())
			<< " minutes.\n" << endl;

        // clear stats for next simulation
		stats.at(i).clearStats();
	}

	out << "Overall Totals:\n";
	out << totalJobs << " jobs handled." << endl;
	out << "Total waiting time ....... " << totalWait << " minutes." << endl;
	out << "Average waiting time ..... " << (totalWait * 1.0 / totalJobs) << " minutes.\n\n" << endl;
	out << "================================================" << endl;
}
