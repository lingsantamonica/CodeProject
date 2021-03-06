//YUNPENG LING
//CS 52, Section 4118
//Assignment #5, Problem A
//This program will create an Employee class that takes gets/sets employee's name, ID number, department, position, and years worked. Will output results for three employees to screen.

#include "pch.h"
#include "Employee.h"
#include <iostream>
#include <iomanip>




int main()
{
	Employee a("Jenny Jacobs", "JJ8990", "Accounting", "President", 15);
	Employee b("Myron Smith", "MS7571");
	Employee c;

	b.setDept("IT");
	b.setPos("Programmer");
	b.setYear(-10);
	b.setYear(5);

	c.setName("Chris Raines");
	c.setId("CR6873");
	c.setDept("Manufacturng");
	c.setPos("Engineer");
	c.setYear(30);

	//table header
	std::cout << std::setw(20) << std::left << "Name" <<
		std::setw(15) << std::left << "ID Number" <<
		std::setw(20) << "Department" <<
		std::setw(20) << "Position" <<
		std::setw(15) << "Years Worked" << std::endl;
	std::cout << std::setw(20) << std::left << "-------" <<
		std::setw(15) << std::left << "-------" <<
		std::setw(20) << "-------" <<
		std::setw(20) << "-------" <<
		std::setw(15) << "-------" << std::endl;

	a.showEmployee();
	b.showEmployee();
	c.showEmployee();

	return 0;
}


