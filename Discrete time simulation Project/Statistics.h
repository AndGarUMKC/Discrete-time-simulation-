#ifndef STATISTICS_H
#define STATISTICS_H
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

class statistics {
private:
    // total wait time
	int waitTime;
    
    // jobs processed at a time
	int jobsHandled;

    // longest wait time for a job
	int maxWaitTime;

public:
	statistics();

	void jobHandled();

    // adds wait time to total
	void addWaitTime(int waitTime);

    // updates wait time
	void updateMaxWaitTime(int waitTime);

    // returns wait time
	int getWaitTime() const;

    // returns jobs handled
	int getJobsHandled() const;

    // retuns max time
	int getMaxWaitTime() const;

    // resets stats
	void clearStats();
};

#endif
