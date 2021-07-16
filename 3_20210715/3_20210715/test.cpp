class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		//�ݹ���ֹ����
		if (root == nullptr || root == p || root == q){
			return root;
		}
		//��ʼ�ݹ�
		TreeNode*left = lowestCommonAncestor(root->left, p, q);
		TreeNode*right = lowestCommonAncestor(root->right, p, q);
		if (left == nullptr){
			return right;
		}
		else if (right == nullptr){
			return left;
		}
		else{
			return root;
		}
	}
};



class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		//�ݹ���ֹ����
		if (root == nullptr || root == p || root == q){
			return root;
		}
		//��ʼ�ݹ�
		TreeNode*left = lowestCommonAncestor(root->left, p, q);
		TreeNode*right = lowestCommonAncestor(root->right, p, q);
		//pq����root������������,renturn nullptr
		if (left == nullptr&&right == nullptr){
			return nullptr;
		}
		//pq��������������,return right
		if (left == nullptr){
			return right;
		}
		//pq�������������У�return left
		if (right == nullptr){
			return left;
		}
		//pqһ��һ��
		return root;
	}
};