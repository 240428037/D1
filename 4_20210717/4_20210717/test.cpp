class Solution {
public:
	ListNode* getKthFromEnd(ListNode* head, int k) {
		if (head == nullptr){
			return nullptr;
		}
		ListNode*slow = head;
		ListNode*fast = head;
		while (k--){
			//��ֹk�������Ȼ�������
			if (fast == nullptr){
				return nullptr;
			}
			fast = fast->next;
		}
		while (fast != nullptr){
			fast = fast->next;
			slow = slow->next;
		}
		return slow;
	}
};



class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == nullptr){
			return nullptr;
		}
		ListNode*n1 = nullptr;
		ListNode*n2 = head;
		ListNode*n3 = head->next;
		//ѭ����������Ϊn2
		while (n2 != nullptr){
			n2->next = n1;
			n1 = n2;
			n2 = n3;
			//��n3�����жϷ�ֹԽ��
			if (n3 != nullptr){
				n3 = n3->next;
			}
		}
		//��󷵻�n1
		return n1;
	}
};




class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == nullptr){
			return nullptr;
		}
		ListNode*cur = head;
		ListNode*next = cur->next;
		ListNode*newhead = nullptr;
		while (cur != nullptr){
			next = cur->next;//next�������浱ǰλ��
			cur->next = newhead;//cur������ͷ��
			newhead = cur;//ͷ����ɺ󣬵���newhead
			cur = next;//ͷ����ɺ󣬰�next����cur
		}
		return newhead;
	}
};