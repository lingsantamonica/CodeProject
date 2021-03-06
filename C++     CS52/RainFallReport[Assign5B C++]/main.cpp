//YUNPENG LING
//CS 52, Section 4118
//Assignment #5, Problem B
//This program keeps track of rainfall during a 12-month period. User will be asked to specify rainfall amount for each month of the year. And those amounts will be totaled & averaged. The most/least amount of rainfall will be noted.

#include "pch.h"
#include <iostream>
#include <iomanip>
#include "Stats.h"

#define MONTHS 12

int main()
{

	Stats rainfall;

	for (int i = 0; i < MONTHS; i++) {
		double userAmt;
		std::cout << "Enter Month " << i + 1 << "'s rainfall amount: ";
		std::cin >> userAmt;

		rainfall.setValue(i, userAmt);
	}

	std::cout << std::endl;

	std::cout << std::setprecision(2) << std::fixed;

	rainfall.getValues();

	std::cout << std::endl;
	std::cout << "Total: " << rainfall.getTotal() << std::endl;
	std::cout << "Average: " << rainfall.getAvg() << std::endl;
	std::cout << "Highest: " << rainfall.getLargest() << std::endl;
	std::cout << "Lowest: " << rainfall.getSmallest() << std::endl;

	return 0;
}

