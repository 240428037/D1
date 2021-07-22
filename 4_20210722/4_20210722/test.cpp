class Solution {
public:
	bool postOrder(vector<int>& postorder, int start, int end) {
		if (start >= end) return true;
		int p = start; // ����ָ�룬��ʼΪ���������
		int rootValue = postorder[end]; // ���浱ǰ���ĸ��ڵ��ֵ
		while (rootValue > postorder[p]) p++;
		int lfetTreeEnd = p - 1, rightTreeStart = p;
		while (rootValue < postorder[p]) p++;
		return p == end && postOrder(postorder, start, lfetTreeEnd)
			&& postOrder(postorder, rightTreeStart, end - 1);
	}
	bool verifyPostorder(vector<int>& postorder) {
		if (postorder.empty()) return true; // �п�
		return postOrder(postorder, 0, postorder.size() - 1);
	}
};



class Solution {
public:
	bool postorder1(vector<int>&postorder, int left, int right){
		//�ݹ���ֹ����
		if (left >= right){
			return true;
		}
		int i = left;//����ָ�룬��ʼΪ���������
		int root = postorder[right];//�洢��ǰ���ڵ�
		//Ѱ������������
		while (root > postorder[i]){
			i++;
		}
		int leftend = i - 1;//������[left,left1]
		int rightstart = i;//������[right,right1]
		while (root < postorder[i]){
			i++;
		}
		//right-1ȥ����ǰ���ڵ㣡��
		return i == right&&postorder1(postorder, left, leftend) && postorder1(postorder, rightstart, right - 1);

	}
	bool verifyPostorder(vector<int>& postorder) {
		if (postorder.empty()){
			return true;
		}
		return postorder1(postorder, 0, postorder.size() - 1);
	}
};


class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		queue<TreeNode*>q;
		vector<vector<int>>vv;
		if (root){
			q.push(root);
		}
		while (!q.empty()){
			vector<int>v;
			int levelsize = q.size();
			//�����ڿ�ʼforѭ��֮ǰ��q.size()��ֵ��levelszie
			//��Ϊһ����ʼforѭ��q.size()��ֵ�ͻᷢ���仯
			for (int i = 0; i < levelsize; i++){
				TreeNode*front = q.front();
				q.pop();
				v.push_back(front->val);
				if (front->left){
					q.push(front->left);
				}
				if (front->right){
					q.push(front->right);
				}
			}
			vv.push_back(v);
		}
		return vv;
	}
};


class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		queue<TreeNode*>q;
		vector<vector<int>>vv;
		if (root != nullptr){
			q.push(root);
		}
		while (!q.empty()){
			vector<int>v;
			int levelsize = q.size();
			for (int i = 0; i < levelsize; i++){
				TreeNode*front = q.front();
				q.pop();
				v.push_back(front->val);
				if (front->left){
					q.push(front->left);
				}
				if (front->right){
					q.push(front->right);
				}
			}
			vv.push_back(v);
		}
		return vv;
	}
};