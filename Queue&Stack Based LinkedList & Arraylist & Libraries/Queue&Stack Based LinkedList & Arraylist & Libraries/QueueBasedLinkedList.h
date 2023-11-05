#pragma once
template <class Q>
class Queue : private DoubleLinkedList<Q> {
public:
	void enqueue(Q value) {
		this->AddToEnd(value);
	}

	Q dequeue() {
		Q value = this->head->Get_Data();
		this->Delete(1);
		return value;
	}

	bool isEmpty() {
		return this->head == NULL;
	}
};