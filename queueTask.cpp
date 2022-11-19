#include <iostream>
template<typename T>
class Queue {
	struct Node {
		T data;
		Node* next;
	};
	Node* head;
	Node* tail;
public:
	Queue();
	bool empty() const;
	void put(const T& data);
	T get();
	~Queue();
};
// implementation
template<typename T>
Queue<T>::Queue() : head(nullptr), tail(nullptr) {}
template<typename T>
bool Queue<T>::empty() const {
	return this->head == nullptr;
}
template<typename T>
void Queue<T>::put(const T& data) {
	if (head == nullptr) {
		head = new Node{ data, nullptr };
		tail = head;
	}
	else {
		Node* n = new Node{ data, nullptr };
		tail->next = n;
		tail = n;
	}
} 
template<typename T>
T Queue<T>::get() {
	T data = head->data;
	Node* tmp = head->next;
	delete head;
	head = tmp;
	return data;

	
}
template<typename T>
Queue<T>::~Queue() {
	while (!this->empty()) {
		std::cout << " Del:" << get();
	}
	
}
int main() {
	int data1, data2;
	Queue<int>* q = new Queue<int>();
	q->put(1);
	data1 = q->get();
	std::cout << " data1=" << data1 << std::endl;
	q->put(1);
	q->put(2);
	data1 = q->get();
	data2 = q->get();
	std::cout << " data1=" << data1
		<< " data2=" << data2 << std::endl;
	q->put(1); q->put(2); q->put(3);
	q->put(4); q->put(5); q->put(6);
	while (!q->empty())
		std::cout << " " << q->get();
	std::cout << std::endl;
	q->put(1); q->put(2); q->put(3);
	delete q;
	
}