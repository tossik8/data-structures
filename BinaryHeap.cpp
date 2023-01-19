#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include <array>

template <typename T>
class BinaryHeap {
private:
	int last;
	std::vector<T> values;
public:
	BinaryHeap() : last(0) {}
	~BinaryHeap() {
		values.clear();
		values.shrink_to_fit();
	}
	void insert(T value) {
		values.push_back(value);
		this->upHeap(++last);
	}
	T findMin() {
		return values.at(0);
	}
	void print() {
		for (T value : values) {
			std::cout << value << " ";
		}
		std::cout << '\n';
	}
	void deleteMin() {
		values[0] = values[--last];
		values.erase(values.end() - 1, values.end());
		values.shrink_to_fit();
		this->downHeap(1);
	}
	void upHeap(int index) {
		for (int i = index / 2; i >= 1; i /= 2) {
			if (values[i - 1] > values[index - 1]) {
				std::swap(values[i - 1], values[index - 1]);
				index = i;
			}
			else break;
		}
	}
	void downHeap(int index) {
		for (int i = index; i <= last / 2;) {
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
	int getHeight() {
		return std::log2(last);
	}
	int lowerBoundOfElements(int height) {
		return std::pow(2, height);
	}
	int upperBoundOfElements(int height) {
		return std::pow(2, height + 1) - 1;
	}
	void sortHeap() {
		std::sort(values.begin(), values.end()/*, std::greater<T>()*/);
	}
};

int main() {
	auto start = std::chrono::high_resolution_clock::now();
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
	std::cout << "Min element: " << binaryHeap->findMin() << '\n';

	binaryHeap->deleteMin();

	binaryHeap->print();

	std::cout << "Min element: " << binaryHeap->findMin() << '\n';


	binaryHeap->deleteMin();

	binaryHeap->print();

	binaryHeap->deleteMin();

	binaryHeap->print();

	binaryHeap->insert(38);
	binaryHeap->insert(72);
	binaryHeap->insert(21);

	binaryHeap->insert(233);
	binaryHeap->insert(2);
	binaryHeap->insert(137);

	binaryHeap->insert(2433);
	binaryHeap->insert(207);
	binaryHeap->insert(42);

	binaryHeap->print();

	std::cout << "The smallest number of elements: " << binaryHeap->lowerBoundOfElements(binaryHeap->getHeight()) << ", the biggest number of elements: "
		<< binaryHeap->upperBoundOfElements(binaryHeap->getHeight()) << '\n';

	binaryHeap->sortHeap();
	binaryHeap->print();

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
	std::cout << "Total execution time: " << duration.count() << '\n';

	delete binaryHeap;
}
