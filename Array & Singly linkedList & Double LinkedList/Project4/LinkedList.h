#pragma once
class Node {
public:
	int data;
	Node* next;

	Node(int value) {
		data = value;
		next = 0;
	}
};

class LinkedList {
	Node* head;
	Node* tail;
	int itemsAdded = 0;
public:
	LinkedList() {
		head = 0;
		tail = 0;
	}

	~LinkedList() {
		if (head) {
			head = 0;
			tail = 0;
		}
	}

	void AddForward(int value) {
		Node* temp = new Node(value);
		if (!head) {
			head = tail = temp;
		}
		else
		{
			temp->next = head;
			head = temp;
		}
		itemsAdded++;
	}

	void AddToEnd(int value) {
		Node* temp = new Node(value);
		if (!head) {
			head = tail = temp;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
		itemsAdded++;
	}

	void PrintAll() {
		Node* temp = head;
		while (temp) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	void Delete(int index) {
		int counter = 1;
		Node* temp = head;
		
		if (!temp) {
			cout << "ERROR:The List is empty!!";
			exit(0);
		}
		Node* temp2 = head->next;
		while (counter < index - 1 && temp) {
			temp2 = temp2->next;
			temp = temp->next;
			counter++;
		}
		if (index > itemsAdded+1) {
			cout << "ERROR: There is no Data in this Place in the linked list to delete";
			exit(0);
		}
		else if (index == 1) {
			head = head->next;
			delete temp;
		}
		else if (temp->next == NULL) {
			tail->next = 0;
			tail = temp;
			delete temp;
		}
		else {
			temp->next = temp2->next;
			delete temp2;
		}
		itemsAdded--;
	}

	void insert(int value, int index) {
		int counter = 1;
		Node* x = new Node(value);
		Node* temp = head;
		if (index > itemsAdded + 1) {
			cout << "ERROR can't insert here!!";
			exit(0);
		}
		if (!temp) {
			cout << "ERROR:The List is empty!!";
			exit(0);
		}
		while (counter < index - 1 && temp) {
			temp = temp->next;
			counter++;
		}
		if (temp->next == NULL) {
			temp->next = x;
			tail = x;
		}
		else if (index == 1) {
			x->next = temp;
			head = x;
		}
		else {
			x->next = temp->next;
			temp->next = x;
		}
		itemsAdded++;
	}

	void Clear() {
		if (!head) {
			cout << "ERROR:The List is empty!!";
			exit(0);
		}
		else {
			head = tail = 0;
			itemsAdded = 0;
		}
	}
	int Get_itemsAdded() {
		return itemsAdded;
	}
};
