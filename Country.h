//This file includes the struct of countries
#ifndef H_Country
#define H_Country

#include<iostream>
#include<string>

#include"btree.h"

using namespace std;

struct Country
{
	//constructors and destructor
	Country(); 
	Country(int, string , btree); //taking name of country , id , and a btree object to add a tree of cities to this country 
	Country(int, string); //taking name of country and id
	~Country() {};

	int country_id;
	string country_name;
	btree tree;

	void addtree(btree); // function to add a tree of cities to the country



};

#endif