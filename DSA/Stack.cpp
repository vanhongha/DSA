#include "Stack.h"

Stack::Stack() {
	this->list = new LinkedList<int>();
}

void Stack::Print() {
	this->list->Print();
}

void Stack::Push(int value) {
	this->list->InsertToHead(value);
}

int Stack::Pop() {
	if (IsEmpty()) {
		cout << "Stack is empty!";
		return 0;
	}

	Node<int>* front_node = this->list->RemoveAt(0);
	int value = front_node->GetData();
	delete(front_node);

	return value;
}

int Stack::GetTop() {
	if (IsEmpty()) {
		cout << "Queue is empty!";
		return 0;
	}

	return this->list->GetNodeAt(0)->GetData();
}

bool Stack::IsEmpty() {
	return this->list->IsEmpty();
}