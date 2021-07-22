class Solution {
public:
	vector<int> levelOrder(TreeNode* root) {
		if (!root) return{}; // �п�
		vector<int> ret; // �洢�������Ľڵ�
		queue<TreeNode*> q; // ����ģ���α���
		q.push(root); // ���ڵ��������
		while (!q.empty()) {
			/*
			*  ÿ�����whileѭ����ʼ
			*  �����д洢�Ľڵ㶼λ�ڶ�������ͬһ��
			*  cnt��¼��ʱ���еĳ��ȣ�Ҳ���Ƕ�����ĳһ��Ŀ��
			*/
			int cnt = q.size();
			while (cnt--) {
				/*
				*  �ڲ�whileѭ���������д��ڶ�����ͬһ������нڵ����
				*  ������һ������нڵ���������
				*/
				TreeNode* node = q.front();
				ret.push_back(node->val);
				q.pop();
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
		}
		// ���ؼ���
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
		int label = 0; // ��ǵ�ǰ���
		while (!q.empty()) {
			int cnt = q.size();
			label++; // ���whileÿѭ��һ�Σ���ξͼ�һ
			while (cnt--) {
				TreeNode* node = q.front();
				in.push_back(node->val);
				q.pop();
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
			/*
			*  �жϲ���Ƿ�Ϊ����
			*  �����Ļ�Ҫ���ò�ڵ㵹���ڴ���out��
			*  ��������Ļ�����������������ң�ż������ҵ���
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
		int level = 0;//��ǲ��
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
			//ż������Ҫ��ת������Ԫ��
			if (level % 2 == 0){
				reverse(v.begin(), v.end());
			}
			vv.push_back(v);
		}
		return vv;
	}
};