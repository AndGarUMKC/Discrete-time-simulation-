#ifndef MULTI_LEVEL_H
#define MULTI_LEVEL_H

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include "PrintQueue.h"

// create a multilevel priority queue with the categories given
class MultiLevel : public printQueue {
private:
	queue<jobsData> adminQueue;
	queue<jobsData> facultyQueue;
	queue<jobsData> studentQueue;

    // to check if there are any priority jobs
	bool priorityPending;

public:
    // Intializes the class
	MultiLevel();
	
    // pushes the jobs into the vector then selects based on category and will check if printer is available or not
	int selectJob(vector<jobsData>& jobsPending, vector<statistics>& stats, int currentTime);

    // checks if there are any pending priority jobs 
	bool getPriorityPending() const;
	
    // opens output stream and outputs statistics based on the simulation
	void writeSummary(ofstream& out, vector<statistics>& stats, int categories);
};

#endif
