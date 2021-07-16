class Solution {
public:
	int i = 0;
	stack<TreeNode*>st;
	void Traveltree(TreeNode*root){
		if (root == nullptr){
			return;
		}
		Traveltree(root->left);
		st.push(root);
		Traveltree(root->right);
	}
	int kthLargest(TreeNode* root, int k) {
		Traveltree(root);
		while (!st.empty()){
			root = st.top();
			st.pop();
			i++;
			if (i == k){
				return root->val;
			}
		}
		return 0;
	}
};



class Solution {
public:
	int i = 0;
	stack<TreeNode*>st;
	//��Ϊʹ��stack-LIFO-���Ա�����˳������Ϊ������-ʵ�ʳ�ջ˳���Ϊ������
	//�����ڶ���������������-���������Ϊһ����������
	//��i==kʱroot->val��Ϊ��K���ֵ
	void Traveltree(TreeNode*root){
		if (root == nullptr){
			return;
		}
		Traveltree(root->left);
		st.push(root);
		Traveltree(root->right);
	}
	int kthLargest(TreeNode* root, int k) {
		Traveltree(root);
		while (!st.empty()){
			root = st.top();
			st.pop();
			i++;
			if (i == k){
				return root->val;
			}
		}
		return 0;
	}
};