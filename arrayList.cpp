#pragma
#include <iostream>

class ArrayList {
	int size;
	int currentSize;
	int* arr;
public:
	ArrayList(int size) : size(size), currentSize(-1) {
		arr = new int[size];
	}
	void put(int i) {
		// Time complexity for insertion of an element in the end is O(1)
		if (currentSize < size-1) {
			arr[++currentSize] = i;
		}
		// Time complexity for insertion of an element in the end is O(n) when the array list is full
		else {
			size *= 2;
			int* arr2 = new int[size];
			for (int i = 0; i <= currentSize; ++i) {
				arr2[i] = arr[i];
			}
			delete[] arr;
			arr = arr2;
			arr[++currentSize] = i;
		}
	}
	// Time complexity for insertion of an element in the beginning is O(n)
	void putBeginning(int i) {
		if (currentSize < size - 1) {
			++currentSize;
			for (int j = currentSize; j >0; --j) {
				arr[j] = arr[j - 1];
			}
			arr[0] = i;
		}
		else {
			size *= 2;
			int* arr2 = new int[size];
			// O(n^2)?
			for (int i = 0; i <= currentSize; ++i) {
				arr2[i] = arr[i];
			}
			delete[] arr;
			arr = arr2;
			++currentSize;
			for (int j = currentSize; j > 0; --j) {
				arr[j] = arr[j - 1];
			}
			arr[0] = i;
		}
	}
	// Time complexity for insertion of an element in the middle is O(n)
	void putMiddle(int val, int ind) {
		if (currentSize < size - 1) {
			++currentSize;
			for (int j = currentSize; j > ind; --j) {
				arr[j] = arr[j - 1];
			}
			arr[ind] = val;
		}
		else {
			size *= 2;
			// O(n^2)?
			int* arr2 = new int[size];
			for (int i = 0; i <= currentSize; ++i) {
				arr2[i] = arr[i];
			}
			delete[] arr;
			arr = arr2;
			++currentSize;
			for (int j = currentSize; j > ind; --j) {
				arr[j] = arr[j - 1];
			}
			arr[ind] = val;
		}
	}
	void display() {
		std::cout << "[ ";
		for (int i = 0; i <= currentSize; ++i) {
			std::cout << arr[i] <<" ";
		}
		std::cout << "]\n";
	}
	// Time complexity for removing an element at an index is O(n)
	void remove(int index) {
		if (index <= currentSize && index >= 0 && currentSize >=0) {
			for (int i = index; i < currentSize; ++i) {
				arr[i] = arr[i + 1];
			}
			--currentSize;
		}
	}
	bool empty() {
		return currentSize == -1;
	}
	int getLength() {
		return currentSize + 1;
	}
	~ArrayList() {
		delete[] arr;
	}
};

int main() {
	ArrayList* arrayList = new ArrayList(3);
	std::cout << arrayList->empty() << '\n';
	arrayList->put(4);
	arrayList->put(4);
	arrayList->put(2);
	arrayList->put(5);
	arrayList->put(7);
	arrayList->display();
	arrayList->remove(2);
	arrayList->display();
	arrayList->put(10);
	arrayList->put(44);
	arrayList->display();
	arrayList->putBeginning(22);
	arrayList->display();
	arrayList->putMiddle(100, 5);
	arrayList->display();
	std::cout << arrayList->empty() << '\n';

}