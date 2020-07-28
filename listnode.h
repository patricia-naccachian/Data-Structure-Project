//This file includes the struct of listnode that will be used in the data structures of linked list of countries

#ifndef H_listnode
#define H_listnode

#include"Country.h"

struct listnode
{
	Country data;
	listnode* next;
};

#endif