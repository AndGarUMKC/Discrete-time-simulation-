#ifndef SJF_H
#define SJF_H

#include "PrintQueue.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

class SJF : public printQueue {
private:
	int shortestIndex;

public:
    // intializes
	SJF();

    // Jobs put into jobs pending vector, job is selected with the least pages, and checks if printer is available
	int selectJob(vector<jobsData>& jobsPending, vector<statistics>& stats, int currentTime);

    // Finds the job with the least amount of pages
	int findShortestJob(vector<jobsData>& jobsPending);

    // Outputs the stats of all the jobs processed based on SFJ
	void writeSummary(ofstream& out, vector<statistics>& stats, int categories);
};

#endif
