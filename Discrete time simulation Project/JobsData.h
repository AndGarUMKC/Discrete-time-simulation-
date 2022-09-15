#ifndef JOBS_DATA_H
#define JOBS_DATA_H

#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

class jobsData {
private:
    // clock ticks from 0 - 480 ticks
	int arrivalTime;

    // (A)dmin, (F)aculty, or (S)tudent 
	char category;

    // Size of the print job
	int pages;

public:
	jobsData();

    // checks the arrival time
	void setArrivalTime(int arrivalTime);

    // checks the category
	void setCategory(char category);

    // checks and assigns job size
	void setPages(int pages);

	// returns arrival time
	int getArrivalTime() const;

    // returns category
	char getCategory() const;

    // returns pages of the job
	int getPages() const;
	
    // reads the data from the file
	bool ReadData(std::istream& in);
};

#endif
