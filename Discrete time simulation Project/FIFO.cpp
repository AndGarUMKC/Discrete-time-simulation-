#include "FIFO.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

FIFO::FIFO() : printQueue() {

}


int FIFO::selectJob(vector<jobsData>& jobsPending, vector<statistics>& stats, int currentTime) {

    // Process first available job
	jobsData job = jobsPending.front();

    // remove completed job
	jobsPending.erase(jobsPending.begin());	

    // return next availability
	return printQueue::processJob(job, stats, currentTime);
}

void FIFO::writeSummary(ofstream& out, vector<statistics>& stats, int categories) {
    out << "================================================" << endl << endl;
	out << "Results for First In First Out (FIFO) queue Simulation.\n\n";

	printQueue::writeSummary(out, stats, categories);
}
