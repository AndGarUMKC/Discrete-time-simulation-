#include "JobsData.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;

jobsData::jobsData() {
	arrivalTime = 0;
	category = ' ';
	pages = 0;
}

void jobsData::setArrivalTime(int arrivalTime) {
	this->arrivalTime = arrivalTime;
}

void jobsData::setCategory(char category) {
	this->category = category;
}

void jobsData::setPages(int pages) {
	this->pages = pages;
}

int jobsData::getArrivalTime() const {
	return arrivalTime;
}

char jobsData::getCategory() const {
	return category;
}

int jobsData::getPages() const {
	return pages;
}

bool jobsData::ReadData(istream& in) {
	int time;
	char jobType;
	int size;

	in >> time;
	in >> jobType;
	in >> size;

	setArrivalTime(time);
	setCategory(jobType);
	setPages(size);

	return in.good();
}
