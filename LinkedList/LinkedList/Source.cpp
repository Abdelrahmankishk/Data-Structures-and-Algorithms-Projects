#include <iostream>
#include <exception>
#include <list>
using namespace std;
#include "LinkedList.h"


void main()
{
	cout << "55555555555555555555555555555555";
	LinkedList<int> l;
	list<int> l2;

	for (int i = 0; i < 100; i++)
	{
		l.AddToEnd(i);
		l2.push_back(i);
	}

	l.Insert(5000, 50);
	l.DeleteFromFront(50);

	l.PrintAll();
}