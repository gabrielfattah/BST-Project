#pragma once
#include <iostream>
#include "Node.h"
#define SPACE 10

using namespace std;
class BST {

public:
	TreeNode* root;

	BST() 
	{
		root = NULL;
	}
	bool isEmpty() 
	{
		if (root == NULL) 
		{
			return true;
		}
		else 
		{
			return false;
		}
	}

	void insertNode(TreeNode *new_node) 
	{
		if (root == NULL) {
			root = new_node;
			cout << "Key Inserted as root node!" << endl;
		}
		else {
			TreeNode* temp = root;
			while (temp != 0) {
				if (new_node->key == temp->key) {
					cout << "Key already exists, Insert another key !" << endl;
					return;
				}
				else if((new_node -> key < temp -> key) && (temp->left == NULL)){
					temp->left = new_node;
					cout << "Key Inserted to the left !" << endl;
					break;
				}
				else if (new_node -> key < temp -> key) {
					temp = temp->left;
				}
				else if ((new_node -> key > temp -> key) && (temp -> right == NULL)) {
					temp->right = new_node;
					cout << "Key Inserted to the right!" << endl;
					break;
				}
				else {
					temp = temp->right;
				}
			}
		}
	}
	
	void print2D(TreeNode* r, int space) { //Printing BST in a Graphical Way
		if (r == NULL) {
			return;
		}
		else {
			space += SPACE;
			print2D(r->right, space);
			cout << endl;
			for (int i = SPACE; i < space; i++) {
				cout << " ";
			}
			cout << r->key << "\n";
			print2D(r->left, space);
		}
	}

	void printPreOrder(TreeNode* r) { //Root, Left, Right 
		if (r == NULL)
			return;
		else {
			cout << r->key << " ";
			/*first print data of node*/
			printPreOrder(r->left);
			/*then recur on left subtree*/
			printPreOrder(r->right);
			/*now recur on right subtree*/
		}
		    
	}

	void printInOrder(TreeNode* r) {
		if (r == NULL)
			return;
		else {
			printInOrder(r->left);
			cout << r->key << " ";
			printInOrder(r->right);
		}
	}

	void printPostOrder(TreeNode* r) {
		if (r == NULL)
			return;
		else {
			printPostOrder(r->left);
			printPostOrder(r->right);
			cout << r->key << " ";
		}
	}

	TreeNode* SearchNode(int val) {
		if (root == NULL) {
			return  root;
		}
		else {
			TreeNode* temp = root;
			while (temp != 0) {
				if (val == temp->key) {
					return temp;
				}
				else if (val < temp->key) {
					temp = temp->left;
				}
				else {
					temp = temp->right;
				}
			}
			return NULL;
		}
	}
};
