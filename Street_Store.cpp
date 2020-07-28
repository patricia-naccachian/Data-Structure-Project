#include<iostream>
#include<string>

#include"Date.h"
#include"employee.h"
#include"Street_Store.h"

using namespace std;

Street_Store::Street_Store()
{
	Store_id = 0;
	Street_name = "";
	Manager_name = "";
	Telephone = "";
	date_open;
}

Street_Store::Street_Store(int Store_id1, string Street_name1, string Manager_name1, string Telephone1, int day, int month, int year)
{
	Store_id = Store_id1;
	Street_name = Street_name1;
	Manager_name = Manager_name1;
	Telephone = Telephone1;
	date_open.setDate(day, month, year);
}

employee* Street_Store::extendarray(employee* oldArray, int& size)
{
	int newSize = size + 1;
	employee* newArray = new employee[newSize];
	for (int i = 0; i < size; i++) {
		newArray[i] = oldArray[i];
	}
	delete[] oldArray;
	size++;
	oldArray = new employee[size];
	oldArray = newArray;
	return oldArray;
}

employee* Street_Store::decremnetdarray(employee* oldArray, int& size)
{
	int newSize = size - 1;
	employee* newArray = new employee[newSize];
	for (int i = 0; i < newSize; i++) {
		newArray[i] = oldArray[i];
	}
	delete[] oldArray;
	size--;
	oldArray = new employee[size];
	oldArray = newArray;
	return oldArray;
}

void Street_Store::insertemployee(employee emp)
{
	if (size < 10)
	{
		A_emplyee = extendarray(A_emplyee, size);
		A_emplyee[size - 1] = emp;
	}
	else
	{
		cout << "The store has reached its max capacity of employees" << endl;
	}
}

bool Street_Store::searchemployeecheck(employee emp)
{
	for (int i = 0; i < size; i++)
	{
		if (A_emplyee[i].employee_id == emp.employee_id)
		{
			return true;
		}
	}
	return false;
}

int Street_Store::searchemployeeindex(employee emp)
{
	for (int i = 0; i < size; i++)
	{
		if (A_emplyee[i].employee_id == emp.employee_id)
		{
			return i;
		}
	}
	return -1;
}

void Street_Store::deleteemployee(employee emp)
{
	if (searchemployeecheck(emp) == true)  //we use an already defined fucntion to see if the deleted employee(emp) exists first and so on
	{
		employee temp = A_emplyee[searchemployeeindex(emp)];
		A_emplyee[searchemployeeindex(emp)] = A_emplyee[size - 1];
		A_emplyee[size - 1] = temp;
		A_emplyee = decremnetdarray(A_emplyee, size);
	}
	else
	{
		cout << "This employee doesnt exist in this store" << endl;
	}
}

void Street_Store::print()  //printing all details of the store and street
{
	cout << "The Store id is " << Store_id << endl;
	cout << "The Street name is " << Street_name << endl;
	cout << "The Manager of the Store is " << Manager_name << endl;
	cout << "The Store phone number is " << Telephone << endl;
	cout << "The Store was openned in ";
	date_open.display();
	if (size == 0)
	{
		cout << "There are no employees in the store" << endl;
	}
	else
	{
		cout << "The employees that work in the store are : ";
		cout << A_emplyee[0].employee_name;
		for (int i = 1; i < size; i++)
		{
			cout << ", " << A_emplyee[i].employee_name;
		}
		cout << endl;
	}
}



