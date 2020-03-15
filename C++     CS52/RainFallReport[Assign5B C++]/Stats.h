#include "pch.h"
#include <iostream>

#ifndef STATS_H_
#define STATS_H_

class Stats {
private:
	double rain[12];
public:
	Stats();
	void setValue(int, double);
	void getValues(); 
	double getTotal(); 
	double getAvg(); 
	double getLargest(); 
	double getSmallest();
};

#endif;