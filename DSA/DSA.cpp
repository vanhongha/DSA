#include <iostream>
#include "LinkedList.h"

int main()
{
	LinkedList<int>* linkedList = new LinkedList<int>();

	linkedList->InsertToHead(1);
	linkedList->InsertToHead(2);
	linkedList->InsertToHead(3);
	linkedList->InsertToTail(4);
	linkedList->InsertAt(3, 7);
	linkedList->RemoveAt(4);
	linkedList->RemoveAt(3);
	linkedList->RemoveAt(10);

	linkedList->Print();
}
