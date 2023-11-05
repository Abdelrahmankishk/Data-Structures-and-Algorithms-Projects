#pragma once
template <class N>
struct Node{
	N value;
	Node<N>* right;
	Node<N>* left;
public:
	Node() {
		right = left = 0;
	}
	Node(N value) {
		this->value = value;
		right = 0;
		left = 0;
	}
	~Node() {
		if (value || right || left)
			value = right = left = 0;
	}
};

template<class B>
class BST {
	Node<B>* root;

	bool SearchRecusiveInternal(Node<B>* temp, B value) {
		if (!temp) {
			return false;
		}
		if (temp->value == value) {
			return true;
		}
		else if (temp->value > value) {
			SearchRecusiveInternal(temp->left, value);
		}
		else {
			SearchRecusiveInternal(temp->right, value);
		}
	}
	void PreorderInternal(Node<B>* temp) {
		
		if (!temp) {
			return;
		}
		cout << temp->value << ", ";
		PreorderInternal(temp->left);
		PreorderInternal(temp->right);
	}

	void InorderInternal(Node<B>* temp) {
		
		if (!temp) {
			return;
		}
		InorderInternal(temp->left);
		cout << temp->value << ", ";
		InorderInternal(temp->right);
	}
	void PostorderInternal(Node<B>* temp) {
		
		if (!temp) {
			return;
		}
		PostorderInternal(temp->left);
		PostorderInternal(temp->right);
		cout << temp->value << ", ";
	}

public:
	BST() {
		root = 0;
	}

	void ADD(B v) {
		Node<B>* x = new Node<B>(v);
		if (!root) {
			root = x;
		}
		else {
			Node<B>* temp = root;
			while (temp) {
				if (temp->value == v) {
					cout << v << " is  already Exists!!";
					exit(0);
				}
				else if (temp->value < v)
				{
					if (temp->right) {
						temp = temp->right;
					}
					else
					{
						temp->right = x;
						break;
					}
				}
				else
				{
					if (temp->left) {
						temp = temp->left;
					}
					else
					{
						temp->left = x;
						break;
					}
				}
			}
		}
	}

	bool SearchIterative(B value) {
		Node<B>* temp = root;
		while (temp) {
			if (temp->value == value) {
				return true;
			}
			else if (temp->value > value) {
				temp = temp->left;
			}
			else {
				temp = temp->right;
			}
		}
		return false;
	}

	void SearchRecursive(B value) {
		if (SearchRecusiveInternal(this->root, value) == 1) {
			cout << value << " is found in the tree" << endl;
		}
		else
		{
			cout << value << " is NOT in the tree" << endl;
		}
	}

	void Preorder() {
		cout << "Preorder: ";
		 PreorderInternal(this->root);
		 cout << endl;
	}

	void Inorder() {
		cout << "Inorder: ";
		InorderInternal(this->root);
		cout << endl;
	}

	void Postorder() {
		cout << "Postorder: ";
		PostorderInternal(this->root);
		cout << endl;
	}
};