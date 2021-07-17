class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		//�����ȿ�����������������һ������Ϊ�գ��Ͳ��úϲ��ˣ�ֱ�ӷ�����һ��
		if (l1 == nullptr){
			return l2;
		}
		if (l2 == nullptr){
			return l1;
		}
		//����ͷ�ڵ�β�ڵ�
		ListNode*head = nullptr;
		ListNode*tail = nullptr;
		//��l1��l2����һ��С����������ʼ��head��tail
		if (l1->val < l2->val){
			head = tail = l1;
			l1 = l1->next;
		}
		else{
			head = tail = l2;
			l2 = l2->next;
		}
		//��ʼ�ϲ���ֻҪ��һ������Ϊ�վͽ���whileѭ��
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
		//��ʣ�µ�����Ľڵ����������β��
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
		//˫ָ��ֱ�������������󳤶�
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
		//�ҳ�����������������k��
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
		//Ѱ���ཻ�ڵ�
		while (longlist){
			if (longlist == shortlist){
				return longlist;
			}
			longlist = longlist->next;
			shortlist = shortlist->next;
		}
		//����whileѭ����û�ҵ���return nullptr;
		return nullptr;
	}
};