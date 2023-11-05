#pragma once
template <class T>
class NodE {
	T data;
	NodE<T>* next;
	NodE<T>* prev;

public:
	NodE(T value) {
		data = value;
		next = 0;
		prev = 0;
	}

	void Set_Data(T value) {
		data = value;
	}
	T Get_Data() {
		return data;
	}
	void Set_next(NodE<T>* n) {
		next = n;
	}
	NodE<T>* Get_next() {
		return next;
	}

	void Set_Previous(NodE<T>* n) {
		prev = n;
	}
	NodE<T>* Get_Previous() {
		return prev;
	}
};
template <class T>
class DoubleLinkedList {
protected:
	NodE<T>* head;
	NodE<T>* tail;
	int itemsADDED = 0;
public:
	DoubleLinkedList() {
		head = tail = 0;
	}
	void AddForward(T value) {
		NodE<T>* temp = new NodE<T>(value);
		if (!head) {
			head = tail = temp;
		}
		else {
			head->Set_Previous(temp);
			temp->Set_next(head);
			head = temp;
		}
		itemsADDED++;
	}

	void AddToEnd(T value) {
		NodE<T>* temp = new NodE<T>(value);
		if (!head) {
			head = tail = temp;
		}
		else {
			tail->Set_next(temp);
			temp->Set_Previous(tail);
			tail = temp;
		}
		itemsADDED++;
	}

	void Delete(int index) {
		int counter = 1;
		NodE<T>* temp = head;
		if (!temp) {
			cout << "ERROR: The linked list is Empty";
			exit(0);
		}

		while (counter < index - 1 && temp) {
			temp = temp->Get_next();
			counter++;
		}
		if (index > itemsADDED) {
			cout << "ERROR: There is no Data in this Place in the linked list to be delete";
			exit(0);
		}
		else if (index == 1) {
			head = head->Get_next();
		}
		else if (index == itemsADDED) {
			tail = temp;
			temp->Set_next(0);
		}
		else {
			temp->Get_Previous()->Set_next(temp->Get_next());
			temp->Get_next()->Set_Previous(temp->Get_Previous());
			delete temp;
		}

		itemsADDED--;
	}

	void insert(T value, int index) {
		int counter = 1;
		NodE<T>* x = new NodE<T>(value);
		NodE<T>* temp = head;
		if (index > itemsADDED) {
			cout << "ERROR can't insert here!!";
			exit(0);
		}
		if (!temp) {
			cout << "ERROR: The linked list is Empty";
			exit(0);
		}
		while (counter < index - 1 && temp) {
			temp = temp->Get_next();
			counter++;
		}
		if (temp->Get_next() == NULL) {
			temp->Set_next(x);
			tail = x;
		}
		else if (index == 1) {
			temp->Set_Previous(x);
			x->Set_next(temp);
			head = x;
		}
		else {
			x->Set_next(temp->Get_next());
			temp->Get_next()->Set_Previous(x);
			temp->Set_next(x);
			x->Set_Previous(temp);
		}
		itemsADDED++;
	}

	void PrintAll() {
		NodE<T>* temp = head;
		if (!temp) {
			cout << "ERROR: The linked list is Empty";
			exit(0);
		}
		while (temp) {
			cout << temp->Get_Data() << " ";
			temp = temp->Get_next();
		}
		cout << endl;
	}

	void Clear() {
		if (!head) {
			cout << "ERROR: The LInked List is Empty";
			exit(0);
		}
		else {
			head = tail = 0;
			itemsADDED = 0;
		}
	}
	int Get_itemsAdded() {
		return itemsADDED;
	}

	void Search(T value) {
		NodE<T>* temp = head;
		int y = 0;
		NodE<T>* x = new NodE<T>(value);
		while (temp)
		{
			if (temp->Get_Data() == x->Get_Data()) {
				cout << "(" << value << ") is Found in The Linked list!" << endl;
				y = 1;
				break;
			}
			else
			{
				temp = temp->Get_next();
			}
		}
		if (y == 0) {
			cout << "(" << value << ") WAS NOT Found in The Linked list!" << endl;
		}
	}
};