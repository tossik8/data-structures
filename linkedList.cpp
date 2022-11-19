#include <iostream>
template <class T>
struct Node {
	T val;
	Node* next;
	Node(T val) : val(val), next(nullptr) {}
};
template <class T>
class LinkedList {
	Node<T>* head;
public:
	bool isEmpty() {
		return head == nullptr;
	}
	void add(T i) {
		if (head == nullptr) {
			head = new Node<T>(i);
		}
		else {
			Node<T>* tmp = head;
			while (tmp->next != nullptr) {
				tmp = tmp->next;
			}
			tmp->next = new Node<T>(i);
		}
	}
	void addAtPosition(T i, int index) {
		if (head == nullptr) {
			head = new Node<T>(i);
		}
		else {
			Node<T>* tmp = head;
			if (index == 0) {
				head = new Node<T>(i);
				head->next = tmp;
			}
			else {
				for (int i = 0; i < index - 1; ++i) {
					tmp = tmp->next;
				}
				Node<T>* next = tmp->next;
				Node<T>* n = new Node<T>(i);
				tmp->next = n;
				n->next = next;
			}

		}
	}
	void deleteAtPosition(int index) {
		if (index == 0) {
			Node<T>* tmp = head->next;
			delete head;
			head = tmp;
		}
		else {
			Node<T>* tmp = head;
			for (int i = 0; i < index - 1; ++i) {
				tmp = tmp->next;
			}
			Node<T>* tmp2 = tmp->next;
			tmp->next = tmp2->next;
			delete tmp2;
		}


	}
	void reverse() {
		Node<T>* tmp, * current = head;
		Node<T>* prev = NULL;
		while (current != nullptr) {
			tmp = current->next;
			current->next = prev;
			prev = current;
			current = tmp;
		}
		head = prev;
	}
	T reverseRecursively(Node<T>* current, Node<T>* prev = nullptr) {
		if (current == nullptr) {
			head = prev;
			return head->val;
		}
		else {
			Node<T>* tmp = current->next;
			current->next = prev;
			reverseRecursively(tmp, current);

		}
	}
	void displayReverseRecursively(Node<T>* tmp) {
		if (tmp == nullptr) return;
		else {
			displayReverseRecursively(tmp->next);
			std::cout << tmp->val << " ";
		}
	}
	void displayRecursively(Node<T>* tmp) {
		if (tmp == nullptr) return;
		else {
			std::cout << tmp->val << " ";
			displayReverseRecursively(tmp->next);

		}
	}
	void display() {
		Node<T>* tmp = head;
		while (tmp != nullptr) {
			std::cout << tmp->val << " ";
			tmp = tmp->next;
		}
		std::cout << '\n';
	}
	~LinkedList() {
		Node<T>* tmp = head;
		while (head != nullptr) {
			tmp = tmp->next;
			std::cout << "Deleting " << head->val << " ";
			delete head;
			head = tmp;

		}
		std::cout << '\n'

	}
	Node<T>* getHead() {
		return head;
	}
	
};

int main() {
	LinkedList<int>* list = new LinkedList<int>();
	std::cout << "Empty? " << list->isEmpty() << '\n';
	list->add(5);
	list->add(8);
	list->add(3);
	list->add(87);
	list->add(85);
	list->addAtPosition(20, 1);
	list->addAtPosition(200, 6);
	list->addAtPosition(2001, 7);
	list->addAtPosition(2002, 3);
	list->addAtPosition(200, 0);
	list->display();
	list->deleteAtPosition(3);

	list->deleteAtPosition(8);
	list->deleteAtPosition(0);
	list->display();
	list->reverse();
	list->display();
	std::cout << "Head after reversing: " <<list->reverseRecursively(list->getHead()) << '\n';

	list->display();


	delete list;
}