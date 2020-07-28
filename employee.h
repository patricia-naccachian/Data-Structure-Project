//This file includes the struct (just like class) of employee 
#ifndef H_employee
#define H_employee

#include<iostream>
#include<string>
using namespace std;

struct  employee 
{
	//constructors and destrcutor
	employee();
	employee(int, string);
	~employee() {};

	int employee_id;
	string employee_name;
};

#endif