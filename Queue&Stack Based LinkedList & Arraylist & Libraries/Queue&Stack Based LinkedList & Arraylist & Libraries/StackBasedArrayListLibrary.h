#pragma once
#include <iostream>
#include <vector>
using namespace std;

template <class S>
class Stack2 {
	vector<S> arr;
public:
	void Push(S value) {
		arr.push_back(value);
	}

	S Pop(){
		S value = arr.back();
		arr.pop_back();
		return value;
	}

	bool isEmpty() {
		return arr.empty();
	}
};