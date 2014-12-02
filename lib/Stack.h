/*
 * Simple implementation of a STACK to learn and get familiarized with C++.
 *
 * @author: Alan Mauricio García García
 */

#include <iostream>
#include <string>

// Struct to use as abstract implementation of the stack core / list
 struct StackNode
 {
 	int data;
 	struct StackNode *next;
 };

 typedef struct StackNode node;

// The abstract implementation of a Stack
 class stack
 {
 public:
 	stack();

 	void pop();
 	void print();
 	void push(int e);
 	bool isEmpty();
 	int peek();
 	int getSize();

 private:
 	// Variable to keep track of the stack size
 	int size;
 	// Node to implement the stack
 	node *elements;
 };

// Default constructor initializes size as zero and the list
 stack::stack()
 {
 	elements = (node*) malloc(sizeof(node));
 	size = 0;
 }

// Returns the size of the stack
 int stack::getSize()
 {
 	return size;
 }

// Returns true if the stack is empty, false otherwise
 bool stack::isEmpty()
 {
 	if(size >= 1) {
 		return false;
 	} 
 	return true;
 }

// Returns the top element of the stack, but does not removes it
 int stack::peek()
 {
 	if(!isEmpty()) {
 		return elements->data;
 	}
 }

// Pushes a new element into the stack
 void stack::push(int e)
 {
 	node *pushed = (node*) malloc(sizeof(node));
 	pushed->data = e;
 	pushed->next = elements;
 	elements = pushed;
 	size += 1;
 }

// Removes the top element of the stack
 void stack::pop()
 {
 	if(!isEmpty()){
 		node *pop = elements->next;
 		elements = pop;
 		size -= 1;
 	}
 }

// Prints a representation of the stack with each element on a seperate line and element counter
 void stack::print()
 {
 	if(isEmpty()){
 		std::cout << "[ empty ]" << std::endl;
 		return;
 	}

 	int count = getSize();
 	node *current = elements;
 	for (int i = 0; i < getSize(); ++i)
 	{
 		std::cout << "[" << count << "]: " << current->data << std::endl;
 		current = current->next;
 		count--;
 	}
 }
