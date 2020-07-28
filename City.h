//This file includes the struct of cities 
#ifndef H_City
#define H_City

#include<iostream>
#include<string>

#include"Date.h"
#include"employee.h"
#include"Street_Store.h"
using namespace std;

struct City
{
	//constructors and destructors
	City();
	City(int, string);
	~City() {};


	Street_Store* Stores = new Street_Store[100];
	int City_id;
	string City_name;


	int hashkey(Street_Store);  //function to get the hask key that will be used in inserting and searching 
	void insertStore(Street_Store); // adding in the array of street and stores using the hash
	bool searchstorebool(Street_Store); //checking if a store is in a city exists using the hash key
	int searchstoreint(Street_Store); //knowing the position after finding it
	void deletestore(Street_Store); //deleteing a city also if no store in it we delete the city
	int countstoreincity(); // counting the number of stores in 1 city
	void print();
};


#endif