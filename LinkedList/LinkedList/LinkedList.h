#pragma once

template <class T>
class Node
{
	T data;
	Node<T>* next;
	Node<T>* previous;

public:
	Node(T data)
	{
		this->data = data;
		next = 0;
		previous = 0;
	}

	void SetNext(Node<T> *next)
	{
		this->next = next;
	}

	Node<T>* GetNext()
	{
		return next;
	}

	void SetPrevious(Node<T>* previous)
	{
		this->previous = previous;
	}

	Node<T>* GetPrevious()
	{
		return previous;
	}

	void SetValue(T value)
	{
		data = value;
	}

	T GetValue()
	{
		return data;
	}
};


template <class T>
class LinkedList
{
	
	Node<T>* head;
	Node<T>* tail;

public:
	LinkedList()
	{
		head = tail = 0;
	}

	~LinkedList()
	{
		//Assignment
	}

	void AddFront(T value)
	{
		Node<T>* n = new Node<T>(value);
		if (!head)
		{
			head = tail = n;
		}
		else
		{
			n->SetNext(head);
			head->SetPrevious(n);
			head = n;
		}
	}

	void AddToEnd(T value)
	{
		Node<T>* n = new Node<T>(value);
		if (!head)
		{
			head = tail = n;
		}
		else
		{
			tail->SetNext(n);
			n->SetPrevious(tail);
			tail = n;
		}
	}

	void DeleteFromFront(int index)
	{
		//Assignment delete first item
		int counter = 0;
		Node<T>* temp = head;
		while (counter < index && temp)
		{
			temp = temp->GetNext();
			counter++;
		}

		if (!temp)
		{
			throw exception("Out of range!");
		}
		else
		{
			temp->GetPrevious()->SetNext(temp->GetNext());
			temp->GetNext()->SetPrevious(temp->GetPrevious());
			delete temp;
		}
	}

	void Insert(T value, int index)
	{
		int counter = 0;
		Node<T>* temp = head;
		while (counter < index && temp)
		{
			temp = temp->GetNext();
			counter++;
		}

		if (!temp)
		{
			throw exception("Out of range!");
		}
		else
		{
			Node<T>* n = new Node<T>(value);
			n->SetNext(temp);
			n->SetPrevious(temp->GetPrevious());
			temp->GetPrevious()->SetNext(n);
			temp->SetPrevious(n);
		}
	}

	void PrintAll()
	{
		Node<T>* temp = head;
		while (temp)
		{
			cout << temp->GetValue() << endl;
			temp = temp->GetNext();
		}
	}

	void DeleteValue(T value)
	{
		//Assignment
	}
};