#include<iostream>
#include<string>
#include"employee.h"

using namespace std;

employee::employee()
{
	employee_id = 0;
	employee_name = " ";
}

employee::employee(int id1, string name1)
{
	employee_id = id1;
	employee_name = name1;
}