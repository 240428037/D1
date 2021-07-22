class Solution {
public:
	vector<int> levelOrder(TreeNode* root) {
		if (!root) return{}; // 判空
		vector<int> ret; // 存储二叉树的节点
		queue<TreeNode*> q; // 队列模拟层次遍历
		q.push(root); // 根节点首先入队
		while (!q.empty()) {
			/*
			*  每次外层while循环开始
			*  队列中存储的节点都位于二叉树的同一层
			*  cnt记录此时队列的长度，也就是二叉树某一层的宽度
			*/
			int cnt = q.size();
			while (cnt--) {
				/*
				*  内层while循环将队列中处在二叉树同一层的所有节点出队
				*  并将下一层的所有节点从左到右入队
				*/
				TreeNode* node = q.front();
				ret.push_back(node->val);
				q.pop();
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
		}
		// 返回即可
		return ret;
	}
};




class Solution {
public:
	vector<int> levelOrder(TreeNode* root) {
		if (root == nullptr){
			return{};
		}
		queue<TreeNode*>q;
		vector<int>v;
		q.push(root);
		while (!q.empty()){
			int size = q.size();
			while (size--){
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
		}
		return v;
	}
};


class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (!root) return{};
		vector<int> in;
		vector<vector<int>> out;
		queue<TreeNode*> q;
		q.push(root);
		int label = 0; // 标记当前层次
		while (!q.empty()) {
			int cnt = q.size();
			label++; // 外层while每循环一次，层次就加一
			while (cnt--) {
				TreeNode* node = q.front();
				in.push_back(node->val);
				q.pop();
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
			/*
			*  判断层次是否为奇数
			*  奇数的话要将该层节点倒序，在存入out中
			*  这样输出的话就满足奇数层从左到右，偶数层从右到左
			*/
			if (!(label & 1)) reverse(in.begin(), in.end());
			out.push_back(in);
			vector<int>().swap(in);
		}
		return out;
	}
};



class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (root == nullptr){
			return{};
		}
		queue<TreeNode*>q;
		vector<vector<int>>vv;
		q.push(root);
		int level = 0;//标记层次
		while (!q.empty()){
			vector<int>v;
			level++;
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
			//偶数层需要翻转数组内元素
			if (level % 2 == 0){
				reverse(v.begin(), v.end());
			}
			vv.push_back(v);
		}
		return vv;
	}
};