#include<iostream>
using namespace std;
#include "LinkedList.h"
#include "ArrayList.h"
#include "QueueBasedLinkedList.h"
#include "QueueBasedArrayList.h"
#include "QueueBasedLinkedListLibrary.h"
#include "StackBasedArrayListLibrary.h"
#include "StackBasedLinkedList.h"
#include "StackBasedArrayList.h"
#include "StackBasedLinkedListLibrary.h"

int main() {
	Stack3<int> x;
	for (int i = 0; i < 50; i++) {
		x.Push(i);
	}
	while (!x.isEmpty() ) {
		cout<< x.Pop() << " ";
	}
	return 0;
}