class Solution {
public:
	ListNode* getKthFromEnd(ListNode* head, int k) {
		if (head == nullptr){
			return nullptr;
		}
		ListNode*slow = head;
		ListNode*fast = head;
		while (k--){
			//防止k比链表长度还大的情况
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
		//循环控制条件为n2
		while (n2 != nullptr){
			n2->next = n1;
			n1 = n2;
			n2 = n3;
			//对n3进行判断防止越界
			if (n3 != nullptr){
				n3 = n3->next;
			}
		}
		//最后返回n1
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
			next = cur->next;//next用来保存当前位置
			cur->next = newhead;//cur拿下来头插
			newhead = cur;//头插完成后，迭代newhead
			cur = next;//头插完成后，把next赋给cur
		}
		return newhead;
	}
};