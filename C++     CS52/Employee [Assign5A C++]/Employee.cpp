#include "pch.h"
#include "Employee.h"
#include <iostream>
#include <string>
#include <iomanip>



//Employee class constructors
Employee::Employee(std::string en, std::string ei, std::string ed, std::string ep, int ey)
{
	name = en;
	idNumber = ei;
	department = ed;
	position = ep;
	yearsWorked = ey;
}

Employee::Employee(std::string en, std::string ei)
{
	name = en;
	idNumber = ei;
	department = "";
	position = "";
	yearsWorked = 0;
}

Employee::Employee()
{
	name = "";
	idNumber = "";
	department = "";
	position = "";
	yearsWorked = 0;
}

//mutators - setters
void Employee::setName(std::string n)
{
	name = n;
	return;
}
void Employee::setId(std::string i)
{
	idNumber = i;
	return;
}
void Employee::setDept(std::string d)
{
	department = d;
	return;
}
void Employee::setPos(std::string p)
{
	position = p;
	return;
}
void Employee::setYear(int y)
{
	if (y < 0) {
		yearsWorked = 0;
		std::cout << "Attempt to set yearsWorked for " << name << " was invalid. It was set to 0. " << std::endl;
	}
	else 
		yearsWorked = y;
	return;
}

//acessors - getters
std::string Employee::getName()
{
	return name;
}
std::string Employee::getId()
{
	return idNumber;
}
std::string Employee::getDept()
{
	return department;
}
std::string Employee::getPos()
{
	return position;
}
int Employee::getYear() 
{
	return yearsWorked;
}

//show function
void Employee::showEmployee()
{
	std::cout << std::setw(20) << name <<
			std::setw(15) << idNumber << 
			std::setw(20) << department <<
			std::setw(20) << position <<
			std::setw(15) << yearsWorked << std::endl;

	return;
}


