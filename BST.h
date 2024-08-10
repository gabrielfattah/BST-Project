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

	TreeNode* minValueNode(TreeNode* node) { //Finding smallest node on right subtree

		TreeNode* current = node;
		/*Loop down to find the leftmost leaf*/
		while (current->left != NULL) {
			current = current->left;
		}
		return current;
	}

	TreeNode* deleteNode(TreeNode* r, int v) {
		// base condition 
		if (r == NULL) {
			return r; 
		}
		//if key to be deleted is smaller than the root's key, 
		//then it lies in the left subtree
		else if (v < r -> key) {
			r->left = deleteNode(r->left, v);
		}
		//if the key to be deleted is greater than the root's key,
		//then it lies in the right subtree 
		else if (v > r->key) {
			r->right = deleteNode(r->right, v);
		}
		//if key is same as root's key , then this is the node to be deleted
		else {
			//node with only one child or no child
			if (r->left == NULL) {
				TreeNode* temp = r->right;
				delete r;
				return temp;
			}
			else if (r->right == NULL) {
				TreeNode* temp = r->left;
				delete r;
				return temp;
			}
			else {
				//node with two children 
				TreeNode* temp = minValueNode(r->right);
				r->key = temp->key;
				r->right = deleteNode(r->right, temp->key);
			}
		}
		return r;
	}


};
