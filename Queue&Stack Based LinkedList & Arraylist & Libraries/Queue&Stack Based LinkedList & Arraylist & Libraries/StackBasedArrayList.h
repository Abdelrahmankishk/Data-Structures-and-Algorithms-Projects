#pragma once
template <class S>
class Stack1: private ArrayList<S> {
public:
	void Push(S value) {
		this->Add(value);
	}

	S Pop() {
		int items = this->get_itemsAdded();
		S value = this->storage[items-1];
		this->Delete(items);
		return value;
	}

	bool isEmpty() {
		return this->get_itemsAdded() == 0;
	}
};