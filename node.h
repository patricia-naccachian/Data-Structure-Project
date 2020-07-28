//This file includes the struct of node that will be used in the data structures of bst to the cities

#ifndef H_node
#define H_node

#include"City.h"

struct node
{
	City value;
	node* left;
	node* right;
};


#endif