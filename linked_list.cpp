#include<iostream>
#include<string>

#include"linked_list.h"
#include"listnode.h"
#include"Country.h"

using namespace std;


linked_list::linked_list()
{
	head = NULL;
	tail = NULL;
	fence = NULL;
}

void linked_list::add_node(Country n)
{
	listnode* tmp = new listnode;
	tmp->data = n;
	tmp->next = NULL;

	if (head == NULL)
	{
		head = tmp;
		tail = tmp;
		fence = tmp;
	}
	else
	{
		tail->next = tmp;
		tail = tail->next;
	}
}

bool linked_list::searchifthere(Country n)
{
	fence = head;
	if (head == NULL)
	{
		return false;
	}
	else
	{
		if (head->data.country_id == n.country_id)
		{
			return true;
		}
		else
		{

			while (fence->next != NULL)
			{
				if (fence->next->data.country_id == n.country_id)
				{
					return true;
				}
				else
				{
					fence = fence->next;
				}
			}
			return false;
		}
	}
}

listnode* linked_list::search(Country n)
{
	fence = head;
	if (head->data.country_id == n.country_id)
	{
		return head;
	}
	else
	{

		while (fence->next != NULL)
		{
			if (fence->next->data.country_id == n.country_id)
			{
				return fence;
			}
			else
			{
				fence = fence->next;
			}
		}
		return head;
	}
}

void linked_list::deletefunction(Country n)
{

	if (searchifthere(n) == true)
	{
		fence = head;
		if (head->next == NULL)
		{
			head = NULL;
			tail = NULL;
			fence = NULL;
		}
		else if (head->data.country_id == n.country_id)
		{
			head = head->next;
			fence = head;
		}
		else
		{
			while (fence->next != NULL)
			{
				if (fence->next->data.country_id == n.country_id)
				{
					fence->next = fence->next->next;
				}
				else
				{
					fence = fence->next;
				}
			}
		}

	}
	else
	{
		cout << "This country doenst exist" << endl;
	}
}

void linked_list::deleteifnostores()
{
	fence = head;
	if (head == NULL)
	{

	}
	else if (head->next == NULL)
	{
		if (head->data.tree.countstoreofcountry() == 0)
		{
			deletefunction(head->data);
		}
	}
	else
	{
		while (fence->next != NULL)
		{

			if (fence->data.tree.countstoreofcountry() == 0)
			{
				deletefunction(fence->data);

			}
			else
			{
				fence = fence->next;
			}
		}
		if (fence->data.tree.countstoreofcountry() == 0)
		{

			deletefunction(fence->data);

		}
	}
}

void linked_list::deleteifnostorescities()
{
	fence = head;
	if (head == NULL)
	{

	}
	else
	{
		if (head->data.tree.root != NULL)
		{
			head->data.tree.deletecityifnostores();
			while (fence->next != NULL)
			{
				if (fence->data.tree.countstoreofcountry() == 0)
				{
					fence->data.tree.deletecityifnostores();
				}
				else
				{
					fence = fence->next;
				}
			}
		}
	}

}

void linked_list::print()
{
	fence = head;
	if (head == NULL)
	{
		cout << "There are no countries that contains stores" << endl;
	}
	else
	{

		while (fence->next != NULL)
		{
			cout << "The country " << fence->data.country_name << " of Id " << fence->data.country_id << " contains :" << endl;
			fence->data.tree.inorder_print();
			fence = fence->next;
		}
		cout << "The country " << fence->data.country_name << " of Id " << fence->data.country_id << " contains :" << endl;
		fence->data.tree.inorder_print();
	}
}