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
		//�������whileѭ������ָ�뻹û������return false;
		return false;
	}
};


class Solution {
public:
	bool hasCycle(ListNode *head) {
		//һ�����ȿ����������
		if (head == nullptr || head->next == nullptr){
			return false;
		}
		//Ȼ�����ÿ���ָ��ȥ�ж�
		ListNode*slow = head;
		ListNode*fast = head;
		while (fast != nullptr&&fast->next != nullptr){
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast){
				return true;
			}
		}
		//�������whileѭ������ָ�뻹û������return false;
		return false;
	}
};



class Solution {
public:
	ListNode* deleteNode(ListNode* head, int val) {
		//�����ȿ����������������Ϊ��,ֱ��return nullptr
		if (head == nullptr){
			return nullptr;
		}
		//˫ָ��-ǰ��ָ���������ɾ��val
		ListNode*prev = nullptr;
		ListNode*cur = head;
		while (cur != nullptr){
			//˫ָ���������������
			if (cur->val != val){
				prev = cur;
				cur = cur->next;
			}
			//ɾ�ڵ�
			else{
				//ɾ���Ľڵ���ͷ�ڵ㣬��ͷ�ڵ����¸�ֵ
				if (cur == head){
					head = cur->next;
					cur = head;
				}
				//ɾ���Ľڵ㲻��ͷ�ڵ�
				else{
					prev->next = cur->next;
					cur = prev->next;
				}
			}
		}
		return head;
	}
};