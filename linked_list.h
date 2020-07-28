//This file includes the class of the likned list that will be used for the countries
#ifndef H_linked_list
#define H_linked_list

#include<iostream>
#include<string>

#include"Country.h"
#include"listnode.h"

using namespace std;

class linked_list
{
public:

	//constructor 
	linked_list();

	listnode* head;
	listnode* tail;
	listnode* fence;

	void add_node(Country); // function to add a country just like code found in the slides of linked list when forming new node
	bool searchifthere(Country); //function to check if the country exists or not and will be used in other funcntions especally delete.
	//we used the hash key since it would be faster to do so.
	listnode* search(Country); // to search and return the country required through a pointer or address of it in the linkedlist
	void deletefunction(Country); //deleting a country from the linked list by first searching if it exists then looking for it then delete it
	// and then reconnecting the linked list just like ther removal code in the slides of linked list
	void deleteifnostores(); //deleting a country that has no store
	void deleteifnostorescities(); //deleting the country if there are no stores and cities in the country instead of calling the function
	//for the cities with no stores since we had some issues in such functions in functions so seperate functions to work
	void print(); 




};



#endif