#include<iostream>
#include<string>

#include"Country.h"
#include"btree.h"

using namespace std;

Country::Country() 
{
	country_id = 0;
	country_name = " ";
}

Country::Country(int id1, string name1, btree tree1) 
{
	country_id = id1;
	country_name = name1;
	tree = tree1;
}

Country::Country(int id1, string name1)
{
	country_id = id1;
	country_name = name1;
}

void Country::addtree(btree tree1)
{
	tree = tree1;
}