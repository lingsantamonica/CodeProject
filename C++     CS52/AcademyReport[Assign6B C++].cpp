

//YUNPENG LING
//CS 52, Section 4118
//Assignment #6, Problem #B
//This program function as school management system. It lets user create student
//record, display all student record, search student record from data, modify
//and delete student record

#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;





//Student class
class student
{
	
	int rollno;
	char name[50];
	int p_Grade, c_Grade, m_Grade, e_Grade, cs_Grade;
	double per;
	char grade;
	void calculate();	
	

public:
	void getdata();	
	void showdata() const;	
	void show_tabular() const;
	int retrollno() const;
	
	
}; 



//This function calculates student grade
void student::calculate()
{
	per=(p_Grade+c_Grade+m_Grade+e_Grade+cs_Grade)/5.0;
	if(per>=60)
		grade='A';
	else if(per>=50)
		grade='B';
	else if(per>=33)
		grade='C';
	else
		grade='F';
}




//This function get data from user input
void student::getdata()
{
	cout<<"\nEnter The roll number of student ";
	cin>>rollno;
	cout<<"\n\nEnter The Name of student ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\nEnter The Grade in physics out of 100 : ";
	cin>>p_Grade;
	cout<<"\nEnter The Grade in chemistry out of 100 : ";
	cin>>c_Grade;
	cout<<"\nEnter The Grade in maths out of 100 : ";
	cin>>m_Grade;
	cout<<"\nEnter The Grade in english out of 100 : ";
	cin>>e_Grade;
	cout<<"\nEnter The Grade in computer science out of 100 : ";
	cin>>cs_Grade;
	
	//Send data to calculate function
	calculate();
}




//This function display student data on the screen
void student::showdata() const
{
	cout<<"\nRoll number of student : "<<rollno;
	cout<<"\nName of student : "<<name;
	cout<<"\nGrade in Physics : "<<p_Grade;
	cout<<"\nGrade in Chemistry : "<<c_Grade;
	cout<<"\nGrade in Maths : "<<m_Grade;
	cout<<"\nGrade in English : "<<e_Grade;
	cout<<"\nGrade in Computer Science :"<<cs_Grade;
	cout<<"\nPercentage of student is  :"<<per;
	cout<<"\nGrade of student is :"<<grade;
}





void student::show_tabular() const
{
	
	cout<<rollno<<setw(6)<<" "<<name<<setw(10)<<p_Grade<<setw(4)<<c_Grade<<setw(4)<<m_Grade<<setw(4)<<e_Grade<<setw(4)<<cs_Grade<<setw(8)<<per<<setw(6)<<grade<<endl;

}

	 
int  student::retrollno() const
{
	//Return roll number
	return rollno;
	
}





//function declaration
void write_student();	
void display_all();		
void display_sp(int);	
void modify_student(int);	
void delete_student(int);	
void class_result();	
void result();	
void signature();	
void entry_menu();	




//Main function
int main()
{
	
	
	char ch;
	cout.setf(ios::fixed|ios::showpoint);
	cout<<setprecision(2); 
	signature();
	
	
	do
	{
		
		system("cls");
		cout<<"\n\tMAIN MENU";
		cout<<"\n\t01. RESULT MENU";
		cout<<"\n\t02. ENTRY/EDIT MENU";
		cout<<"\n\t03. EXIT";
		cout<<"\n\tPlease Enter Your Option (1-3) ";
		cin>>ch;
		
		
		
		switch(ch)
		{
			case '1': result();
				break;
			case '2': entry_menu();
				break;
			case '3':
				break;
			default :cout<<"\a";
		}
    }while(ch!='3');
	
	
	return 0;
	
	
}




//This function write the record into binary file
void write_student()
{
	
	student st;
	ofstream outFile;
	outFile.open("student.dat",ios::binary|ios::app);
	st.getdata();
	outFile.write(reinterpret_cast<char *> (&st), sizeof(student));
	outFile.close();
	
    cout<<"\n\nStudent record Created successfully";
	cin.ignore();
	cin.get();
	
}



//function to read all records from file
void display_all()
{
	
	
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	
	
	if(!inFile)
	{
		cout<<"File could not be opened !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	
	
	cout<<"\n\tDISPLAY ALL RECORD !!!\n";
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
	{
		st.showdata();
		cout<<"\n\n====================================\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
	
	
}




//This function accept roll number and read record from binary file
void display_sp(int n)
{
	
	
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	
	
	if(!inFile)
	{
		cout<<"File could not be opened !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
		
		
	}
	
	
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
	{
		if(st.retrollno()==n)
		{
	  		 st.showdata();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nrecord not exist";
	cin.ignore();
	cin.get();
	
	
}



//This function accept roll number and update record of binary file
void modify_student(int n)
{
	
	
	bool found=false;
	student st;
	fstream File;
	File.open("student.dat",ios::binary|ios::in|ios::out);
	
	
	if(!File)
	{
		
		
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		
		return;
		
		
	}

	while(!File.eof() && found==false)
	{
		
		File.read(reinterpret_cast<char *> (&st), sizeof(student));
		
		if(st.retrollno()==n)
		{
			st.showdata();
			cout<<"\n\nPlease Enter The New Details of student"<<endl;
			st.getdata();
		    int pos=(-1)*static_cast<int>(sizeof(st));
		    File.seekp(pos,ios::cur);
		    File.write(reinterpret_cast<char *> (&st), sizeof(student));
			
		    cout<<"\n\t Record Updated";
		    found=true;
			
			
		}
	}
	
	
	File.close();
	if(found==false)
		cout<<"\n Error  Record Not Found ";
	cin.ignore();
	cin.get();

}




//This function accept roll number and delete selected records from binary file
void delete_student(int n)
{
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be opened !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("Temp.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
	{
		if(st.retrollno()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&st), sizeof(student));
		}
	}
	outFile.close();
	inFile.close();
	remove("student.dat");
	rename("Temp.dat","student.dat");
	cout<<"\n\n\tRecord Deleted ..";
	cin.ignore();
	cin.get();
}




//This function display all records in tabular format from binary file
void class_result()
{
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\t\tALL STUDENTS RESULT \n\n";
	cout<<"==========================================================\n";
	cout<<"R.No       Name        P   C   M   E   CS   %age   Grade"<<endl;
	cout<<"==========================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
	{
		st.show_tabular();
	}
	cin.ignore();
	cin.get();
	inFile.close();
}




//This function display result 
void result()
{
	char ch;
	int rno;
	system("cls");
	cout<<"\n\tRESULT MENU";
	cout<<"\n\t1. Class Result";
	cout<<"\n\t2. Student Report Card";
	cout<<"\n\t3. Back to Main Menu";
	cout<<"\n\\tEnter Choice (1/2/3)? ";
	
	cin>>ch;
	system("cls");
	switch(ch)
	{
	case '1' :	class_result(); break;
	case '2' :	cout<<"\n\n\tEnter Roll Number Of Student : "; cin>>rno;
				display_sp(rno); break;
	case '3' :	break;
	default:	cout<<"\a";
	}
}



//Signature function
void signature()
{
	
	
	cout<<"\n\tSTUDENT ACADEMY REPORT PROJECT";
	cout<<"\n\tMADE BY : 1526000  YUNPENG LING";
	cout<<"\n\tSCHOOL : SMC   PRESS ANY KEY TO CONTINUE";
	
	cin.get();
		
	
}



//Main Menu
void entry_menu()
{
	char ch;
	int num;
	system("cls");
	
	
	cout<<"\n\tENTRY MENU";
	cout<<"\n\t1.CREATE STUDENT RECORD";
	cout<<"\n\t2.DISPLAY ALL STUDENTS RECORDS";
	cout<<"\n\t3.SEARCH STUDENT RECORD ";
	cout<<"\n\t4.MODIFY STUDENT RECORD";
	cout<<"\n\t5.DELETE STUDENT RECORD";
	cout<<"\n\t6.BACK TO THE MAIN MENU";
	cout<<"\n\tPlease Enter Your Choice (1-6) ";
	
	
	cin>>ch;
	system("cls");
	
	switch(ch)
	{
	case '1':	write_student(); break;
	case '2':	display_all(); break;
	case '3':	cout<<"\n\tPlease Enter The roll number "; cin>>num;
				display_sp(num); break;
	case '4':	cout<<"\n\tPlease Enter The roll number "; cin>>num;
				modify_student(num);break;
	case '5':	cout<<"\n\tPlease Enter The roll number "; cin>>num;
				delete_student(num);break;
	case '6':	break;
	
	default:	cout<<"\a"; entry_menu();
	}
	
	
	
}









