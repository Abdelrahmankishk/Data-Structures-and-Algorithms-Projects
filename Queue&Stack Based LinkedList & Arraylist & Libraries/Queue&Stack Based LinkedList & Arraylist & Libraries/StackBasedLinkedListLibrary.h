#pragma once
#include<iostream>
#include <list>
using namespace std;
template <class S>
class Stack3 {
	list<S> Linked;
public:
	Stack3() {

	}
	void Push(S value) {
		Linked.push_front(value);
	}
	S Pop() {
		S value = Linked.front();
		Linked.pop_front();
		return value;
	}

	bool isEmpty() {
		return Linked.empty();
	}
};