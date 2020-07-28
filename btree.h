//This file includes the class of the bst that will be used for the cities
#ifndef H_btree
#define H_btree

#include<iostream>
#include<string>

#include"Date.h"
#include"employee.h"
#include"Street_Store.h"
#include"City.h"
#include"node.h"
using namespace std;

class btree
{
public:

	//constructor, desctructor and data member
	btree();
	void destroy_tree(); //desctructor 
	void destroy_tree(node*); //delete or destroy all the tree
	node* root;



	void insert(City, node*); //inserting fucntion of object of class city in the node with the pointer to it
	void insert(City); // insert by using the key in this fuction that will call the above fucntion
	void deleteNode(City); //ddeleting an object of class city using the key and calling the below function
	void deleteNode(node*&, City); // Function to delete node from a BST
	node* search(City, node*); //searching for the object of class citiy with returning a pointer to the required node
	node* search(City); //searching the onject of class city using the key and then calling the above function
	void deletecityifnostores(); // deleting a city if it has no stores in it 
	void deletecityifnostores(node*);  
	int countstoreofcountry(); //delete country if it contains no cities meaning no stores
	int countstoreofcountry(node*); 
	void inorder_print();  //indorder printing
	void inorder_print(node*);
	bool searchifthere(City, node*); // searching if object of class city is found and its ponter (T/F)
	bool searchifthere(City); // using the key to search, in this function we call the above fucntion
	node* findMin(node*);// function to find minimum that will help in deleting just like deletemin in the slides lecture of bst
	void searchKey(node*&, City, node*&); //recurssive fucntion to search using hash key giving a root and parent using referrence 

};



#endif
