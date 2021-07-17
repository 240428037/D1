class Solution {
public:
	int maxDepth(TreeNode* root) {
		//�ݹ���ֹ����root==nullptr,return 0;
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
		//�ݹ���ֹ����
		if (root == nullptr){
			return 0;
		}
		int leftdepth = maxdepth(root->left);
		int rightdepth = maxdepth(root->right);
		return max(leftdepth, rightdepth) + 1;
	}
	bool isBalanced(TreeNode* root) {
		//һ�����ȿ����������-����Ϊƽ�������
		if (root == nullptr){
			return true;
		}
		//Ȼ���ٷ��εݹ�
		int leftdepth = maxdepth(root->left);
		int rightdepth = maxdepth(root->right);
		//�ݹ����ֹ����Ϊ���3��������һ�������������return false�����ݹ�
		//1.���������߶Ȳ���1
		//2.������Ϊƽ�������
		//3.������Ϊƽ�������
		//֮ǰ��߶ȵ��õ���maxdepth���ݹ���Ҫ��������isBalanced
		return abs(leftdepth - rightdepth) <= 1 && isBalanced(root->left) && isBalanced(root->right);
	}
};