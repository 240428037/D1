class Solution {
public:
	int maxDepth(TreeNode* root) {
		//递归终止条件root==nullptr,return 0;
		if (root == nullptr){
			return 0;
		}
		int leftdepth = maxDepth(root->left);
		int rightdepth = maxDepth(root->right);
		return max(leftdepth, rightdepth) + 1;
	}
};



class Solution {
public:
	int maxdepth(TreeNode*root){
		//递归终止条件
		if (root == nullptr){
			return 0;
		}
		int leftdepth = maxdepth(root->left);
		int rightdepth = maxdepth(root->right);
		return max(leftdepth, rightdepth) + 1;
	}
	bool isBalanced(TreeNode* root) {
		//一上来先考虑特殊情况-空树为平衡二叉树
		if (root == nullptr){
			return true;
		}
		//然后再分治递归
		int leftdepth = maxdepth(root->left);
		int rightdepth = maxdepth(root->right);
		//递归的终止条件为如果3个条件有一个条件不满足就return false跳出递归
		//1.左右子树高度差不差过1
		//2.左子树为平衡二叉树
		//3.右子树为平衡二叉树
		//之前求高度调用的是maxdepth，递归需要调用自身isBalanced
		return abs(leftdepth - rightdepth) <= 1 && isBalanced(root->left) && isBalanced(root->right);
	}
};