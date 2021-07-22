class Solution {
public:
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		vector<int> vec(k, 0);
		if (k == 0) { // 排除 0 的情况
			return vec;
		}
		priority_queue<int> Q;
		for (int i = 0; i < k; ++i) {
			Q.push(arr[i]);
		}
		for (int i = k; i < (int)arr.size(); ++i) {
			if (Q.top() > arr[i]) {
				Q.pop();
				Q.push(arr[i]);
			}
		}
		for (int i = 0; i < k; ++i) {
			vec[i] = Q.top();
			Q.pop();
		}
		return vec;
	}
};



class Solution {
public:
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		vector<int>v(k, 0);
		//如果K==0,return v;
		if (k == 0){
			return v;
		}
		//向q中插入arr中下标从0到k的k个数
		priority_queue<int>q;
		for (int i = 0; i < k; i++){
			q.push(arr[i]);
		}
		//i从k开始，逐一与堆顶元素比较，如果比堆顶元素小，则交换
		for (int i = k; i<(int)arr.size(); i++){
			if (q.top()>arr[i]){
				q.pop();
				q.push(arr[i]);
			}
		}
		//把q的值赋给v
		for (int i = 0; i < k; i++){
			v[i] = q.top();
			q.pop();
		}
		return v;
	}
};