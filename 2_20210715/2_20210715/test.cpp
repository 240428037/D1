class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		//迭代
		while (root){
			if (p->val<root->val&&q->val<root->val){
				root = root->left;//root迭代
			}
			else if (p->val>root->val&&q->val>root->val){
				root = root->right;//root迭代
			}
			else{
				return root;//一左一右/p==root/q==root，最近公共祖先就是root
			}
		}
		//都没找到return nullptr;
		return nullptr;
	}
};



class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		// 递归返回条件：
		// 1、root为空节点
		// 2、root与q或p存在相等的情况
		if (root == NULL) return NULL;
		if (root->val == p->val || root->val == q->val) return root;
		if (root->val < p->val && root->val < q->val) {
			// q和p都大于当前根节点
			// 去右子树中寻找
			return lowestCommonAncestor(root->right, p, q);
		}
		else if (root->val > p->val && root->val > q->val) {
			// q和p都小于当前根节点
			// 去左子树中寻找
			return lowestCommonAncestor(root->left, p, q);
		}
		else {
			// 否则q和p在当前根节点的两边
			// 则当前根节点即为最近公共祖先
			return root;
		}
	}
};