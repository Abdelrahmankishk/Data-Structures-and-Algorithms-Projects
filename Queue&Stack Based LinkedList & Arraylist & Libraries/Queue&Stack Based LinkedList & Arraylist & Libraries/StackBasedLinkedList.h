#pragma once
template <class S>
class Stack: private DoubleLinkedList<S> {
public:
	void Push(S value) {
		this->AddForward(value);
	}

	S Pop() {
		S value = this->head->Get_Data();
		this->Delete(1);
		return value;
	}

	bool isEmpty() {
		return this->head == NULL;
	}
};