class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		//上来先考虑特殊情况，如果有一个链表为空，就不用合并了，直接返回另一个
		if (l1 == nullptr){
			return l2;
		}
		if (l2 == nullptr){
			return l1;
		}
		//定义头节点尾节点
		ListNode*head = nullptr;
		ListNode*tail = nullptr;
		//从l1和l2中拿一个小的下来，初始化head和tail
		if (l1->val < l2->val){
			head = tail = l1;
			l1 = l1->next;
		}
		else{
			head = tail = l2;
			l2 = l2->next;
		}
		//开始合并，只要有一个链表为空就结束while循环
		while (l1&&l2){
			if (l1->val < l2->val){
				tail->next = l1;
				l1 = l1->next;
				tail = tail->next;
			}
			else{
				tail->next = l2;
				l2 = l2->next;
				tail = tail->next;
			}
		}
		//把剩下的链表的节点接着拿下来尾插
		while (l1){
			tail->next = l1;
			l1 = l1->next;
			tail = tail->next;
		}
		while (l2){
			tail->next = l2;
			l2 = l2->next;
			tail = tail->next;
		}
		return head;
	}
};



class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		//双指针分别遍历两个链表求长度
		ListNode*curA = headA;
		ListNode*curB = headB;
		int la = 0, lb = 0;
		while (curA){
			la++;
			curA = curA->next;
		}
		while (curB){
			lb++;
			curB = curB->next;
		}
		//找出长的链表，让它先走k步
		ListNode*longlist = headA;
		ListNode*shortlist = headB;
		if (la < lb){
			longlist = headB;
			shortlist = headA;
		}
		int k = abs(la - lb);
		while (k--){
			longlist = longlist->next;
		}
		//寻找相交节点
		while (longlist){
			if (longlist == shortlist){
				return longlist;
			}
			longlist = longlist->next;
			shortlist = shortlist->next;
		}
		//出了while循环还没找到就return nullptr;
		return nullptr;
	}
};