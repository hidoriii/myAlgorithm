#include "Solution.h"

ListNode* Solution::removeElements(ListNode* head, int val)
{
	// 删除头结点
	while (head && head->val == val) {
		ListNode* tmp = head;
		head = head->next;
		delete tmp;
	}
	// 删除非头结点
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
	ListNode* dummyHead = new ListNode(0); // 设置一个虚拟头结点
	dummyHead->next = head; // 将虚拟头结点指向head，这样方面后面做删除操作
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
	ListNode* tmp; // 保存cur的下一个节点
	while (cur->next) {
		tmp = cur->next; // 保存一下cur的下一个节点，因为接下来要改变cur->next
		cur->next = pre; // 翻转操作
		// 更新pre和cur指针
		pre = cur;
		cur = tmp;
	}
	return cur;
}

ListNode* Solution::reverseList_2(ListNode* head)
{
	// 和双指针法初始化是一样的逻辑
	// ListNode* cur = head;
	// ListNode* pre = NULL;
	return reverse(nullptr, head);
}

ListNode* Solution::reverse(ListNode* pre, ListNode* cur)
{
	if (cur == nullptr) return pre;
	ListNode* tmp = cur->next;
	cur->next = pre;
	// 可以和双指针法的代码进行对比，如下递归的写法，其实就是做了这两步
	// pre = cur;
	// cur = tmp;
	return reverse(pre, tmp);
}

ListNode* Solution::reverseList_3(ListNode* head)
{
	// 边缘条件判断
	if (head == nullptr) return nullptr;
	if (head->next == nullptr) return head;
	// 递归调用，翻转第二个节点开始往后的链表
	ListNode* last = reverseList_3(head->next);
	// 翻转头节点与第二个节点的指向
	head->next->next = head;
	// 此时的 head 节点为尾节点，next 需要指向 NULL
	head->next = nullptr;
	return last;
}

ListNode* Solution::swapPairs(ListNode* head)
{
	ListNode* dummyHead = new ListNode(0);
	dummyHead->next = head; // 记录临时节点
	ListNode* cur = dummyHead; // 记录临时节点
	while (cur->next && cur->next->next) {
		ListNode* tmp1 = cur->next;
		ListNode* tmp2 = cur->next->next->next;
		cur->next = cur->next->next;
		cur->next->next = tmp1;
		cur->next->next->next = tmp2;
		cur = cur->next->next; // cur移动两位，准备下一轮交换
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
	fast = fast->next; // fast再提前走一步，因为需要让slow指向删除节点的上一个节点
	while (fast) {
		fast = fast->next;
		slow = slow->next;
	}
	ListNode* tmp = slow->next;
	slow->next = slow->next->next;
	delete tmp; // 释放要删除结点的内存

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
	// 让curA为最长链表的头，lenA为其长度
	if (lenA < lenB) {
		std::swap(lenA, lenB);
		std::swap(curA, curB);
	}
	// 求两链表的长度差
	int gap = lenA - lenB;
	// 让curA和curB在同一起点上（末尾位置对齐）
	while (gap--) {
		curA = curA->next;
	}
	// 遍历curA 和 curB，遇到相同则直接返回
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
		// 快慢指针相遇，此时从head 和 相遇点，同时查找直至相遇
		if (fast == slow) {
			ListNode* index1 = fast;
			ListNode* index2 = head;
			while (index1 != index2) {
				index1 = index1->next;
				index2 = index2->next;
			}
			return index1; // 返回环的入口
		}
	}
	return nullptr;
}
