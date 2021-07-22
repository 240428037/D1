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
		//�ݹ���ֹ����
		//AB��Ϊ�ա�
		if (A == nullptr&&B == nullptr){
			return true;
		}
		//A��Ϊ��BΪ�ա�
		if (A != nullptr&&B == nullptr){
			return true;
		}
		//AΪ��B��Ϊ�ա�
		if (A == nullptr&&B != nullptr){
			return false;
		}
		//AB�ڵ��ֵ��ͬ��
		if (A->val != B->val){
			return false;
		}
		//AB�ڵ��ֵ��ͬ�����ݹ�
		//����Ϊ&&
		return issametree(A->left, B->left) && issametree(A->right, B->right);
	}
	bool isSubStructure(TreeNode* A, TreeNode* B) {
		//A��B��һ��Ϊ�������涨������������һ�������ӽṹ
		if (A == nullptr || B == nullptr){
			return false;
		}
		//A��B��ͬ
		if (A->val == B->val&&issametree(A, B)){
			return true;
		}
		//�ݹ�A��������������������һ��return true���У�������||
		return isSubStructure(A->left, B) || isSubStructure(A->right, B);
	}
};