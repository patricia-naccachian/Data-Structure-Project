#include<iostream>
#include"Date.h"

using namespace std;

Date::Date()
{
	day = 1;
	month = 1;
	year = 2020;
	
}

Date::Date(int day1, int month1, int year1)
{
	setDate(day1, month1, year1);
}

void Date::setDate(int day1, int month1, int year1)
{
	if (month1 > 0 && month1 <= 12)
	{
		month = month1;
	}
	else
	{
		cout << "You entered invalid number of month" << endl;
		exit(EXIT_FAILURE);
	}

	if (month1 == 1 || month1 == 3 || month1 == 5 || month1 == 7 || month1 == 8 || month1 == 10 || month1 == 12)
	{
		if (day1 > 0 && day1 <= 31)
		{
			day = day1;
		}
		else
		{
			cout << "You entered invalid number of days due to the month" << endl;
			exit(EXIT_FAILURE);
		}
	}

	if (month1 == 4 || month1 == 6 || month1 == 9 || month1 == 11)
	{
		if (day1 > 0 && day1 <= 30)
		{
			day = day1;
		}
		else
		{
			cout << "You entered invalid number of days due to the month" << endl;
			exit(EXIT_FAILURE);
		}
	}

	if (month1 == 2)
	{
		if (day1 > 0 && day1 <= 29)
		{
			day = day1;
		}
		else
		{
			cout << "You entered invalid number of days due to the month" << endl;
			exit(EXIT_FAILURE);
		}
	}

	year = year1;
}

void Date::display()
{

	cout << month << "/" << day << "/" << year;

}