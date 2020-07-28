//This file includes the struct of street and store
#ifndef H_Street_Store
#define H_Street_Store

#include<iostream>
#include<string>

#include"Date.h"
#include"employee.h"
using namespace std;


struct  Street_Store
{
	//constructtors and dectructors 
	Street_Store();
	Street_Store(int, string, string, string, int, int, int);
	~Street_Store() {};

	int size = 0;
	int Store_id;
	string Street_name;
	string Manager_name;
	string Telephone;
	Date date_open;
	bool valid = false;
	employee* A_emplyee = new employee[size]; //using alocated memory in the size just like in lab1 so that we can fit employees in the array
	//This will also help in increasing the size of the array and decreasing it depending on number of employees. 
	//we found the implementation of a similar idea on the internet which made it possible for us to apply it in the project


	employee* extendarray(employee*, int&); //function that is used to increase the array size as we stated above
	employee* decremnetdarray(employee*, int&); // opposite of the above
	void insertemployee(employee); // add a employee
	bool searchemployeecheck(employee); //searching for employee to check if it exists 
	int searchemployeeindex(employee); // displaying the positions of the employee in the array
	void deleteemployee(employee ); // deleteing an employee 
	void print();



};

#endif