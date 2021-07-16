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
	//因为使用stack-LIFO-所以遍历的顺序依旧为左中右-实际出栈顺序就为右中左
	//又由于二叉搜索树的性质-输出的序列为一个降序序列
	//当i==k时root->val即为第K大的值
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