class Solution {
public:
	vector<int> reversePrint(ListNode* head) {
		stack<int>st;
		vector<int>v;
		while (head != nullptr){
			st.push(head->val);
			head = head->next;
		}
		while (!st.empty()){
			v.push_back(st.top());
			st.pop();
		}
		return v;
	}
};




class CQueue {
public:
	stack<int>st1;
	stack<int>st2;
	CQueue() {
	}
	void appendTail(int value) {
		st1.push(value);
	}
	int deleteHead() {
		//���stack2Ϊ�գ���stack1�е�����Ԫ�ص������뵽stack2��
		if (st2.empty()){
			while (!st1.empty()){
				st2.push(st1.top());
				st1.pop();
			}
		}
		//���stack2��Ϊ�գ�return-1
		if (st2.empty()){
			return -1;
		}
		//�����stack2�е���һ��Ԫ�ز��������Ԫ��
		int tmp = st2.top();
		st2.pop();
		return tmp;
	}
};