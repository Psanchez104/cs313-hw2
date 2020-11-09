//Questions 6

#include <iostream>
#include <string>
#include <fstream>

struct Node {
	char data;
	Node* next;
};

class Stack {
private:
	int size;
	Node* top;
public:
	Stack();
	~Stack();
	void push(char c);
	char pop();
	char peek();
	int getSize();
	bool isEmpty();
};

Stack::Stack() {
	//constructor
	//std::cout << "In the Constructor\n";
	size = 0;
	top = nullptr;
}
Stack::~Stack() {
	//destructor
	//std::cout << "In the destructor\n";
	if (!isEmpty()) {
		while (!isEmpty()) {
			pop();
		}
	}
	else std::cout << "Stack is empty";
}
void Stack::push(char c) {
	Node* temp = new Node;
	temp->data = c;
	temp->next = top;
	top = temp;
	size++;
}
char Stack::pop() {
	if (!isEmpty()) {
		Node* temp;
		temp = top;
		top = top->next;
		size--;
		return temp->data;
	}
	else std::cout << "Stack is empty";
}
char Stack::peek() {
	if (!isEmpty()) return top->data;
	else std::cout << "Stack is empty";
}
int Stack::getSize() {
	return size;
}
bool Stack::isEmpty() {
	return(size == 0);
}

int main() {

	std::string test = "When Chuck Norris falls in water, Chuck Norris doesn't get wet. Water gets Chuck Norris.";
	std::string output;
	Stack myStack;

	for (int i = 0; i < test.length(); i++) {
		if (test[i] == ' ' || test[i] == ',' || test[i] == '.') {
			while (!myStack.isEmpty()) {
				output += myStack.pop();
			}
			output += test[i];
			continue;
		}
		else {
			myStack.push(test[i]);
		}
	}

	std::cout << output;




	//std::ifstream inFile;
	//inFile.open("Chuck Norris Jokes.txt");

	//if (inFile.fail()) {
	//	std::cerr << "Error opening file\n";
	//	exit(1);
	//}
	//else {
	//	inFile >> currentString;
	//	std::cout << currentString;
	//}
}