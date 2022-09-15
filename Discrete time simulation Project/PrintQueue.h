#ifndef PRINT_QUEUE_H
#define PRINT_QUEUE_H

#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include "JobsData.h"
#include "Statistics.h"

using namespace std;

class printQueue {
private:

    // how much the printer can handle a minute
	const double printCapacity = 150;
	
    // intializes wait time which is used to know when to do next job
    int waitTime;
	
    // Initialize time required for a job to be done
    double serviceTime;

public:
	printQueue();

    //  selects job based by the simulation and returns availabilty
	int processJob(jobsData job, vector<statistics>& stats, int currentTime);
	
    // outputs stats
	virtual void writeSummary(ofstream& out, vector<statistics>& stats, int categories) = 0;
};

#endif
