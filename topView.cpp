// C++ program for printing vertical order of a given binary tree
#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Structure for a binary tree node
struct Node
{
	int key;
	Node *left, *right;
};

// A utility function to create a new node
struct Node* newNode(int key)
{
	struct Node* node = new Node;
	node->key = key;
	node->left = node->right = NULL;
	return node;
}

// Utility function to store vertical order in map 'm'
// 'hd' is horigontal distance of current node from root.
// 'hd' is initally passed as 0
void getVerticalOrder(Node* root, int hd, map<int, int> &m)
{
	// Base case
	if (root == NULL)
		return;

	// Store current node in map 'm'
    if(m.count(hd)==0)
		m[hd]=root->key;

	// Store nodes in left subtree
	getVerticalOrder(root->left, hd-1, m);

	// Store nodes in right subtree
	getVerticalOrder(root->right, hd+1, m);
}

// The main function to print vertical oder of a binary tree
// with given root
void printVerticalOrder(Node* root)
{
	// Create a map and store vertical oder in map using
	// function getVerticalOrder()
	map < int,int > m;
	int hd = 0;
	getVerticalOrder(root, hd,m);

	// Traverse the map and print nodes at every horigontal
	// distance (hd)
	map< int,int > :: iterator it;
	for (it=m.begin(); it!=m.end(); it++)
	{

			cout << it->second<< " ";
		//cout << endl;
	}
}

// Driver program to test above functions
int main()
{
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->right->left = newNode(4);
    root->right->left->left = newNode(5);
    root->right->left->left->left = newNode(6);
	cout << "Vertical order traversal is n";
	printVerticalOrder(root);
	return 0;
}
