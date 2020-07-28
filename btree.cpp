#include<iostream>
#include<string>

#include"Date.h"
#include"employee.h"
#include"Street_Store.h"
#include"City.h"
#include"node.h"
#include"btree.h"

using namespace std;

btree::btree()
{
	root = NULL;
}

void btree::destroy_tree() 
{
	destroy_tree(root);
}

void btree::destroy_tree(node* leaf)
{
	if (leaf != NULL)
	{
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

void btree::insert(City key, node* leaf)
{
	if (key.City_id < leaf->value.City_id) {
		if (leaf->left != NULL) {
			insert(key, leaf->left);
		}
		else {
			leaf->left = new node;
			leaf->left->value = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}
	else if (key.City_id >= leaf->value.City_id) {

		if (leaf->right != NULL) {
			insert(key, leaf->right);
		}
		else {
			leaf->right = new node;
			leaf->right->value = key;
			leaf->right->right = NULL;
			leaf->right->left = NULL;
		}
	}
}

void btree::insert(City key)
{

	if (root != NULL) {
		insert(key, root);
	}
	else {
		root = new node;
		root->value = key;
		root->left = NULL;
		root->right = NULL;
	}

}

node* btree::search(City key, node* leaf) 
{
	if (leaf != NULL) {
		if (key.City_id == leaf->value.City_id) {
			return leaf;
		}
		if (key.City_id < leaf->value.City_id) {
			return search(key, leaf->left);
		}
		else {
			return search(key, leaf->right);
		}
	}
	else {
		return NULL;
	}
}

node* btree::search(City key) 
{
	return search(key, root);
}

void btree::deleteNode(node*& root, City key)
{
	// pointer to store parent node of current node
	node* parent = nullptr;

	// start with root node
	node* curr = root;

	// search key in BST and set its parent pointer
	searchKey(curr, key, parent);

	// return if key is not found in the tree
	if (curr == nullptr)
		return;

	// Case 1: node to be deleted has no children i.e. it is a leaf node
	if (curr->left == nullptr && curr->right == nullptr)
	{
		// if node to be deleted is not a root node, then set its
		// parent left/right child to null
		if (curr != root)
		{
			if (parent->left == curr)
				parent->left = nullptr;
			else
				parent->right = nullptr;
		}
		// if tree has only root node, delete it and set root to null
		else
			root = nullptr;

		// deallocate the memory
		free(curr);	 // or delete curr;
	}


	// Case 2: node to be deleted has two children
	else if (curr->left && curr->right)
	{
		// find its in-order successor node
		node* successor = findMin(curr->right);

		// store successor value
		City val = successor->value;

		// recursively delete the successor. Note that the successor
		// will have at-most one child (right child)
		deleteNode(root, successor->value);

		// Copy the value of successor to current node
		curr->value = val;
	}

	// Case 3: node to be deleted has only one child
	else
	{
		// find child node
		node* child = (curr->left) ? curr->left : curr->right;

		// if node to be deleted is not a root node, then set its parent
		// to its child
		if (curr != root)
		{
			if (curr == parent->left)
				parent->left = child;
			else
				parent->right = child;
		}

		// if node to be deleted is root node, then set the root to child
		else
			root = child;

		// deallocate the memory
		free(curr);
	}
}

void btree::deleteNode(City key)
{
	deleteNode(root, key);
}

void btree::deletecityifnostores()
{
	deletecityifnostores(root);
}

void btree::deletecityifnostores(node* leaf)
{
	if (leaf != NULL)
	{
		deletecityifnostores(leaf->left);
		deletecityifnostores(leaf->right);
		if (leaf->value.countstoreincity() == 0)
		{
			deleteNode(leaf->value);
		}
	}
}
 
int btree::countstoreofcountry()
{
	return countstoreofcountry(root);

}

int btree::countstoreofcountry(node* leaf)
{
	int count = 0;
	if (leaf != NULL) {
		count = count + leaf->value.countstoreincity();
		count = count + countstoreofcountry(leaf->left);
		count = count + countstoreofcountry(leaf->right);
	}
	return count;
}

void btree:: inorder_print()
{
	inorder_print(root);
	cout << "\n";
}

void btree::inorder_print(node* leaf) 
{
	if (leaf != NULL) {
		inorder_print(leaf->left);
		leaf->value.print();
		inorder_print(leaf->right);
	}
}

bool btree::searchifthere(City key, node* leaf) 
{
	if (leaf != NULL) {
		if (key.City_id == leaf->value.City_id) {
			return true;
		}
		if (key.City_id < leaf->value.City_id) {
			return search(key, leaf->left);
		}
		else {
			return search(key, leaf->right);
		}
	}
	else {
		return NULL;
	}
}

bool btree::searchifthere(City key) 
{
	return searchifthere(key, root);
}

node* btree::findMin(node* root)
{
	while (root->left != NULL)
	{
		root = root->left;
	}
	return root;
}

void btree::searchKey(node*& curr, City key, node*& parent)
{
	// traverse the tree and search for the key 
	while (curr != nullptr && curr->value.City_id != key.City_id)
	{
		// update parent node as current node
		parent = curr;

		// if given key is less than the current node, go to left subtree
		// else go to right subtree similar to the code found in the slides
		if (key.City_id < curr->value.City_id)
			curr = curr->left;
		else
			curr = curr->right;
	}
}