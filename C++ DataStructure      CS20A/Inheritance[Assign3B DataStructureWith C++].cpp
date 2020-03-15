//YUNPENG LING
//CS 20A Section 4098
//Assignment 3B 
//This program create a subclass object while using some base class function

#include <iostream>


//base class
class Student {

public:
	Student(int intelli)
	{
		iq = intelli;
		howSmartAmI(iq);
	}

	virtual void cheer()
	{
		std::cout << "Go SMC!";
	}



	void howSmartAmI(int iq)
	{
		
		std::cout << "  Smart ass with a " << iq << "IQ scores!\n" << std::endl;

	}

	

private:

	int iq;

};



//Sub class of student
class NerdStudent : public Student{

public:

	NerdStudent() :Student(110) {

		myBooks = 90;
	};

	virtual void cheer() {

		std::cout << "Go Algorithms!";
	}


private:

	int myBooks;




};



//Sub class 
class ComputerScienceStudent : public Student {

public:
	ComputerScienceStudent() :Student(130) {

		myEBooks = 100;
	}

	virtual void cheer() {

		std::cout <<"01001101 01100101 01110010 01110010 01111001 00100000\n";
		std::cout<<"01000011 01101000 01110010 01101001 01110011 01110100 01101101 01100001 01110011\n";
	}



private:

	int myEBooks = 100;
};





//Main function
int main()
{
    //Create object from a subclass
	ComputerScienceStudent ling;
	ling.cheer();


}