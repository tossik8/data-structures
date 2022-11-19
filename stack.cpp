#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
#include <iterator>
#include <sstream>
#include <functional>   // std::negate
#include <algorithm>    
#include <cmath>
template <typename T>
class Stack {
	int size;
	int top;
	T* arr;
public:
	Stack(int size) : top(-1), size(size) {
		arr = new T[size];
	}

	void push(T i) {
		if (top < size-1) {
			arr[++top] = i;
		}
		else { 
			
			size *= 2;
			T* arr2 = new T[size];
			for (int i = 0; i <= top; ++i) {
				arr2[i] = arr[i];
			}
			delete[] arr;
			arr = arr2;
			arr[++top] = i;
		}
	}
	bool isEmpty() {
		return top == -1;
	}
	void pop() {
		if (top == -1) {
			return;
		}
		--top;
	}
	T peek() {
		if (top == -1) {
			return -1;
		}
		return arr[top];
	}
	void display() {
		for (int i = 0; i <= top; ++i) {
			std::cout << arr[i] << " ";
		}
		std::cout << '\n';
	}
	
	~Stack() {
		delete[] arr;
	}
};
template <typename T>
class StackLinkedList {
	template <typename T>
	struct Node {
		T val;
		Node<T>* next;
		Node(int i) : val(i), next(nullptr){}
	};
	Node<T>* head;
public:
	StackLinkedList() : head(nullptr){}
	~StackLinkedList() {
		Node<T>* tmp = head;
		while (head != nullptr) {
			tmp = head->next;
			std::cout << "Deleting: " << head->val << " ";
			delete head;
			head = tmp;
		}
		std::cout << '\n';
	}
	void push(int i) {
		Node<T>* n = new Node<T>(i);
		n->next = head;
		head = n;
	}
	void pop() {
		if (head == nullptr) {
			return;
		}
		Node<T>* tmp = head;
		head = head->next;
		tmp->next = nullptr;
		delete tmp;
		
		
	}
	bool isEmpty() {
		return head == nullptr;
	}
	T peek() {
		if (head != nullptr) {
			
			return head->val;
		}
		return -1;
	}
	void display() {
		Node<T>* tmp = head;
		while (tmp != nullptr) {
			std::cout << tmp->val << " ";
			tmp = tmp->next;
		}
		std::cout << '\n';
	}
};

void reverse(std::string&);
template <typename T>
void reverseList(std::list<T>&);
bool balancedParentheses(std::string&);
double evaluatePostfix(std::string);
double evaluatePrefix(std::string);
std::string infixToPostfix(std::string);
std::string infixToPrefix(std::string);
int main() {
	using std::cout;
	Stack<int>* stack = new Stack<int>(3);
	cout << "Is stack empty?" << stack->isEmpty() << '\n';
	stack->push(1);
	cout << "Is stack empty?" << stack->isEmpty() << '\n';
	cout << "Peek: " << stack->peek() << '\n';
	stack->push(2);
	stack->push(3);
	stack->push(4);
	cout << "Peek: " <<stack->peek() << '\n';
	stack->display();
	stack->pop();
	stack->display();
	stack->push(5);
	stack->display();
	stack->pop();
	stack->display();
	stack->push(4);
	stack->push(4);
	stack->push(4);
	stack->push(8);

	stack->push(12);

	stack->display();
	delete stack;
	StackLinkedList<int>* stack2 = new StackLinkedList<int>();
	stack2->push(2);
	stack2->push(3);
	stack2->push(4);
	stack2->push(1);
	cout << "Peek: " << stack2->peek() << '\n';
	stack2->pop();
	stack2->display();
	delete stack2;

	std::string s = "Nikita";
	reverse(s);
	cout << s << '\n';
	std::list<int> list;
	list.push_back(5);
	list.push_back(4);
	list.push_back(3);	
	list.push_back(2);
	list.push_back(1);
	std::list<int>::iterator it = list.begin();
	for (it; it != list.end(); ++it) {
		std::cout << *it;
	}
	std::cout << '\n';
	reverseList(list);
	
	for (it = list.begin(); it != list.end(); ++it) {
		cout << *it;
	}
	cout << '\n';
	cout << -(-3) << '\n';
	std::string s1 = ")[a(())b][]";
	cout << "Is " << s1 << " balanced? " <<balancedParentheses(s1) << '\n';
	cout << "-25 * -3 ^ 2 - 12 / 5 = " <<evaluatePostfix("-25 -3 2 ^ * 12 5 / -") << '\n';
	cout << "5 + 2  ^ 5 = " << evaluatePostfix("5 2 5 ^ +") << '\n';
	cout << "-25 * 3 - 12 / 5 = " << evaluatePrefix("- * -25 -3 / 12 5") << '\n';
	cout << "25 * 3 / 6 + -5 - 10 * 40 = " << evaluatePrefix("- + / * 25 3 6 -5 * 10 40") << '\n';
	cout << "25 * 3 / 6 + -5 - 10 * 40 = " << evaluatePostfix("25 3 * 6 / -5 10 40 * - +") << '\n';
	cout << "-25 * -3 - 12 / 5 = " << evaluatePostfix(infixToPostfix("-25 * -3 - 12 / 5")) << '\n';
	cout << "10 * ( -3 + 6 ) - ( 4 * 3 + 5 ) ^ 2 / 5 = " << evaluatePostfix(infixToPostfix("10 * ( -3 + 6 ) - ( 4 * 3 + 5 ) ^ 2 / 5")) << '\n';
	cout << "(14 + 704) * 280 = " << evaluatePostfix(infixToPostfix("( 14 + 704 ) * 280")) << '\n';
	cout << "59 + 30 - 12 ^ 2 * ( 3 / 2 ) = " << evaluatePrefix(infixToPrefix("59 + 30 - 12 ^ 2 * ( 3 / 2 )")) << '\n';
	cout << infixToPrefix("59 + ( 30 - 12 * ( 6 / 3 ) ) ^ 2 * ( 3 / 2 )") << '\n';
	cout << infixToPostfix("59 + ( 30 - 12 * ( 6 / 3 ) ) ^ 2 * ( 3 / 2 )") << '\n';
	cout << "59 + ( 30 - 12 * ( 6 / 3 ) ) ^ 2 * ( 3 / 2 ) = " << evaluatePrefix(infixToPrefix("59 + ( 30 - 12 * ( 6 / 3 ) ) ^ 2 * ( 3 / 2 )")) << '\n';
	cout << "59 + ( 30 - 12 * ( 6 / 3 ) ) ^ 2 * ( 3 / 2 ) = " << evaluatePostfix(infixToPostfix("59 + ( 30 - 12 * ( 6 / 3 ) ) ^ 2 * ( 3 / 2 )")) << '\n';
}
void reverse(std::string& s) {
	Stack<char>* stackChar = new Stack<char>(10);
	for (int i = 0; i < s.length(); ++i) {
		stackChar->push(s.at(i));
	}
	for (int i = 0; i < s.length(); ++i) {
		s.at(i) = stackChar->peek();
		stackChar->pop();
	}
	delete stackChar;
}
template <typename T>
void reverseList(std::list<T>& list) {
	std::list<int>::iterator it = list.begin();
	Stack<T>* stack3 = new Stack<T>(5);
	for (it; it != list.end(); ++it) {
		stack3->push(*it);
	}
	list.clear();
	while (!stack3->isEmpty()) {
		list.push_back(stack3->peek());
		stack3->pop();
	}
	delete stack3;
}
bool balancedParentheses(std::string& s) {
	Stack<char>* stack = new Stack<char>(s.length()/2);
	for (int i = 0; i < s.length(); ++i) {
		if (s.at(i) != '(' && s.at(i) != '{' && s.at(i) != '[' && s.at(i) != ')' && s.at(i) != '}' && s.at(i) != ']') continue;
		if (s.at(i) == '(' || s.at(i) == '{' || s.at(i) == '[') stack->push(s.at(i));
		else if (s.at(i) == ')' ) {
			if (s.at(i) == (char)(stack->peek()+1)) {
				stack->pop();
			}
			else {
				return false;
			}
		}
		else if (s.at(i) == '}') {
			
			if (s.at(i) == (char)(stack->peek() + 2)) {
				stack->pop();
			}
			else return false;
		}
		else if (s.at(i) == ']') {
			if (s.at(i) == (char)(stack->peek() + 2)) {
				stack->pop();
			}
			else return false;
		}
	}
	bool val = stack->isEmpty();
	delete stack;
	return val;
}
std::string infixToPrefix(std::string infix) {
	Stack<char>* operators = new Stack<char>(4);
	std::string prefix;
	std::stringstream is(infix);
	std::string str;
	std::vector<std::string> vec;
	while (getline(is, str, ' ')) {
		vec.push_back(str.c_str());
	}
	for (int i = vec.size() - 1; i >= 0; --i) {
		
		const char* c = vec.at(i).c_str();
		if (strcmp(c, ")") == 0) {
			operators->push(*c);
		}
		else if (strcmp(c, "(") == 0) {
			while (operators->peek() != ')') {
				prefix.insert(0, std::string(1, operators->peek()));
				prefix.insert(0, 1, ' ');
				operators->pop();

			}
			operators->pop();
		}
		else if ((strcmp(c, "*") != 0) && (strcmp(c, "/") != 0) && (strcmp(c, "+") != 0) && (strcmp(c, "-") != 0) && (strcmp(c, "^") != 0)) {
			prefix.insert(0, c);
			prefix.insert(0,1, ' ');
		}
		else if (strcmp(c, "^") == 0) {
			operators->push(*c);
		}
		else if ((strcmp(c, "*") == 0)) {
			if (operators->isEmpty()) operators->push(*c);
			else {
				while (!operators->isEmpty() && operators->peek() == '/' || operators->peek() == '*' || operators->peek() == '^') {
					prefix.insert(0, std::string(1, operators->peek()));
					prefix.insert(0, 1, ' ');
					
					operators->pop();

				}
				operators->push(*c);

			}

		}
		else if (strcmp(c, "/") == 0) {
			if (operators->isEmpty()) operators->push(*c);
			else {
				while (!operators->isEmpty() && operators->peek() == '/' || operators->peek() == '*' || operators->peek() == '^') {
					prefix.insert(0, std::string(1, operators->peek()));
					prefix.insert(0, 1, ' ');
					operators->pop();

				}
				operators->push(*c);
			}
		}
		else if (strcmp(c, "+") == 0) {
			if (operators->isEmpty()) operators->push(*c);
			else {
				while (!operators->isEmpty() && (operators->peek() == '-' || operators->peek() == '*' || operators->peek() == '^' || 
					operators->peek() == '/')) {
					prefix.insert(0, std::string(1, operators->peek()));
					prefix.insert(0, 1, ' ');
				
					operators->pop();

				}
				operators->push(*c);
			}
		}
		else {
			if (operators->isEmpty()) operators->push(*c);
			else {
				while (!operators->isEmpty() && (operators->peek() == '+' || operators->peek() == '*' || operators->peek() == '^'
					|| operators->peek() == '/')) {
					prefix.insert(0, std::string(1, operators->peek()));
					prefix.insert(0, 1, ' ');
				
					operators->pop();

				}
				operators->push(*c);
			}
		}	
	}
	while (!operators->isEmpty()) {

		prefix.insert(0, std::string(1,operators->peek()));
		operators->pop();
		if(!operators->isEmpty())
			prefix.insert(0, 1,' ');

		
	}
	delete operators;
	return prefix;
}
std::string infixToPostfix(std::string infix) {
	Stack<char>* operators = new Stack<char>(4);
	std::string postfix;
	char* ptr;
	char* cstr2 = new char[infix.length()+1];
	strcpy(cstr2, infix.c_str());
	ptr = strtok(cstr2, " ");
	while (ptr != NULL) {
		const char* c = ptr;
		if (strcmp(c, "(") == 0) {
			operators->push(*c);
		}
		else if (strcmp(c, ")") == 0) {
			while (operators->peek() != '(') {
				postfix.push_back(operators->peek());
				postfix.push_back(' ');
				operators->pop();

			}
			operators->pop();
		}
		else if ((strcmp(c, "*") != 0)&& (strcmp(c, "/") != 0) && (strcmp(c, "+") != 0) && (strcmp(c, "-") != 0) && (strcmp(c, "^") != 0)) {
			postfix.append(c);
			postfix.push_back(' ');

		}
		else if (strcmp(c, "^") == 0) {
			operators->push(*c);
		}
		else if ((strcmp(c, "*") == 0)) {
			if (operators->isEmpty()) operators->push(*c);
			else {
				while (!operators->isEmpty() && operators->peek() == '/' || operators->peek() == '*' || operators->peek() == '^') {
					
					postfix.push_back(operators->peek());
					postfix.push_back(' ');
					operators->pop();
				}
				operators->push(*c);

			}
			
		}
		else if (strcmp(c, "/") == 0) {
			if (operators->isEmpty()) operators->push(*c);
			else {
				while (!operators->isEmpty() && operators->peek() == '/' || operators->peek() == '*' || operators->peek() == '^') {
					postfix.push_back(operators->peek());
					postfix.push_back(' ');
					operators->pop();
				}
				operators->push(*c);
			}
		}
		else if (strcmp(c, "+") == 0) {
			if (operators->isEmpty()) operators->push(*c);
			else {
				while (!operators->isEmpty() &&(operators->peek() == '-' || operators->peek() == '*' || operators->peek() == '^' || operators->peek() == '/')) {
					postfix.push_back(operators->peek());
					postfix.push_back(' ');
					operators->pop();
				}
				operators->push(*c);
			}
		}
		else {
			if (operators->isEmpty()) operators->push(*c);
			else {
				while (!operators->isEmpty() && (operators->peek() == '+' || operators->peek() == '*' || operators->peek() == '^' || operators->peek() == '/')){
					postfix.push_back(operators->peek());
					postfix.push_back(' ');
					operators->pop();
				}
				operators->push(*c);
			}
		}
		ptr = strtok(NULL, " ");
		
	}
	while (!operators->isEmpty()) {
		postfix = postfix + operators->peek() + " ";
		operators->pop();

	}
	delete operators;
	delete[] cstr2;
	return postfix;
}
double evaluatePostfix(std::string postfix) {
	Stack<double>* s = new Stack<double>(4);
	char* ptr;
	char* cstr = new char[postfix.length() + 1];
	strcpy(cstr, postfix.c_str());
	ptr = strtok(cstr, " ");
	while (ptr != NULL) { 
		const char* c = ptr;
		if (strcmp(c, "*") == 0) {
			double op2 = s->peek();
			s->pop();
			double op1 = s->peek();
			s->pop();
			s->push(op1 * op2);
		}
		else if (strcmp(c, "/") == 0) {
			double op2 = s->peek();
			s->pop();
			double op1 = s->peek();
			s->pop();
			s->push(op1 / op2);
		}
		else if (strcmp(c, "-") == 0) {
			double op2 = s->peek();
			s->pop();
			double op1 = s->peek();
			s->pop();
			s->push(op1 - op2);
		}
		else if (strcmp(c, "+") == 0) {
			double op2 = s->peek();
			s->pop();
			double op1 = s->peek();
			s->pop();
			s->push(op1 + op2);
		}
		else if (strcmp(c, "^") == 0) {
			double op2 = s->peek();
			s->pop();
			double op1 = s->peek();
			s->pop();
			s->push(std::pow(op1, op2));
		}
		else{
			double i = std::stod(c);
			s->push(i);
		}
		ptr = strtok(NULL, " ");
	}
	double res = s->peek();
	s->pop();
	delete s;
	delete[] cstr;
	return res;
}
double evaluatePrefix(std::string prefix) {
	Stack<double>* s = new Stack<double>(4);
	std::stringstream is(prefix);
	std::string str;
	std::vector<std::string> vec;
	while (getline(is, str, ' ')) {
		vec.push_back(str);
	}
	
	for(int i = vec.size()-1; i >= 0; --i) {
		if (strcmp(vec[i].c_str(), "*") == 0) {
			double op1 = s->peek();
			s->pop();
			double op2 = s->peek();
			s->pop();
			s->push(op1 * op2);
		}
		else if (strcmp(vec[i].c_str(),"/") == 0) {
			double op1 = s->peek();
			s->pop();
			double op2 = s->peek();
			s->pop();
			s->push(op1 / op2);
		}
		else if (strcmp(vec[i].c_str(), "-") == 0) {
			double op1 = s->peek();
			s->pop();
			double op2 = s->peek();
			s->pop();
			s->push(op1 - op2);
		}
		else if (strcmp(vec[i].c_str(), "+") == 0) {
			double op1 = s->peek();
			s->pop();
			double op2 = s->peek();
			s->pop();
			s->push(op1 + op2);
		}
		else if (strcmp(vec[i].c_str(), "^") == 0) {
			double op1 = s->peek();
			s->pop();
			double op2 = s->peek();
			s->pop();
			s->push(std::pow(op1,op2));
		}
		else {
			double i2 = std::stod(vec[i].c_str());
			s->push(i2);

		}
	}
	double res = s->peek();
	s->pop();
	delete s;
	return res;
}