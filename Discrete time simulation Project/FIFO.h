#ifndef FIFO_H
#define FIFO_H

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include "PrintQueue.h"


class FIFO : public printQueue {
private:


public:
	FIFO();

    // Same as other queues except it selects the job in front and then removes when done and returns availability
	int selectJob(vector<jobsData>& jobsPending, vector<statistics>& stats, int currentTime);

    // Outputs stats of FIFO
	void writeSummary(ofstream& out, vector<statistics>& stats, int categories);
};

#endif
