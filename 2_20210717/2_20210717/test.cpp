class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (head == nullptr || head->next == nullptr){
			return false;
		}
		ListNode*slow = head;
		ListNode*fast = head;
		while (fast != nullptr&&fast->next != nullptr){
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast){
				return true;
			}
		}
		//如果出了while循环快慢指针还没有相遇return false;
		return false;
	}
};


class Solution {
public:
	bool hasCycle(ListNode *head) {
		//一上来先考虑特殊情况
		if (head == nullptr || head->next == nullptr){
			return false;
		}
		//然后再用快慢指针去判断
		ListNode*slow = head;
		ListNode*fast = head;
		while (fast != nullptr&&fast->next != nullptr){
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast){
				return true;
			}
		}
		//如果出了while循环快慢指针还没有相遇return false;
		return false;
	}
};



class Solution {
public:
	ListNode* deleteNode(ListNode* head, int val) {
		//上来先考虑特殊情况，链表为空,直接return nullptr
		if (head == nullptr){
			return nullptr;
		}
		//双指针-前后指针遍历链表删除val
		ListNode*prev = nullptr;
		ListNode*cur = head;
		while (cur != nullptr){
			//双指针继续向后迭代遍历
			if (cur->val != val){
				prev = cur;
				cur = cur->next;
			}
			//删节点
			else{
				//删除的节点是头节点，对头节点重新赋值
				if (cur == head){
					head = cur->next;
					cur = head;
				}
				//删除的节点不是头节点
				else{
					prev->next = cur->next;
					cur = prev->next;
				}
			}
		}
		return head;
	}
};