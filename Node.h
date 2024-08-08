#pragma once
#include <iostream>
#define SPACE 10

//Node Class
class TreeNode {
public :
	int key;
	TreeNode* left;
	TreeNode* right;

	//Constructor to initialize nodes
	TreeNode()
	{
		key = 0;
		left = NULL;
		right = NULL;
	}

	//parameterized constructor 
	TreeNode(int v) 
	{
		key = v;
		left = NULL;
		right = NULL;
	}
};
