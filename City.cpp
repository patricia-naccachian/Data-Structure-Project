#include<iostream>
#include<string>

#include"Date.h"
#include"employee.h"
#include"Street_Store.h"
#include"City.h"

using namespace std;

City::City()
{
	City_id = 0;
	City_name = " ";
}

City::City(int id1, string name1)
{
	City_id = id1;
	City_name = name1;
}

int City::hashkey(Street_Store Store) //function to get the hash key that will be used later on in the inserting and searching
{
	return Store.Store_id % 10;
}

void City::insertStore(Street_Store Store)
{
	bool inserted = false;
	for (int i = hashkey(Store); i < 100; i = i + 10)
	{
		if (Stores[i].valid == false)
		{
			Stores[i] = Store;
			Stores[i].valid = true;
			inserted = true;
			break;
		}
	}
	if (inserted == false)
	{
		cout << "The array for this hash is full" << endl;
	}
}

bool City::searchstorebool(Street_Store Store)
{
	for (int i = hashkey(Store); i < 100; i = i + 10)
	{
		if ((Stores[i].Store_id == Store.Store_id) && (Stores[i].valid == true))
		{
			return true;
		}
	}
	return false;
}

int City::searchstoreint(Street_Store Store)
{
	for (int i = hashkey(Store); i < 100; i = i + 10)
	{
		if ((Stores[i].Store_id == Store.Store_id) && (Stores[i].valid == true))
		{
			return i;
		}
	}
	return -1;
}

void City::deletestore(Street_Store Store)
{
	if (searchstorebool(Store) == true)
	{
		Stores[searchstoreint(Store)].valid = false;
	}
	else
	{
		cout << "The store doesnt exist" << endl;
	}
}

void City::print()
{
	cout << "The city " << City_name << " of id " << City_id << " Contains the following stores :" << endl;
	for (int i = 0; i < 100; i++)
	{
		if (Stores[i].valid == true)
		{
			Stores[i].print();
		}
	}
}

int City::countstoreincity()
{
	int count = 0;
	for (int i = 0; i < 100; i++)
	{
		if (Stores[i].valid == true)
		{
			count++;
		}
	}
	return count;
}