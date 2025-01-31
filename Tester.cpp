// Osman Khan
// CECS 282-07
// Proj 3 -Structs and Pointers 
// 10/14/19

#include<iostream>
#include <string>
#include "myDate.h"
#include "time.h"
#include <iomanip> 
using namespace std;

struct Student {
	char grade;
	char name[20];
	int student_ID;
	string homeTown;
	myDate birthday;
};

// Function that takes student pointer of arrays to fill the list with students and student
// information. Arrays created to set all student information.
void populate(Student *c[]) 
{
	char grades [] = {'A', 'C', 'A', 'B', 'D', 'C', 'B', 'F', 'D' };
	string homeTowns[] = {"Chino", "Pasadena", "Buena Park", "Norwalk", "Anaheim", "Long Beach",
						 "San Diego", "Fullerton", "La Palma"};
	int ID[] = {231993, 734923, 482393, 348393, 230458, 923857, 875049, 190220, 298347};
	char names[][20] = {"Anthony Davis", "Kobe Bryant", "Derek Fisher", "Ron Artest", "Lebron James", "Pau Gasol",
					   "Lamar Odom", "Shaquille O'neal", "Magic Johnson"};
	srand(time(0));

	for (int i = 0; i < 9; i++)
	{
		c[i] = new Student;
		c[i]->grade = grades[i];
		c[i]->student_ID = ID[i];
		c[i]->homeTown = homeTowns[i];
		c[i]->birthday = myDate((rand() % 12) + 1, (rand() % 31) + 1, (rand() % 6) + 1999);
		strcpy_s(c[i]->name, names[i]);
	}
}

// Function that copies one pointer to a student array to another
void dup(Student* p[], Student* q[], int size) 
{
	for (int i = 0; i < size; i++) 
	{
		p[i] = q[i];
	}
}

// Function that displays the entire list using the iomanip function setw and displaying all columns
// left aligned
void disp(Student* p[]) 
{
	cout << '\n' << left << setw(22) << "Student ID" << left << setw(22) << "Name" << left << setw(22) << "Grade" <<
	left <<	setw(22) << "Birthday" << left << setw(22) << "Home Town" << '\n';

	cout << left << setw(22) << "----------" << left << setw(22) << "----" << left << setw(22) << "-----" <<
	left << setw(22) << "--------" << left << setw(22) << "---------" << '\n';

	for (int i = 0; i < 9; i++)
	{
		cout << left << setw(22) << p[i]->student_ID << left << setw(22) <<  p[i]->name << left << setw(22) 
		<< p[i]->grade << left << setw(22) <<p[i]->birthday.formatDate() << left << setw(22) <<  p[i]->homeTown <<endl;
	}
}

// Bubble Sort function for student IDs
void SortbyID(Student* p[]) 
{
	for (int i = 0; i < 9; i++) 
	{
		for (int k = 0; k < 9 - i - 1; k++) 
		{
			if (p[k]->student_ID > p[k + 1]->student_ID)
			{
				Student* temp;
				temp = p[k];
				p[k] = p[k + 1];
				p[k + 1] = temp;
			}
		}
	
	}
}

// Bubble sort function for student grades
void SortbyGrade(Student* p[])
{
	for (int i = 0; i < 9; i++)
	{
		for (int k = 0; k < 9 - i - 1; k++)
		{
			if (p[k]->grade > p[k + 1]->grade)
			{
				Student *temp;
				temp = p[k];
				p[k] = p[k + 1];
				p[k + 1] = temp;
			}
		}
	}
}

// Bubble sort function for student birthdays
void SortbyBirthday(Student* p[])
{
	for (int i = 0; i < 9; i++)
	{
		for (int k = 0; k < 9 - i - 1; k++)
		{
			if (p[k]->birthday.birthdayCalc() > p[k+1]->birthday.birthdayCalc())
			{
				Student* temp; 
				temp = p[k];
				p[k] = p[k + 1];
				p[k + 1] = temp;
			}
		}
		
	}
}

// Bubble sort function for student home towns
void SortbyHomeTown(Student* p[])
{
	for (int i = 0; i < 9; i++)
	{
		for (int k = 0; k < 9 - i - 1; k++)
		{
			if (p[k]->homeTown > p[k + 1]->homeTown)
			{
				Student* temp;
				temp = p[k];
				p[k] = p[k + 1];
				p[k + 1] = temp;
			}
		}

	}
}

// Bubble sort function for student names
void SortbyName(Student* p[])
{
	for (int i = 0; i < 9; i++)
	{
		for (int k = 0; k < 9 - i - 1; k++)
		{
			int val = strcmp(p[k]->name, p[k + 1]->name);
			if (val > 0)
			{
				Student* temp;
				temp = p[k];
				p[k] = p[k + 1];
				p[k + 1] = temp;
			}
		}
	}
}

int main() {
	Student* myClass[9];
	populate(myClass);
	Student* myClass_1[9];
	dup(myClass_1, myClass, 9);
	int choice = 0;
	while (choice != 7) // while the choice is not 7 the program and menu keep running
	{
		cout << "\n";
		cout << "Student Sorting:\n";
		cout << " 1) Display original list \n";
		cout << " 2) Display list sorted by Student ID\n";
		cout << " 3) Display list sorted by Name\n";
		cout << " 4) Display list sorted by Grade\n";
		cout << " 5) Display list sorted by Birthday\n";
		cout << " 6) Display list sorted by Home Town\n";
		cout << " 7) Exit\n";
		cout << "Please enter your selection ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			//cout << "\nList 1:" << endl;
			//disp(myClass);
			cout << "\nOriginal List:" << endl;
			disp(myClass_1);
			break;
		case 2:
			SortbyID(myClass);
			cout << "\nList is now ordered by ID:" << endl;
			disp(myClass);
			break;
		case 3:
			SortbyName(myClass);
			cout << "\nList is now ordered by Name:" << endl;
			disp(myClass);
			break;
		case 4:
			SortbyGrade(myClass);
			cout << "\nList is now ordered by Grade:" << endl;
			disp(myClass);
			break;
		case 5:
			SortbyBirthday(myClass);
			cout << "\nList is now ordered by Birthday:" << endl;
			disp(myClass);
			break;
		case 6:
			SortbyHomeTown(myClass);
			cout << "\nList is now ordered by Home Town:" << endl;
			disp(myClass);
			break;
		case 7:
			cout << "Thanks for playing" << endl;
			break;
		default:
			cout << "\nNot a Valid Choice. \n";
			cout << "Please choose again.\n";
		}
	}
	return 0;
}
