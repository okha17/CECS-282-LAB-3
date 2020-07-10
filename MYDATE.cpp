#include<string>
#include "myDate.h"
#include<iostream>
using namespace std;

// Gregorian to Julian function that returns an int value for a Julian date
int Greg2Julian(int month, int day, int year)
{
	int JD = day - 32075 + 1461 * (year + 4800 + (month - 14) / 12) / 4 + 367
		* (month - 2 - (month - 14) / 12 * 12) / 12 - 3
		* ((year + 4900 + (month - 14) / 12) / 100) / 4;
	return JD;
}
// Julian to Gregorian function that works through pass by reference 
void Julian2Greg(int JD, int& month, int& day, int& year)
{
	int I, J, K;
	int L = JD + 68569;
	int N = 4 * L / 146097;
	L = L - (146097 * N + 3) / 4;
	I = 4000 * (L + 1) / 1461001;
	L = L - 1461 * I / 4 + 31;
	J = 80 * L / 2447;
	K = L - 2447 * J / 80;
	L = J / 11;
	J = J + 2 - 12 * L;
	I = 100 * (N - 49) + I + L;

	year = I;
	month = J;
	day = K;
}
// Default constructor that sets date to default value
myDate::myDate()
{
	month = 5;
	day = 11;
	year = 1959;
}
// Argument constructor that set date to values passed in and
// checks for bogus date to make sure not out of bounds
myDate::myDate(int m, int d, int y)
{
	int val = Greg2Julian(m, d, y);
	Julian2Greg(val, m, d, y);
	if (m > 12)
	{
		month = 2;
		day = 28;
		year = 1999;
	}
	else
	{
		month = m;
		day = d;
		year = y;
	}
}
// Display member function that displays the correct date format and contains
// array of strings of month names
void myDate::display()
{
	string months[] = { "January", "February", "March", "April",
					 "May", "June", "July", "August", "September",
					"October", "November", "December" };

	cout << months[month - 1] << " " << day << ", " << year;
}

// Member function that increases the date by valued passed in using
// Greg2Julian conversion
void myDate::increaseDate(int N)
{
	int date = Greg2Julian(month, day, year);
	date = date + N;
	Julian2Greg(date, month, day, year);
}
// Member function that decreases the date by value passed in using 
// Greg2Julian conversion
void myDate::decreaseDate(int N)
{
	int date = Greg2Julian(month, day, year);
	date = date - N;
	Julian2Greg(date, month, day, year);
}
// Member function that calculates the days between calling date and set date
// sets both dates to Julian values and takes difference between them
int myDate::daysBetween(myDate D)
{
	int date_D = Greg2Julian(D.getMonth(), D.getDay(), D.getYear());
	int other_date = Greg2Julian(month, day, year);
	int result = date_D - other_date;
	return result;
}

// Member function that converts calling date into Julian for the Bubble sort for birthdays
int myDate::birthdayCalc() 
{
	int date = Greg2Julian(month, day, year);
	return date;
}

// Getter that returns month
int myDate::getMonth()
{
	return month;
}
// Getter that returns day
int myDate::getDay()
{
	return day;
}
// Getter that returns year
int myDate::getYear()
{
	return year;
}

// Member function that calculates the day of the year in Julian notation
// The difference between the first day of the year and set date are taken
// to find correct date. 1 is added in order to account for leap years
int myDate::dayOfYear()
{
	int date = Greg2Julian(month, day, year);
	int startOfYear = Greg2Julian(1, 1, year);
	int result = date - startOfYear;
	return result + 1;
}
// Member function that returns what day of the week it is in a string
// array of strings for days is made and Julian value of set date
// is taken with mod 7 to find correct return date
string myDate::dayName()
{
	string days[] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
	int value = Greg2Julian(month, day, year);
	int dayOf = value % 7;
	return days[dayOf];
}

// Formats the date to the correct 
string myDate::formatDate() 
{
	string months[] = { "January", "February", "March", "April",
					"May", "June", "July", "August", "September",
					"October", "November", "December" };
	string v1 = months[month -1];
	string v2 = to_string(day);
	string v3 = to_string(year);
	string v4 = " ";
	string v5 = ",";
	string v = v1 + v4 + v2 + v5 + v4 + v3;
	return v;
}
