using namespace std;
#include<string> 
#ifndef MYDATE_H
#define MYDATE_H

class myDate {
private:
	int month, day, year;
public:
	myDate();
	myDate(int, int, int);
	void display();
	void increaseDate(int);
	void decreaseDate(int);
	int daysBetween(myDate);
	string formatDate();
	int getMonth();
	int getDay();
	int getYear();
	int dayOfYear();
	int birthdayCalc();
	string dayName();
};
#endif 
