#include <iostream>
#include "Queue.h"

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
}