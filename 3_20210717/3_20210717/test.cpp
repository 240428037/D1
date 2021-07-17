class Solution {
public:
	TreeNode* mirrorTree(TreeNode* root) {
		//递归终止条件,当root==nullptr说明已经递归到叶子节点了，递归结束
		if (root == nullptr){
			return nullptr;
		}
		swap(root->left, root->right);
		mirrorTree(root->left);
		mirrorTree(root->right);
		return root;
	}
};


class Solution {
public:
	bool compare(TreeNode* left, TreeNode* right) {
		if (left == NULL && right == NULL) return true; // 若左右节点都为空，则到目前为止是对称的，返回真
		else if (left == NULL || right == NULL) return false; // 左右节点有一个不为空，都不对称，返回假
		else if (left->val != right->val) return false; // 左右节点都不空，但是值不等，也不对称，返回假
		// 注意：上面判断用的else if，最后剩下的情况就是左右节点都不空，且值相等
		// 然后递归判断子树的
		// 外层是左节点的左子树和右节点的右子树判断对称
		bool outside = compare(left->left, right->right);
		// 内层是左节点的右子树和右节点的左子树判断对称
		bool inside = compare(left->right, right->left);
		// 若内外层都对称，则当前二叉树对称
		// 反之则不对称
		bool isSame = outside && inside;
		return isSame;
	}
	bool isSymmetric(TreeNode* root) {
		if (!root) return true; // 判空，空既是真
		return compare(root->left, root->right);
	}
}



class Solution {
public:
	bool compare(TreeNode* left, TreeNode* right) {
		// 首先排除空节点的情况
		if (left == NULL && right != NULL) return false;
		else if (left != NULL && right == NULL) return false;
		else if (left == NULL && right == NULL) return true;
		// 排除了空节点，再排除数值不相同的情况
		else if (left->val != right->val) return false;

		// 此时就是：左右节点都不为空，且数值相同的情况
		// 此时才做递归，做下一层的判断
		bool outside = compare(left->left, right->right);   // 左子树：左、 右子树：右
		bool inside = compare(left->right, right->left);    // 左子树：右、 右子树：左
		bool isSame = outside && inside;                    // 左子树：中、 右子树：中 （逻辑处理）
		return isSame;

	}
	bool isSymmetric(TreeNode* root) {
		if (root == NULL) return true;
		return compare(root->left, root->right);
	}
};



class Solution {
public:
	bool compare(TreeNode*left, TreeNode*right){
		//左右子树都为空return true;
		if (left == nullptr&&right == nullptr){
			return true;
			//左右子树其中一个为空return false;
		}
		else if (left == nullptr || right == nullptr){
			return false;
			//左右子树都不为空但是值不相等return false;
		}
		else if (left->val != right->val){
			return false;
		}
		//此时走到这，左右子树都不为空且值相等，可以开始递归
		//先判断外侧
		bool outside = compare(left->left, right->right);
		bool inside = compare(left->right, right->left);
		bool issame = outside&&inside;
		return issame;

	}
	bool isSymmetric(TreeNode* root) {
		//上来先考虑特殊情况，root==nullptr直接return true;
		if (root == nullptr){
			return true;
		}
		//在子函数compare里递归解决
		return compare(root->left, root->right);
	}
};


class Solution {
public:
	bool compare(TreeNode*left, TreeNode*right){
		//左右子树都为空return true;
		if (left == nullptr&&right == nullptr){
			return true;
			//左右子树其中一个为空return false;
		}
		else if (left == nullptr || right == nullptr){
			return false;
			//左右子树都不为空但是值不相等return false;
		}
		else if (left->val != right->val){
			return false;
		}
		//此时走到这，左右子树都不为空且值相等，可以开始递归
		//递归判断外侧
		bool outside = compare(left->left, right->right);
		//递归判断内侧
		bool inside = compare(left->right, right->left);
		bool issame = outside&&inside;
		return issame;

	}
	bool isSymmetric(TreeNode* root) {
		//上来先考虑特殊情况，root==nullptr直接return true;
		if (root == nullptr){
			return true;
		}
		//在子函数compare里递归解决
		return compare(root->left, root->right);
	}
};