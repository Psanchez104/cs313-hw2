#include <iostream>
#include <string>

struct Node {
	std::string data;
	Node* next;
};

class Stack {
private:
	int size;
	Node* top;
public:
	Stack();
	~Stack();
	void push(std::string c);
	std::string pop();
	std::string peek();
	int getSize();
	bool isEmpty();
	void print();
	void change(int i, std::string);
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
void Stack::push(std::string c) {
	Node* temp = new Node;
	temp->data = c;
	temp->next = top;
	top = temp;
	size++;
}
std::string Stack::pop() {
	if (!isEmpty()) {
		Node* temp;
		temp = top;
		top = top->next;
		size--;
		return temp->data;
	}
	else std::cout << "Stack is empty";
}
std::string Stack::peek() {
	if (!isEmpty()) return top->data;
	else std::cout << "Stack is empty";
}
int Stack::getSize() {
	return size;
}
bool Stack::isEmpty() {
	return(size == 0);
}

//list all elements in the stack... part a
void Stack::print() {
	if (isEmpty()) std::cout << "Stack is empty";
	else {
		Node* temp;
		temp = top;
		while (temp != NULL) {
			std::cout << temp->data << std::endl;
			temp = temp->next;
		}
	}
}

//iterate thorugh stack and change an element based on its position... part b
void Stack::change(int i, std::string s) {
	if (isEmpty()) {
		std::cout << "Stack is empty";
		return;
	}
	int counter = 0;
	Node* temp = top;
	while (true) {
		if (counter == i) {
			temp->data = s;
			break;
		}
		if (temp->next != nullptr) {
			temp = temp->next;
			counter++;
		}
		else break;
	}
	
}

int main() {
	Stack myStack;
	myStack.push("Pablo");
	myStack.push("Jess");
	myStack.push("Emilio");
	myStack.push("Pedro");

	myStack.print();

	myStack.change(0, "Allen");

	std::cout << std::endl;

	myStack.print();
}