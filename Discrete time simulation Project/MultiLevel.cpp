#include "MultiLevel.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

// Multi-Level Queue called to be proccesed
MultiLevel::MultiLevel() : printQueue() {

    // Set Priority to false because there are no jobs to process to begin with
	priorityPending = false;
}


int MultiLevel::selectJob(vector<jobsData>& jobsPending, vector<statistics>& stats, int currentTime) {
	// Jobs to be processed
    jobsData job;

	// Assigns pending jobs into priority queues according to the category
	while (jobsPending.size() > 0) {

		switch (jobsPending.front().getCategory()) {

		case 'A':
			adminQueue.push(jobsPending.front());
			break;

		case 'F':
			facultyQueue.push(jobsPending.front());
			break;

		case 'S':
			studentQueue.push(jobsPending.front());
			break;
		}
        
        // Remove job after being put into it's priority queue
		jobsPending.erase(jobsPending.begin());	

        // Jobs ready to be printed
		priorityPending = true;
	}

	// Assign next job to be processed based on priority
    // Process admin jobs first
	if (adminQueue.size() > 0) {
		job = adminQueue.front();

        // remove job
		adminQueue.pop();
	}

    // If no admin jobs pending then process next priority which is faculty
	else if (facultyQueue.size() > 0) {
		job = facultyQueue.front();

        // remove job
		facultyQueue.pop();
	}

    // if no admin or faculty jobs pending process the student job
	else if (studentQueue.size() > 0) {
		job = studentQueue.front();

        // remove job
		studentQueue.pop();
	}

    // If no more priority jobs left
	else {
		priorityPending = false;
	}
	
	//Process selected job and return the the next Available time
	return printQueue::processJob(job, stats, currentTime);
}


bool MultiLevel::getPriorityPending() const {
	return priorityPending;
}

void MultiLevel::writeSummary(ofstream& out, vector<statistics>& stats, int categories) {
	out << "\nResults for Multi-level queue Simulation.\n\n";

	printQueue::writeSummary(out, stats, categories);
}
