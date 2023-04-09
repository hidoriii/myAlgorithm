#pragma once
#include <iostream>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	// 203.�Ƴ�����Ԫ�� https://leetcode.cn/problems/remove-linked-list-elements/
	ListNode* removeElements(ListNode* head, int val);
	ListNode* removeElements_2(ListNode* head, int val);
	// 206.��ת���� https://leetcode.cn/problems/reverse-linked-list/
	ListNode* reverseList(ListNode* head);
	ListNode* reverseList_2(ListNode* head);
	ListNode* reverse(ListNode* pre, ListNode* cur);
	ListNode* reverseList_3(ListNode* head);
	// 24. �������������еĽڵ� https://leetcode.cn/problems/swap-nodes-in-pairs/
	ListNode* swapPairs(ListNode* head);
	// 19.ɾ������ĵ�����N���ڵ� https://leetcode.cn/problems/remove-nth-node-from-end-of-list/
	ListNode* removeNthFromEnd(ListNode* head, int n);
	// ������ 02.07.�����ཻ https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB);
	// 142.��������II https://leetcode.cn/problems/linked-list-cycle-ii/
	ListNode* detectCycle(ListNode* head);
};

// 707.������� https://leetcode.cn/problems/design-linked-list/
class MyLinkedList {
public:
	MyLinkedList() : _dummyHead(new ListNode(0)), _size(0) {
	}

	int get(int index) {
		if (index < 0 || index >(_size - 1))
			return -1;
		ListNode* cur = _dummyHead->next;
		while (index--) {
			cur = cur->next;
		}
		return cur->val;
	}

	void addAtHead(int val) {
		ListNode* newNode = new ListNode(val);
		newNode->next = _dummyHead->next;
		_dummyHead->next = newNode;
		_size++;
	}

	void addAtTail(int val) {
		ListNode* newNode = new ListNode(val);
		ListNode* cur = _dummyHead;
		while (cur->next)
			cur = cur->next;
		cur->next = newNode;
		_size++;
	}

	void addAtIndex(int index, int val) {
		if (index > _size) return;
		if (index < 0) index = 0;
		ListNode* newNode = new ListNode(val);
		ListNode* cur = _dummyHead;
		while (index--) {
			cur = cur->next;
		}
		newNode->next = cur->next;
		cur->next = newNode;
		_size++;
	}

	void deleteAtIndex(int index) {
		if (index >= _size || index < 0)
			return;
		ListNode* cur = _dummyHead;
		while (index--)
			cur = cur->next;
		ListNode* tmp = cur->next;
		cur->next = cur->next->next;
		delete tmp;
		_size--;
	}

	void printLinkedList() {
		ListNode* cur = _dummyHead;
		while (cur->next) {
			std::cout << cur->next->val << " ";
			cur = cur->next;
		}
		std::cout << std::endl;
	}

private:
	ListNode* _dummyHead;
	int _size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */