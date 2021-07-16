class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		//递归终止条件
		if (root == nullptr || root == p || root == q){
			return root;
		}
		//开始递归
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
		//递归终止条件
		if (root == nullptr || root == p || root == q){
			return root;
		}
		//开始递归
		TreeNode*left = lowestCommonAncestor(root->left, p, q);
		TreeNode*right = lowestCommonAncestor(root->right, p, q);
		//pq不在root的左右子树中,renturn nullptr
		if (left == nullptr&&right == nullptr){
			return nullptr;
		}
		//pq都不在左子树中,return right
		if (left == nullptr){
			return right;
		}
		//pq都不在右子树中，return left
		if (right == nullptr){
			return left;
		}
		//pq一左一右
		return root;
	}
};