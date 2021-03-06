class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		stack<int>st;
		int i = 0;
		for (auto&s : pushed){
			st.push(s);
			while (!st.empty() && st.top() == popped[i]){
				st.pop();
				i++;
			}
		}
		return st.empty();
	}
};