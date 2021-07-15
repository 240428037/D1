class MinStack {
public:
	stack<int>st1;//数据栈
	stack<int>st2;//辅助栈
	MinStack() {
	}
	void push(int x) {
		st1.push(x);
		if (st2.empty() || x <= st2.top()){
			st2.push(x);
		}
	}
	//顺序不能反
	void pop() {
		if (st2.top() == st1.top()){
			st2.pop();
		}
		st1.pop();//先比较再pop;不然st1都pop了，st2和谁比去
	}
	int top() {
		return st1.top();
	}
	int min() {
		return st2.top();
	}
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack* obj = new MinStack();
* obj->push(x);
* obj->pop();
* int param_3 = obj->top();
* int param_4 = obj->min();
*/