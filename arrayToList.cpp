#include <iostream>
struct Node {
	int data;
	Node* next;
};
	Node* arrayToList(const int arr[], size_t size) {
		if (size != 0) {
			Node* head = new Node{ arr[0], nullptr };
			Node* prev = head;
			for (int i = 1; i < size; ++i) {
				Node* nextEl = new Node{ arr[i], nullptr };
				prev->next = nextEl;
				prev = nextEl;

			}
			return head;
		}
		return NULL;
	}
	Node* removeOdd(Node* head) {
		bool first = false;
		Node* tmp = head;
		Node* last = nullptr;
		while (tmp != nullptr) {

			if (tmp->data % 2 != 0) {
				Node* tmp2 = tmp->next;
				std::cout << "DEL: " << tmp->data << " ";
				delete tmp;
				tmp = tmp2;

			}
			else {
				if (first == false) {
					head = tmp;
					last = head;
					tmp = tmp->next;
					first = true;
				}
				else {
					last->next = tmp;
					last = tmp;
					tmp = tmp->next;
				}
			}
		}
		std::cout << "\n";
		return first ? head : nullptr;
	}
	void showList(const Node* head) {
		if (head == nullptr) std::cout << "Empty list\n";
		else {
			while (head != nullptr) {
				std::cout << head->data << " ";
				head = head->next;
			}
			std::cout << "\n";
		}

	}
	void deleteList(Node*& head) {
		while (head != nullptr) {
			std::cout << "DEL: " << head->data << " ";
			Node* tmp = head->next;
			delete head;
			head = tmp;
		}
		std::cout << "\n";
	}
int main() {
	int arr[] = { 1,2,3,4,5,6 };
	size_t size = sizeof(arr) / sizeof(*arr);
	Node* head = arrayToList(arr, size);
	showList(head);
	head = removeOdd(head);
	showList(head);
	deleteList(head);
	showList(head);
}