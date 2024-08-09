// BST Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Node.h"
#include "BST.h"
#define SPACE 10

using namespace std;

int main()
{
    BST obj; //BST object of Class BST created
    int option, val; 

    do 
    {
        cout << "What operation do you want to perform ? " << endl;
        cout << "Select option number . Enter 0 to exit" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Search Node" << endl;
        cout << "3. Delete Node" << endl;
        cout << "4. Print BST Values" << endl;
        cout << "5. Clear Screen" << endl;
        cout << "0. Exit Program" << endl;

        cin >> option;

        TreeNode *new_node = new TreeNode(); //memory allocated for TreeNode object on heap 

        switch (option) 
        {
        case 0:
             break;
        case 1: 
             cout << "Insert the key of Tree Node to insert in BST" << endl;
             cin >> val;
             new_node-> key = val;
             obj.insertNode(new_node);
             cout << endl;
             break;
        case 2:
            cout << "Insert the key you want to find !" << endl;
            cin >> val;
            new_node = obj.SearchNode(val);
            if (new_node != NULL) {
                cout << " HOORAY , Value found :)" << endl << endl;
            }
            else {
                cout << " Sorry :( , Value was not found" << endl << endl;
            }
            break;
        case 3:
            cout << "DELETE" << endl;
            break;
        case 4:
            cout << "PRINT and TRAVERSE" << endl;
            obj.print2D(obj.root, 5);
            cout << "Pre-order Tree Traversal Technique : ";
            obj.printPreOrder(obj.root);
            cout << endl;
            cout << "In-order Tree Traversal Technique : ";
            obj.printInOrder(obj.root);
            cout << endl;
            cout << "Post-order Tree Traversal Technique : ";
            obj.printPostOrder(obj.root);
            cout << endl << endl;
            break;
        case 5:
            system("cls");
            break;
        default:
            cout << "Your option does not exist , Enter a proper number ! " << endl;
        }

    } 
    while (option != 0);

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file