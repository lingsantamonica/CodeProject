#include "pch.h"
#include "Stats.h"




//Stats class constructor
Stats::Stats() {
	rain[11] = { 0.0 };
}

//mutator
void Stats::setValue(int index, double value) {
	if (value < 0) 
		rain[index] = 0;
	else
		rain[index] = value;
	return;
}

//accessors
void Stats::getValues() {
	std::cout << "Annual Rainfall Report:" << std::endl;
	for (int i = 0; i < (sizeof(rain) / sizeof(rain[0])); i++) {
		std::cout << "Month " << i + 1 << ": " << rain[i] << std::endl;
	}

	return;
}
double Stats::getTotal() {
	double total = 0;

	for (int i = 0; i < (sizeof(rain) / sizeof(rain[0])); i++)
		total += rain[i];

	return total;
}
double Stats::getAvg() {
	double total = 0, average;

	for (int i = 0; i < (sizeof(rain) / sizeof(rain[0])); i++)
		total += rain[i];

	average = total / (sizeof(rain) / sizeof(rain[0]));

	return average;
}
double Stats::getLargest() {
	for (int i = 1; i < (sizeof(rain) / sizeof(rain[0])); ++i) {
		if (rain[0] < rain[i])
			rain[0] = rain[i];
	}
	return rain[0];
}
double Stats::getSmallest() {
	for (int i = 1; i < (sizeof(rain) / sizeof(rain[0])); ++i) {
		if (rain[0] > rain[i])
			rain[0] = rain[i];
	}
	return rain[0];
}

