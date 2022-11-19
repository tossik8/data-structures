#include <iostream>
#include <queue>
struct EmptyTreeException : std::exception {
	const char* what() const throw() {
		return "Empty tree";
	}
};
struct Node {
	int val;
	Node* left, * right;
	Node(int val) : val(val), left(nullptr), right(nullptr) {};
};
class BinarySearchTree {
	Node* root;
public:
	BinarySearchTree() : root(nullptr) {}
	void insert(int val) {
		if (root == nullptr) {
			root = new Node(val);
		}
		else {
			bool left;
			Node* tmp = root, * points = tmp;
			while (tmp != nullptr) {
				points = tmp;
				if (val > tmp->val) {
					tmp = tmp->right;
					left = false;
				
				}
				else if (val <= tmp->val) {
					tmp = tmp->left;
					left = true;
				}
				
			}
			if (left) {
				points->left = new Node(val);
			}
			else {
				points->right = new Node(val);
			}

		}
	}
	bool search(int val) {
		if (root == nullptr) return false;
		else {
			Node* tmp = root;
			while(tmp!= nullptr){
				if (tmp->val == val) return true;
				if (tmp->val < val) {
					tmp = tmp->right;
				}
				else tmp = tmp->left;
			}
			return false;
		}
	}
	Node* insertRecursively(int val, Node* root) {
		if (root == nullptr) {
			root = new Node(val);
		}
		else if (val > root->val) {
			root->right = insertRecursively(val, root->right);
		}
		else {
			root->left = insertRecursively(val, root->left);
		}
		return root;
	}
	Node* getRoot() {
		return root;
	}
	bool searchRecursively(int val, Node* root) {
		if (root == nullptr) return false;
		if (root->val == val) return true;
		else if (root->val > val) { searchRecursively(val, root->left); }
		else { searchRecursively(val, root->right); }
	}
	int findMin() {
		if (root == nullptr) {
			throw EmptyTreeException();
		}
		Node* tmp = root;
		while (tmp->left != nullptr) {
			tmp = tmp->left;
		}
		return tmp->val;
	}
	int findMax() {
		if (root == nullptr) {
			throw EmptyTreeException();
		}
		Node* tmp = root;
		while (tmp->right != nullptr) {
			tmp = tmp->right;
		}
		return tmp->val;
	}
	Node* findMinRecursively(Node* root) {
		if (root == nullptr) throw EmptyTreeException();
		if (root->left == nullptr) return root ;
		findMinRecursively(root->left);
	}
	Node* findMaxRecursively(Node* root) {
		if (root == nullptr) throw EmptyTreeException();
		if (root->right == nullptr) return root;
		findMaxRecursively(root->right);
	}
	int findHeight(Node* root) {
		if (root == nullptr) {
			return -1;
		}
		int leftHeight = findHeight(root->left);
		int rightHeight = findHeight(root->right);
		return std::max(leftHeight, rightHeight) + 1;
	}
	void breadthFirstTraversal() {
		std::queue<Node*> q;
		q.push(root);
		while (!q.empty()) {
			std::cout << q.front()->val << " ";
			if(q.front()->left != nullptr)	q.push(q.front()->left); 
			if(q.front()->right != nullptr)   q.push(q.front()->right);
			q.pop();
		}
	}
	void preorderTraversal(Node* root) {
		if (root == nullptr) {
			return;
		}
		std::cout << root->val << " ";
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}
	void inorderTraversal(Node* root) {
		if (root == nullptr) {
			return;
		}
		inorderTraversal(root->left);
		std::cout << root->val << " ";
		inorderTraversal(root->right);
	}
	void postorderTraversal(Node* root) {
		if (root == nullptr) {
			return;
		}
		postorderTraversal(root->left);
		postorderTraversal(root->right);
		std::cout << root->val << " ";
	}
	bool isSubtreeSmaller(Node* root, int val) {
		if (root == nullptr) return true;
		if (root->val <= val && isSubtreeSmaller(root->left, val) && isSubtreeSmaller(root->right, val)) {
			return true;
		}
		else return false;
	}
	bool isSubtreeGreater(Node* root, int val) {
		if (root == nullptr) return true;
		if (root->val > val && isSubtreeGreater(root->left, val) &&
			isSubtreeGreater(root->right, val)) { 
			return true;
		}
		else return false;
	}
	bool isBinarySearchTree(Node* root) {
		if (root == nullptr) return true;
		if (isSubtreeSmaller(root->left, root->val) && isSubtreeGreater(root->right, root->val) &&
			isBinarySearchTree(root->left) && isBinarySearchTree(root->right)) return true;
		return false;
	}
	Node* deleteNode(Node* root, int val) {
		if (root == nullptr) return nullptr;
		if (root->val > val) root->left = deleteNode(root->left, val);
		else if (root->val < val) {
			root->right = deleteNode(root->right, val);
		}
		else {
			if (root->left == nullptr && root->right == nullptr) {
				delete root;
				return nullptr;
			}
			else if (root->left == nullptr && root->right != nullptr) {
				Node* tmp = root->right;
				delete root;
				return tmp;
			}
			else if (root->left != nullptr && root->right == nullptr) {
				Node* tmp = root->left;
				delete root;
				return tmp;
			}
			else {
				Node* min = this->findMinRecursively(root->right);
				root->val = min->val;
				root->right = deleteNode(root->right, min->val);
				return root;
				
			}
		} 
		return root;
	}
	Node* getSuccessor(Node* root, int data) {
		Node* current = find(root, data);
		if (current == nullptr) return nullptr;
		if (current->right != nullptr) {
			return findMinRecursively(current->right);
		}
		Node* successor = nullptr;
		Node* ancestor = root;
		while (ancestor != current) {
			if (data < ancestor->val) {
				successor = ancestor;
				ancestor = ancestor->left;
			}
			else {
				ancestor = ancestor->right;
			}
		}
		return successor;

	}
	Node* getPredecessor(Node* root, int data) {
		Node* current = find(root, data);
		if (current == nullptr) return nullptr;
		if (current->left != nullptr) return current->left;
		Node* predecessor = nullptr;
		while (root != current) {
			if (data > root->val) {
				predecessor = root;
				root = root->right;
			}
			else {
				root = root->left;
			}
		}
		return predecessor;
	}
	Node* find(Node* root, int data) {
		if (root == nullptr) return nullptr;
		else if (root->val == data) return root;
		else if (root->val > data) find(root->left, data);
		else find(root->right, data);
	}
};
int main() {
	BinarySearchTree* tree = new BinarySearchTree();
	try {
		std::cout << "Minimal value in a tree is " << tree->findMin() << '\n';
		std::cout << "Maximax value in a tree is " << tree->findMax() << '\n';
	}
	catch (EmptyTreeException e) {
		std::cout << e.what() << '\n';
	}
	try {
		std::cout << "Max value in a tree is " << tree->findMaxRecursively(tree->getRoot())->val << '\n';
		std::cout << "Min value in a tree is " << tree->findMinRecursively(tree->getRoot())->val << '\n';
	}
	catch (EmptyTreeException e) {
		std::cout << e.what() << '\n';
	}
	tree->insert(15); tree->insert(14); tree->insert(18);
	tree->insert(10); tree->insert(1); tree->insert(100);
	tree->insert(20); tree->insert(13); tree->insert(25);
	std::cout << "Is 50 in a tree? "<<tree->search(50) << '\n';
	std::cout << "Is 20 in a tree? " << tree->search(20) << '\n';
	std::cout << "Is 10 in a tree? " << tree->search(10) << '\n';
	std::cout << "Is 15 in a tree? " << tree->search(15) << '\n';
	std::cout << "Is 0 in a tree? " << tree->search(0) << '\n';
	std::cout << "Is 18 in a tree? " << tree->search(18) << '\n';
	std::cout << "Is 1 in a tree? " << tree->search(1) << '\n';
	std::cout << "Is 100 in a tree? " << tree->search(100) << '\n';
	std::cout << "Is 25 in a tree? " << tree->search(25) << '\n';
	std::cout << "Is 14 in a tree? " << tree->search(14) << '\n';
	std::cout << "Is 200 in a tree? " << tree->search(200) << '\n';
	std::cout << "Is 101 in a tree? " << tree->search(101) << '\n';
	tree->insertRecursively(50, tree->getRoot());
	std::cout << "Is 50 in a tree? " << tree->search(50) << '\n';
	std::cout << "Is 51 in a tree? " << tree->searchRecursively(51, tree->getRoot()) << '\n';
	std::cout << "Is 18 in a tree? " << tree->searchRecursively(18, tree->getRoot()) << '\n';
	try {
		std::cout << "Minimal value in a tree is " << tree->findMin() << '\n';
		std::cout << "Maximal value in a tree is " << tree->findMax() << '\n';
	}
	catch (EmptyTreeException e) {
		std::cout << e.what() << '\n';
	}
	try {
		std::cout << "Minimal value in a tree is " << tree->findMinRecursively(tree->getRoot())->val << '\n';
		std::cout << "Maximal value in a tree is " << tree->findMaxRecursively(tree->getRoot())->val << '\n';
	}
	catch (EmptyTreeException e) {
		std::cout << e.what() << '\n';
	}
	std::cout << "The height of a tree is " << tree->findHeight(tree->getRoot()) << '\n';

	std::cout << "Breadth-first traversal: ";
	tree->breadthFirstTraversal();
	std::cout << '\n';
	std::cout << "Preorder traversal: ";
	tree->preorderTraversal(tree->getRoot());
	std::cout << '\n';
	std::cout << "Inorder traversal: ";
	tree->inorderTraversal(tree->getRoot());
	std::cout << '\n';
	std::cout << "Postorder traversal: ";
	tree->postorderTraversal(tree->getRoot());
	std::cout << '\n';
	std::cout << "Is tree a binary seacrh one? " << tree->isBinarySearchTree(tree->getRoot()) << '\n';
	std::cout << "Delete: 10\n";
	tree->deleteNode(tree->getRoot(), 10);
	std::cout << "Postorder traversal: ";
	tree->postorderTraversal(tree->getRoot());
	std::cout << '\n';
	std::cout << "Is 10 in a tree? " << tree->search(10) << '\n';
	std::cout << "Successor of 18 is " << tree->getSuccessor(tree->getRoot(), 18)->val << '\n';
	std::cout << "Delete: 100\n";
	tree->deleteNode(tree->getRoot(), 100);
	std::cout << "Inorder traversal: ";
	tree->inorderTraversal(tree->getRoot());
	std::cout << '\n';
	std::cout << "Is 100 in a tree? " << tree->search(100) << '\n';
	std::cout << "Successor of 1 is " << tree->getSuccessor(tree->getRoot(), 1)->val << '\n';
	std::cout << "Successor of 10 is " << tree->getSuccessor(tree->getRoot(), 10) <<'\n';
	std::cout << "Successor of 15 is " << tree->getSuccessor(tree->getRoot(), 15)->val << '\n';
	std::cout << "Successor of 25 is " << tree->getSuccessor(tree->getRoot(), 25)->val << '\n';
	std::cout << "Successor of 18 is " << tree->getSuccessor(tree->getRoot(), 18)->val << '\n';
	std::cout << "Successor of 50 is " << tree->getSuccessor(tree->getRoot(), 50) << '\n';
	std::cout << "Predecessor of 50 is " << tree->getPredecessor(tree->getRoot(), 50)->val << '\n';
	std::cout << "Predecessor of 1 is " << tree->getPredecessor(tree->getRoot(), 1) << '\n';
	std::cout << "Predecessor of 10 is " << tree->getPredecessor(tree->getRoot(), 10) << '\n';
	std::cout << "Predecessor of 15 is " << tree->getPredecessor(tree->getRoot(), 15)->val << '\n';
	std::cout << "Predecessor of 14 is " << tree->getPredecessor(tree->getRoot(), 14)->val << '\n';


} 