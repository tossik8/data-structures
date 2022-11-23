#include <iostream>
#include <algorithm>
#include <vector>


template <typename T>
class BinaryHeap {
private:
	int last;
	std::vector<T> values;
public:
	BinaryHeap() : last(0) {}
	void insert(T value) {
		values.push_back(value);
		int lastCopy = ++last;
		for (int i = lastCopy / 2; i >= 1; i/=2) {
			if (values[i - 1] > values[lastCopy - 1]) {
				std::swap(values[i-1], values[lastCopy - 1]);
				lastCopy = i;
			}
			else break;
		}
	}
	T findMin() {
		return values.at(0);
	}
	void print() {
		for (T value : values){
			std::cout << value << " ";
		}
		std::cout << '\n';
	}
	void deleteElement(int index) {
		for(int i = index + 1; i > 1;i/=2){
			std::swap(values[i - 1], values[i / 2 - 1]);
		}
		values[0] = values[--last];
		values.erase(values.end()-1, values.end());
		this->heapify();
	}
	void heapify() {
		for (int i = 1; i <= last / 2;) {
			T& current = values[i - 1];
			T& leftChild = values[i * 2 - 1];
			T& rightChild = values[i * 2];
			if (leftChild == NULL && rightChild == NULL) break;
			if (rightChild != NULL && leftChild < rightChild) {
				std::swap(current, leftChild);
				i *= 2;
			}
			else {
				std::swap(current, rightChild);
				i *= 2;
				++i;
			}
		}
	}
	
};

int main() {
	BinaryHeap<int>* binaryHeap = new BinaryHeap<int>();
	binaryHeap->insert(10);
	binaryHeap->insert(11);
	binaryHeap->insert(13);
	binaryHeap->insert(9);
	binaryHeap->insert(16);
	binaryHeap->insert(22);
	binaryHeap->insert(17);
	binaryHeap->insert(8);
	binaryHeap->insert(9);
	binaryHeap->insert(9);
	binaryHeap->insert(9);
	binaryHeap->insert(9);
	binaryHeap->insert(120);
	binaryHeap->insert(23);
	binaryHeap->insert(27);
	binaryHeap->insert(1);

	binaryHeap->print();
	std::cout << binaryHeap->findMin() << '\n';

	binaryHeap->deleteElement(4);

	binaryHeap->print();

	binaryHeap->deleteElement(0);

	binaryHeap->print();

}
