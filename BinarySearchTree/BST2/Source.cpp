#include <iostream>
#include <exception>
using namespace std;
#include "BST.h"
void main() {
	BST<int>* x = new BST<int>();
	x->ADD(25);
	x->ADD(36);
	x->ADD(20);
	x->ADD(10);
	x->ADD(22);
	x->ADD(30);
	x->ADD(40);
	x->ADD(5);
	x->ADD(12);
	x->ADD(28);
	x->ADD(38);
	x->ADD(48);
	x->ADD(1);
	x->ADD(8);
	x->ADD(15);
	x->ADD(45);
	x->ADD(50);
	
	x->SearchRecursive(50);
	x->SearchRecursive(45);
	x->SearchRecursive(80);
	x->SearchRecursive(100);

	x->Inorder();
	x->Preorder();
	x->Postorder();
}