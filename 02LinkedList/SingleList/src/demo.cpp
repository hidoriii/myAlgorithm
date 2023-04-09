#include <iostream>

#include "Solution.h"


int main()
{
	//ListNode* head = new ListNode(5);
	MyLinkedList myLinkedList;
	myLinkedList.addAtHead(1);
	myLinkedList.addAtTail(3);
	myLinkedList.addAtIndex(1, 2);    // 链表变为 1->2->3
	myLinkedList.printLinkedList();
	std::cout << myLinkedList.get(1) << std::endl;	// 返回 2
	myLinkedList.deleteAtIndex(1);    // 现在，链表变为 1->3
	myLinkedList.printLinkedList();
	std::cout << myLinkedList.get(1) << std::endl;	// 返回 3

	ListNode* head = new ListNode();
	head->val = 5;

	std::cin.get();
	return 0;
}