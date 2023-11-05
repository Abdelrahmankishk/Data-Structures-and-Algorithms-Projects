#pragma once
#include<iostream>
#include <list>
using namespace std;

template <class Q>
class Queue2 {
	list<Q> Linked;
public:
	Queue2() {

	}
	void enqueue(Q value) {
		Linked.push_back(value);
	}

	Q dequeue() {
		Q value = Linked.front();
		Linked.pop_front();
		return value;
	}

	bool isEmpty() {
		return Linked.empty();
	}

};