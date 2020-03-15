#include "pch.h"
#include <iostream>

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

//Head file definition
class Employee {
private:
	std::string name;
	std::string idNumber;
	std::string department;
	std::string position;
	int yearsWorked;
public:
	//constructors
	Employee(std::string, std::string, std::string, std::string, int);
	Employee(std::string, std::string);
	Employee();

	//acessors & mutators
	void setName(std::string);
	void setId(std::string);
	void setDept(std::string);
	void setPos(std::string);
	void setYear(int);

	std::string getName();
	std::string getId();
	std::string getDept();
	std::string getPos();
	int getYear();

	//show employee
	void showEmployee();
};


#endif
