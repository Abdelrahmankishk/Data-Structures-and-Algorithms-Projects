#include<iostream>
using namespace std;

int counSeq = 0;
int BinaryIterCoun= 0;
int BinartRecCoun = 0;

int SequentialSearch(int* arr , int size , int number) {
	for (int i = 0; i < size; i++) {
		counSeq++;
		if (arr[i] == number)
			return i;
	}
	return -1;
}

int BinaryIterative(int* arr, int size, int number) {
	int first = 0;
	int last = size - 1;
	while (first <= last) {
		int pos = (first + last) / 2;
		BinaryIterCoun++;
		if (arr[pos] == number)
			return pos;
		else if (arr[pos] < number)
			first = pos + 1;
		else
			last = pos - 1;
	}
	return -1;
}

int BinaryRecurssion(int* arr, int first, int last, int number) {
	if(first > last) 
		return -1;
	BinartRecCoun++;
	int pos = (first + last) / 2;
	if (arr[pos] == number)
		return pos;
	else if (arr[pos] < number)
		BinaryRecurssion(arr, pos + 1, last, number);
	else
		BinaryRecurssion(arr, first, pos - 1, number);
}

void main() {
	int size = 1000000;
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = i;
	}
	cout<< "The Result of Searching using Squential Search: " << SequentialSearch(arr, size, 999999) <<
		" Number of Steps: " << counSeq << endl;

	cout << "The Result of Searching using Binary (Iterative) Search: " << BinaryIterative(arr, size, 999999) <<
		" Number of Steps: " << BinaryIterCoun << endl;
	cout << "The Result of Searching using Binary (Recurssion) Search: " << BinaryRecurssion(arr, 0, 999999, 999999) <<
		" Number of Steps: " << BinartRecCoun << endl;
}