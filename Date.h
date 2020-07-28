//This file includes the class of date 
#ifndef H_Date
#define H_Date

#include<iostream>
using namespace std;

class Date
{
public:
	//constructors and destructors
	Date();
	Date(int, int, int);
	~Date() {};

	void setDate(int, int, int);
	void display();

	int month;   //keeping them public since other classes (linked list and etc) will acess them making it easier rather than inhetiance
	int day;
	int year; 
	
};


#endif
