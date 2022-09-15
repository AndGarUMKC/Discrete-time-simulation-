#include "SJF.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

SJF::SJF() : printQueue() {
	shortestIndex = 0;
}


int SJF::selectJob(vector<jobsData>& jobsPending, vector<statistics>& stats, int currentTime) {
    
	// jobs to be processed
    jobsData job;
	
	// Find shortest pending job
	shortestIndex = findShortestJob(jobsPending);

	// Assign shortest job to object and remove from pending queue
	job = jobsPending.at(shortestIndex);
	jobsPending.erase(jobsPending.begin() + shortestIndex);

	// Process selected job and return next available time
	return printQueue::processJob(job, stats, currentTime);
}

int SJF::findShortestJob(vector<jobsData>& jobsPending) {
	int leastPages = jobsPending.at(0).getPages();
	shortestIndex = 0;
	
	for (int i = 1; i < jobsPending.size(); i++) {
		if (jobsPending.at(i).getPages() < leastPages) {
			shortestIndex = i;
			leastPages = jobsPending.at(i).getPages();
		}
	}

	return shortestIndex;
}


void SJF::writeSummary(ofstream& out, vector<statistics>& stats, int categories) {
	out << "\nResults for Shortest Job First (SJF) queue Simulation.\n\n";

	printQueue::writeSummary(out, stats, categories);
}
