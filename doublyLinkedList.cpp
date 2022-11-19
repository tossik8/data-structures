#include <iostream>
template<typename T>
struct Node {
	T val;
	Node<T>* next;
	Node<T>* prev;
	Node(T i) :val(i), next(nullptr),prev(nullptr) {}
};
template<typename T>
class DoublyLinkedList {
	Node<T>* head;
public:
	~DoublyLinkedList() {
		Node<T>* tmp = head;
		while (head != nullptr) {
			tmp = tmp->next;
			std::cout << "Deleting " <<head->val << " ";
			delete head;
			head = tmp;

		}
		std::cout << '\n';
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
			Node<T>* n = new Node<T>(i);
			tmp->next = n;
			n->prev = tmp;
			n->next = nullptr;
		}
	}
	void reverse() {
		if (head == nullptr || head->next == nullptr){
			return;
		}
		Node<T>* temp = NULL;
		Node<T>* current = head;
		while (current != NULL){
			temp = current->prev;
			current->prev = current->next;
			current->next = temp;
			current = current->prev;
		}  
		if (temp != NULL)
			head = temp->prev;
	}
	void reverseRecursively(Node<T>* node) {
		if (node == nullptr) return;
		if (node->next == nullptr) {
			head = node;
			node->next = node->prev;
			node->prev = nullptr;
			return;
		}
		else {
			reverseRecursively(node->next);
			Node<T>* tmp = node->next;
			node->next = node->prev;
			node->prev = tmp;
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
	Node<T>* getHead() {
		return head;
	}
};

int main() {
	DoublyLinkedList<int>* list = new DoublyLinkedList<int>();
	list->add(5);
	list->add(6);
	list->add(7);
	list->add(8);
	list->display();
	list->reverse();
	list->display();
	list->reverseRecursively(list->getHead());
	list->display();
	delete list;
}