class Solution {
public:
	bool issametree(TreeNode*p, TreeNode*q){
		if (p == nullptr&&q == nullptr){
			return true;
		}
		if (p == nullptr || q == nullptr){
			return false;
		}
		if (p->val != q->val){
			return false;
		}
		return issametree(p->left, q->left) && issametree(p->right, q->right);
	}
	bool isSubtree(TreeNode* root, TreeNode* subRoot) {
		if (root == nullptr){
			return false;
		}
		if (issametree(root, subRoot)){
			return true;
		}
		return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
	}
};



class Solution {
public:
	bool isSameTree(TreeNode* A, TreeNode* B) {
		if (!A &&  B)          return false;
		if (A && !B)          return true;
		if (!A && !B)          return true;
		if (A->val != B->val)  return false;
		return isSameTree(A->left, B->left) && isSameTree(A->right, B->right);
	}

	bool isSubStructure(TreeNode* A, TreeNode* B) {
		if (!A || !B) return false;
		if (A->val == B->val && isSameTree(A, B)){ return true; }
		return isSubStructure(A->left, B) || isSubStructure(A->right, B);
	}
};



class Solution {
public:
	bool issametree(TreeNode*A, TreeNode*B){
		//递归终止条件
		//AB都为空√
		if (A == nullptr&&B == nullptr){
			return true;
		}
		//A不为空B为空√
		if (A != nullptr&&B == nullptr){
			return true;
		}
		//A为空B不为空×
		if (A == nullptr&&B != nullptr){
			return false;
		}
		//AB节点的值不同×
		if (A->val != B->val){
			return false;
		}
		//AB节点的值相同继续递归
		//条件为&&
		return issametree(A->left, B->left) && issametree(A->right, B->right);
	}
	bool isSubStructure(TreeNode* A, TreeNode* B) {
		//A和B有一棵为空树，规定空树不是任意一棵树的子结构
		if (A == nullptr || B == nullptr){
			return false;
		}
		//A和B相同
		if (A->val == B->val&&issametree(A, B)){
			return true;
		}
		//递归A的左子树和右子树，有一棵return true就行，所以是||
		return isSubStructure(A->left, B) || isSubStructure(A->right, B);
	}
};