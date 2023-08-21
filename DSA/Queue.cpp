#include "Queue.h"

Queue::Queue() {
	this->list = new LinkedList<int>();
}

void Queue::Print() {
	this->list->Print();
}

void Queue::Enqueue(int value) {
	this->list->InsertToTail(value);
}

int Queue::Dequeue() {
	if (IsEmpty()) {
		cout << "Queue is empty!";
		return 0;
	}

	Node<int> *front_node = this->list->RemoveAt(0);
	int value = front_node->GetData();
	delete(front_node);

	return value;
}

int Queue::GetFront() {
	if (IsEmpty()) {
		cout << "Queue is empty!";
		return 0;
	}

	return this->list->GetNodeAt(0)->GetData();
}

bool Queue::IsEmpty() {
	return this->list->IsEmpty();
}

