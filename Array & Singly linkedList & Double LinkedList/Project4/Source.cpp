#include <iostream>
using namespace std;
#include "ArrayList.h"
#include "LinkedList.h"
#include "DoubleLinkedList.h";
int main() {
	LinkedList z;
	DoubleLinkedList<int> y;
	
for (int i = 1; i <= 50; i++) {
		z.AddToEnd(i);
	}
	
	z.Delete(1);
	z.Delete(z.Get_itemsAdded());
	z.insert(555, 1);
	z.insert(666, 10);
	z.PrintAll();

	z.Clear();
	z.AddToEnd(15);
	z.AddToEnd(16);
	z.AddForward(55);
	z.insert(55, 3);
	z.insert(66, 2);
	z.Delete(4);
	z.Get_itemsAdded();
	z.insert(77, 4);
	z.insert(88, 5);

	z.PrintAll();
	for (int i = 0; i <50; i++) {
		y.AddToEnd(i);
	}
	y.Search(49);
	y.insert(205,50);
	y.insert(555,y.Get_itemsAdded());
	y.Delete(1);
	//cout << "(" << y.Get_itemsAdded() << ")" << endl;
	y.insert(1, 51);
	y.Delete(y.Get_itemsAdded());
	y.Search(205);
	y.Search(555);
	y.Search(606);
	y.PrintAll();
	
	//y.Clear();
	
	//y.AddToEnd(15);
	//y.AddToEnd(20);
	//y.AddToEnd(60);
	//y.insert(120, 3);
	//y.Delete(9);
	//y.Delete(y.Get_itemsAdded());
	//y.PrintAll();
}