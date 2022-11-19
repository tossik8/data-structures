#include <iostream>
#include <algorithm>
#include <type_traits>
#include <string>

template <typename T>
class Queue{
	int size;
	int rear, front;
	T* arr;
public:
	Queue(int size) : front(-1),rear(-1), size(size) {
		arr = new T[size];
	}
	void enqueue(T val) {
		if (isEmpty()) {
			front = ++rear;
			arr[rear] = val;
			return;
		}
		else if ((rear + 1) % size == front) {
			return;
		}
		else {
			rear = (rear + 1) % size;
			arr[rear] = val;
		}
	}
	T dequeue() {
		if (isEmpty()) {
			return -1;
		}
		else if (front == rear) {
			T val = arr[front];
			rear = front = -1;
			return val;
		}
		else {
			T val = arr[front];
			front = (front + 1) % size;
			return val;
		}
	}
	bool isEmpty() {
		return front == -1 && rear == -1;
	}
	~Queue() {
		delete[] arr;
	}
};
template <>
class Queue<std::string> {
	int size;
	int front, rear;
	std::string* arr;
public:
	Queue(int size) : front(-1),rear(-1),size(size){
		arr = new std::string[size];
	}
	void enqueue(std::string val) {
		if (isEmpty()) {
			rear = ++front;
			arr[rear] = val;
			return;
		}
		else if ((rear + 1) % size == front) {
			return;
		}
		else {
			rear = (rear + 1) % size;
			arr[rear] = val;
		}
		
	}
	std::string dequeue() {
		if (isEmpty()) {
			return "";
		}
		else if (front == rear) {
			std::string val = arr[front];
			front = rear = -1;
			return val;
		}
		else {
			std::string val = arr[front];
			front = (front + 1) % size;
			return val;
		}
		
	}
	bool isEmpty() {
		return front == -1 && rear == -1;
	}
	~Queue() {
		delete[] arr;
	}
};
template <typename T>
struct Node {
	T val;
	Node<T>* next;
	Node<T>(T val) : val(val), next(nullptr){}
};
template <typename T>
class QueueLinkedList {
	Node<T>* head;
	Node<T>* tail;
public:
	void enqueue(T val) {
		if (isEmpty()) {
			tail = head = new Node<T>(val);
			
		}
		else {
			Node<T>* n  = new Node<T>(val);
			tail->next = n;
			tail = n;
			
		}
	}
	T dequeue() {
		if (isEmpty()) return -1;
		Node<T>* tmp = head;
		if (head == tail) {
			T val = tail->val;
			head = tail = nullptr;
			delete tmp;
			return val;
		}
		T val = head->val;
		head = head->next;
		delete tmp;
		return val;
	}
	bool isEmpty() {
		return head == nullptr;
	}
	~QueueLinkedList() {
		Node<T>* tmp = head;
		while (tmp != nullptr) {
			tmp = tmp->next;
			delete head;
			head = tmp;
		}
	}
};

template <>
struct Node<std::string> {
	std::string val;
	Node* next;
	Node(std::string val) : val(val), next(nullptr) {}
};
template <>
class QueueLinkedList<std::string> {
	Node<std::string>* head;
	Node<std::string>* tail;
public:
	void enqueue(std::string val) {
		if (isEmpty()) {
			tail = head = new Node<std::string>(val);

		}
		else {
			Node<std::string>* n = new Node<std::string>(val);
			tail->next = n;
			tail = n;

		}
	}
	std::string dequeue() {
		if (isEmpty()) return "";
		Node<std::string>* tmp = head;
		if (head == tail) {
			std::string val = tail->val;
			head = tail = nullptr;
			delete tmp;
			return val;
		}
		std::string val = head->val;
		head = head->next;
		delete tmp;
		return val;
	}
	bool isEmpty() {
		return head == nullptr;
	}
	~QueueLinkedList() {
		Node<std::string>* tmp = head;
		while (tmp != nullptr) {
			tmp = tmp->next;
			delete head;
			head = tmp;
		}
	}
};

int main() {
	Queue<char>* q = new Queue<char>(4);
	std::cout << "Dequeued: " << q->dequeue() << '\n';
	q->enqueue('c');
	q->enqueue('b');
	q->enqueue('q');
	q->enqueue('w');
	q->enqueue('e');
	std::cout << "Dequeued: " << q->dequeue() << '\n';
	q->enqueue('e');
	std::cout << "Empty? " << q->isEmpty() << '\n';
	std::cout << "Dequeued: " << q->dequeue() << '\n';
	std::cout << "Dequeued: " << q->dequeue() << '\n';
	std::cout << "Dequeued: " << q->dequeue() << '\n';
	std::cout << "Dequeued: " << q->dequeue() << '\n';
	std::cout << "Empty? " << q->isEmpty() << '\n';
	delete q;
	Queue<std::string>* q2 = new Queue<std::string>(4);
	std::cout << q2->dequeue() << '\n';
	std::cout << "Empty? " << q2->isEmpty() << '\n';
	q2->enqueue("hi");
	q2->enqueue("I");
	q2->enqueue("am");
	q2->enqueue("Nikita");
	q2->enqueue("Toropov");
	std::cout << "Empty? " << q2->isEmpty() << '\n';
	std::cout << q2->dequeue() << '\n';
	q2->enqueue("Toropov");
	std::cout << q2->dequeue() << '\n';
	std::cout << q2->dequeue() << '\n';
	std::cout << q2->dequeue() << '\n';
	std::cout << q2->dequeue() << '\n';
	std::cout << q2->dequeue() << '\n';
	delete q2;
	QueueLinkedList<char>* ql = new QueueLinkedList<char>();
	std::cout << ql->isEmpty() << '\n';
	ql->dequeue();
	ql->enqueue('c');
	std::cout << ql->isEmpty() << '\n';
	ql->enqueue('b');
	ql->enqueue('s');
	ql->enqueue('n');
	ql->enqueue('a');
	std::cout << ql->dequeue() << '\n';
	std::cout << ql->dequeue() << '\n';
	std::cout << ql->dequeue() << '\n';
	std::cout << ql->dequeue() << '\n';
	std::cout << ql->dequeue() << '\n';
	std::cout << ql->dequeue() << '\n';
	std::cout << ql->isEmpty() << '\n';
	delete ql;
	QueueLinkedList<std::string>* qls = new QueueLinkedList<std::string>();
	qls->dequeue();
	qls->enqueue("Hello");
	std::cout << qls->isEmpty() << '\n';
}