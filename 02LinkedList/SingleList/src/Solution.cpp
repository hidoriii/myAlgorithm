#include "Solution.h"

ListNode* Solution::removeElements(ListNode* head, int val)
{
	// ɾ��ͷ���
	while (head && head->val == val) {
		ListNode* tmp = head;
		head = head->next;
		delete tmp;
	}
	// ɾ����ͷ���
	ListNode* cur = head;
	while (cur && cur->next) {
		if (cur->next->val == val) {
			auto tmp = cur->next;
			cur->next = cur->next->next;
			delete tmp;
		}
		else
			cur = cur->next;
	}
	return head;
}

ListNode* Solution::removeElements_2(ListNode* head, int val)
{
	ListNode* dummyHead = new ListNode(0); // ����һ������ͷ���
	dummyHead->next = head; // ������ͷ���ָ��head���������������ɾ������
	ListNode* cur = dummyHead;
	while (cur && cur->next) {
		if (cur->next->val == val) {
			auto tmp = cur->next;
			cur->next = cur->next->next;
			delete tmp;
		}
		else
			cur = cur->next;
	}
	head = dummyHead->next;
	delete dummyHead;
	return head;
}

ListNode* Solution::reverseList(ListNode* head)
{
	ListNode* cur = head;
	ListNode* pre = nullptr;
	ListNode* tmp; // ����cur����һ���ڵ�
	while (cur->next) {
		tmp = cur->next; // ����һ��cur����һ���ڵ㣬��Ϊ������Ҫ�ı�cur->next
		cur->next = pre; // ��ת����
		// ����pre��curָ��
		pre = cur;
		cur = tmp;
	}
	return cur;
}

ListNode* Solution::reverseList_2(ListNode* head)
{
	// ��˫ָ�뷨��ʼ����һ�����߼�
	// ListNode* cur = head;
	// ListNode* pre = NULL;
	return reverse(nullptr, head);
}

ListNode* Solution::reverse(ListNode* pre, ListNode* cur)
{
	if (cur == nullptr) return pre;
	ListNode* tmp = cur->next;
	cur->next = pre;
	// ���Ժ�˫ָ�뷨�Ĵ�����жԱȣ����µݹ��д������ʵ��������������
	// pre = cur;
	// cur = tmp;
	return reverse(pre, tmp);
}

ListNode* Solution::reverseList_3(ListNode* head)
{
	// ��Ե�����ж�
	if (head == nullptr) return nullptr;
	if (head->next == nullptr) return head;
	// �ݹ���ã���ת�ڶ����ڵ㿪ʼ���������
	ListNode* last = reverseList_3(head->next);
	// ��תͷ�ڵ���ڶ����ڵ��ָ��
	head->next->next = head;
	// ��ʱ�� head �ڵ�Ϊβ�ڵ㣬next ��Ҫָ�� NULL
	head->next = nullptr;
	return last;
}

ListNode* Solution::swapPairs(ListNode* head)
{
	ListNode* dummyHead = new ListNode(0);
	dummyHead->next = head; // ��¼��ʱ�ڵ�
	ListNode* cur = dummyHead; // ��¼��ʱ�ڵ�
	while (cur->next && cur->next->next) {
		ListNode* tmp1 = cur->next;
		ListNode* tmp2 = cur->next->next->next;
		cur->next = cur->next->next;
		cur->next->next = tmp1;
		cur->next->next->next = tmp2;
		cur = cur->next->next; // cur�ƶ���λ��׼����һ�ֽ���
	}
	return dummyHead->next;
}

ListNode* Solution::removeNthFromEnd(ListNode* head, int n)
{
	ListNode* dummyHead = new ListNode(0);
	dummyHead->next = head;
	ListNode* fast = dummyHead, *slow = dummyHead;
	while (n-- && fast) {
		fast = fast->next;
	}
	fast = fast->next; // fast����ǰ��һ������Ϊ��Ҫ��slowָ��ɾ���ڵ����һ���ڵ�
	while (fast) {
		fast = fast->next;
		slow = slow->next;
	}
	ListNode* tmp = slow->next;
	slow->next = slow->next->next;
	delete tmp; // �ͷ�Ҫɾ�������ڴ�

	return dummyHead->next;
}

ListNode* Solution::getIntersectionNode(ListNode* headA, ListNode* headB)
{
	if (headA == nullptr || headB == nullptr)
		return nullptr;
	ListNode* curA = headA, * curB = headB;
	int lenA = 0, lenB = 0;
	while (curA) {
		lenA++;
		curA = curA->next;
	}
	while (curB) {
		lenB++;
		curB = curB->next;
	}
	curA = headA;
	curB = headB;
	// ��curAΪ������ͷ��lenAΪ�䳤��
	if (lenA < lenB) {
		std::swap(lenA, lenB);
		std::swap(curA, curB);
	}
	// ��������ĳ��Ȳ�
	int gap = lenA - lenB;
	// ��curA��curB��ͬһ����ϣ�ĩβλ�ö��룩
	while (gap--) {
		curA = curA->next;
	}
	// ����curA �� curB��������ͬ��ֱ�ӷ���
	while (curA) {
		if (curA == curB) {
			return curA;
		}
		curA = curA->next;
		curB = curB->next;
	}
	return nullptr;
}

ListNode* Solution::detectCycle(ListNode* head)
{
	ListNode* fast = head, * slow = head;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		// ����ָ����������ʱ��head �� �����㣬ͬʱ����ֱ������
		if (fast == slow) {
			ListNode* index1 = fast;
			ListNode* index2 = head;
			while (index1 != index2) {
				index1 = index1->next;
				index2 = index2->next;
			}
			return index1; // ���ػ������
		}
	}
	return nullptr;
}
