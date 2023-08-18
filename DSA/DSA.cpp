#include <iostream>
#include "Queue.h"
#include "Stack.h"

int main()
{
	Queue *queue = new Queue();
	queue->Enqueue(1);
	queue->Enqueue(2);
	queue->Enqueue(3);
	queue->Print();

	cout << "Dequeue: " << queue->Dequeue() << endl;
	queue->Print();

	cout << "Get front: " << queue->GetFront() << endl;
	queue->Print();

	Stack* stack = new Stack();
	stack->Push(1);
	stack->Push(2);
	stack->Push(3);
	stack->Print();

	cout << "Pop: " << stack->Pop() << endl;
	stack->Print();

	cout << "Get top: " << stack->GetTop() << endl;
	stack->Print();
}