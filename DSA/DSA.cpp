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
	linkedList->Print();

	linkedList->Reversal();
	linkedList->Print();

	// test loop
	//Node<int>* temp_node = linkedList->GetNodeAt(3);
	//cout << temp_node->GetData() << endl;
	//temp_node->SetNextNode(linkedList->GetNodeAt(0));
	string check_loop_string = linkedList->IsLooped() ? "Looped" : "Not looped";
	cout << check_loop_string << endl;
}
