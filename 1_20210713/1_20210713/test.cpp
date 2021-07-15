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
		//如果stack2为空，则将stack1中的所有元素弹出插入到stack2中
		if (st2.empty()){
			while (!st1.empty()){
				st2.push(st1.top());
				st1.pop();
			}
		}
		//如果stack2仍为空，return-1
		if (st2.empty()){
			return -1;
		}
		//否则从stack2中弹出一个元素并返回这个元素
		int tmp = st2.top();
		st2.pop();
		return tmp;
	}
};