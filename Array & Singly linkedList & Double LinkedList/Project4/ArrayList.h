#pragma once
#pragma once
template <class T>
class ArrayList {
	T* storage;
	int size;
	int itemsAdded;

	void Regrow() {
		T* newArray = new T[size + 10];
		for (int i = 0; i < size; i++) {
			newArray[i] = storage[i];
		}
		delete[] storage;
		storage = newArray;
		size += 10;
	}

public:
	ArrayList() {
		storage = 0;
		size = 0;
		itemsAdded = 0;
	}
	ArrayList(int x) {
		storage = new T[x];
		size = x;
		itemsAdded = 0;
	}
	~ArrayList() {
		if (storage) {
			storage = 0;
			size = 0;
		}
	}

	void Add(T value) {
		if (!storage) {
			size = 10;
			storage = new T[10];

		}
		if (itemsAdded == size) {
			Regrow();
		}
		storage[itemsAdded] = value;
		itemsAdded++;
	}

	void insert(T value, int index) {
		if (index > size) {
			cout << "Can't insert here";
			exit(0);
		}
		if (itemsAdded == size) {
			Regrow();
		}
		for (int i = itemsAdded; i > index; i--) {
			storage[i] = storage[i - 1];
		}
		storage[index] = value;
		itemsAdded++;
	}

	void Delete(int index) {
		if (index > size) {
			cout << "Can't Delete from here";
			exit(0);
		}
		for (int i = index; i < itemsAdded; i++) {
			storage[i] = storage[i + 1];
		}
		itemsAdded--;
	}
	int Find(T x) {
		for (int i = 0; i < itemsAdded; i++) {
			if (storage[i] == x) {
				return i;
			}
		}
	}

	T& operator[] (int index) {
		if (index > itemsAdded) {
			cout << "Out of Range";
			exit(0);
		}
		return storage[index];
	}
	int get_itemsAdded() {
		return itemsAdded;
	}
};