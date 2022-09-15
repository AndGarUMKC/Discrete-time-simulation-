// Andres Garcia
// Aiggkp@umsystem.edu
// Student ID: 16303232
// 12/13/20
// Program 6

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

#include "JobsData.h"
#include "Statistics.h"
#include "FIFO.h"
#include "SJF.h"
#include "MultiLevel.h"

using namespace std;

int main() {
	// Constant Variables

    // Hours of operation: 9AM to 5 PM 
	const int timeOpen = 480;

    // FIFO, SJF, PRIORITY Simulations		
	const int totalSimulations = 3;

    // Administration, Faculty, Student
	const int categories = 3;			

	// Stream Variables used
	ifstream in;
	ofstream out;

    // Input file
	string file1 = "Program6Data.txt";

    // Output data file
	string file2 = "Program6output.txt";

	//Printer Variables

    // All jobs, including those not yet arrived 
	queue<jobsData> inputData;

    // Jobs that have arrived but not yet handled
	vector<jobsData> jobsPending;

    // read and process the jobs
	jobsData job;
    
    // Condition to continue printing processing
	bool jobsRemain = true;
    
    // Current time on printer
	int currentTime = 0;

    // Clock tick when printer will be available for next job
	int nextAvailableTime = 0;

    // Vector that stores the jobs by their category and will then be used to print out the stats
	vector<statistics> jobStats(categories);

	// Simulations being processed
	FIFO jobFIFO;
	SJF jobSJF;
	MultiLevel jobMultiLevel;


	// Open and check if a output file is available or in the right directory
    out.open(file2);
	if (!out.is_open()) {
		cout << "Could not open file: " << file2 << endl;
	}

	else {
		for (int simulation = 0; simulation < totalSimulations; simulation++) {
            
			// Open and check input file if in the right directory
			in.open(file1);
			if (!in.is_open()) {
				cout << "Could not open file: " << file1 << endl;
			}

			else {

				//Read data file into inputData queue
				while (job.ReadData(in)) {
					inputData.push(job);
				}
			}

            // close the file
			in.close();

			// Process print jobs based on the different simulation scenarios
			while (jobsRemain) {

				//Check if a job exists if not stop printing
				if (inputData.size() == 0 && jobsPending.size() == 0 && !jobMultiLevel.getPriorityPending()) {

                    // jobsRemain is set to false if it cannot read any jobs
                    // if there are no pending jobs or no more jobs waiting in the priority queue.
					jobsRemain = false;
				}

				else {

					// Check for all new jobs at currentTime and add them to jobsPending queue.
					while ((inputData.size() > 0) && (inputData.front().getArrivalTime() == currentTime)) {
						jobsPending.push_back(inputData.front());
						inputData.pop();
					}

					// Process pending job if printer is available and in the queue or in the priority queue
					if ((currentTime >= nextAvailableTime) && (jobsPending.size() > 0 || jobMultiLevel.getPriorityPending())) {

                        // create a switch for each simulation
						switch (simulation) {
                        
                        // First in First Out(FIFO) Queue
						case 0:
							nextAvailableTime = jobFIFO.selectJob(jobsPending, jobStats, currentTime);
							break;

                        // Shortest First Job Simulation
						case 1:
							nextAvailableTime = jobSJF.selectJob(jobsPending, jobStats, currentTime);
							break;

                        // Multi-Level Priority Queue
						case 2:
							nextAvailableTime = jobMultiLevel.selectJob(jobsPending, jobStats, currentTime);
							break;
						}
					}
				}

                // increment tick
				currentTime++;
			}

			// Output summary statistics to output file using switch cases
            // this allows for better control of data
			switch (simulation) {

        
			case 0:
				jobFIFO.writeSummary(out, jobStats, categories);
				break;

			case 1:
				jobSJF.writeSummary(out, jobStats, categories);
				break;

			case 2:
				jobMultiLevel.writeSummary(out, jobStats, categories);
				break;
			}

			//Reset printer for next queue
			currentTime = 0;
			jobsRemain = true;
			nextAvailableTime = 0;
		}
	}

    //close the output file
	out.close();

	return 0;
}
