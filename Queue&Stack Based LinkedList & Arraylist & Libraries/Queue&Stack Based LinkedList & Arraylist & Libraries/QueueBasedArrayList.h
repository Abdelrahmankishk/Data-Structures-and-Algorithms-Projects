#pragma once
template <class Q>
class Queue1 :private ArrayList<Q>
{
public:
	void enqueue(Q value) {
		this->Add(value);
	}

	Q dequeue() {
		Q value = this->storage[0];
		this->Delete(0);
		return value;
	}

	bool isEmpty() {
		return this->get_itemsAdded() == 0;
	}
};