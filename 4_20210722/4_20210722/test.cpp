class Solution {
public:
	bool postOrder(vector<int>& postorder, int start, int end) {
		if (start >= end) return true;
		int p = start; // 工作指针，初始为数组最左边
		int rootValue = postorder[end]; // 储存当前树的根节点的值
		while (rootValue > postorder[p]) p++;
		int lfetTreeEnd = p - 1, rightTreeStart = p;
		while (rootValue < postorder[p]) p++;
		return p == end && postOrder(postorder, start, lfetTreeEnd)
			&& postOrder(postorder, rightTreeStart, end - 1);
	}
	bool verifyPostorder(vector<int>& postorder) {
		if (postorder.empty()) return true; // 判空
		return postOrder(postorder, 0, postorder.size() - 1);
	}
};



class Solution {
public:
	bool postorder1(vector<int>&postorder, int left, int right){
		//递归终止条件
		if (left >= right){
			return true;
		}
		int i = left;//工作指针，初始为数组最左边
		int root = postorder[right];//存储当前根节点
		//寻找左子树区间
		while (root > postorder[i]){
			i++;
		}
		int leftend = i - 1;//左子树[left,left1]
		int rightstart = i;//右子树[right,right1]
		while (root < postorder[i]){
			i++;
		}
		//right-1去掉当前根节点！！
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
			//必须在开始for循环之前把q.size()的值给levelszie
			//因为一旦开始for循环q.size()的值就会发生变化
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