class Solution {
public:
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		vector<int> vec(k, 0);
		if (k == 0) { // �ų� 0 �����
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
		//���K==0,return v;
		if (k == 0){
			return v;
		}
		//��q�в���arr���±��0��k��k����
		priority_queue<int>q;
		for (int i = 0; i < k; i++){
			q.push(arr[i]);
		}
		//i��k��ʼ����һ��Ѷ�Ԫ�رȽϣ�����ȶѶ�Ԫ��С���򽻻�
		for (int i = k; i<(int)arr.size(); i++){
			if (q.top()>arr[i]){
				q.pop();
				q.push(arr[i]);
			}
		}
		//��q��ֵ����v
		for (int i = 0; i < k; i++){
			v[i] = q.top();
			q.pop();
		}
		return v;
	}
};