class Solution {
public:
	TreeNode* mirrorTree(TreeNode* root) {
		//�ݹ���ֹ����,��root==nullptr˵���Ѿ��ݹ鵽Ҷ�ӽڵ��ˣ��ݹ����
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
		if (left == NULL && right == NULL) return true; // �����ҽڵ㶼Ϊ�գ���ĿǰΪֹ�ǶԳƵģ�������
		else if (left == NULL || right == NULL) return false; // ���ҽڵ���һ����Ϊ�գ������Գƣ����ؼ�
		else if (left->val != right->val) return false; // ���ҽڵ㶼���գ�����ֵ���ȣ�Ҳ���Գƣ����ؼ�
		// ע�⣺�����ж��õ�else if�����ʣ�µ�����������ҽڵ㶼���գ���ֵ���
		// Ȼ��ݹ��ж�������
		// �������ڵ�����������ҽڵ���������ж϶Գ�
		bool outside = compare(left->left, right->right);
		// �ڲ�����ڵ�����������ҽڵ���������ж϶Գ�
		bool inside = compare(left->right, right->left);
		// ������㶼�Գƣ���ǰ�������Գ�
		// ��֮�򲻶Գ�
		bool isSame = outside && inside;
		return isSame;
	}
	bool isSymmetric(TreeNode* root) {
		if (!root) return true; // �пգ��ռ�����
		return compare(root->left, root->right);
	}
}



class Solution {
public:
	bool compare(TreeNode* left, TreeNode* right) {
		// �����ų��սڵ�����
		if (left == NULL && right != NULL) return false;
		else if (left != NULL && right == NULL) return false;
		else if (left == NULL && right == NULL) return true;
		// �ų��˿սڵ㣬���ų���ֵ����ͬ�����
		else if (left->val != right->val) return false;

		// ��ʱ���ǣ����ҽڵ㶼��Ϊ�գ�����ֵ��ͬ�����
		// ��ʱ�����ݹ飬����һ����ж�
		bool outside = compare(left->left, right->right);   // ���������� ����������
		bool inside = compare(left->right, right->left);    // ���������ҡ� ����������
		bool isSame = outside && inside;                    // ���������С� ���������� ���߼�����
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
		//����������Ϊ��return true;
		if (left == nullptr&&right == nullptr){
			return true;
			//������������һ��Ϊ��return false;
		}
		else if (left == nullptr || right == nullptr){
			return false;
			//������������Ϊ�յ���ֵ�����return false;
		}
		else if (left->val != right->val){
			return false;
		}
		//��ʱ�ߵ��⣬������������Ϊ����ֵ��ȣ����Կ�ʼ�ݹ�
		//���ж����
		bool outside = compare(left->left, right->right);
		bool inside = compare(left->right, right->left);
		bool issame = outside&&inside;
		return issame;

	}
	bool isSymmetric(TreeNode* root) {
		//�����ȿ������������root==nullptrֱ��return true;
		if (root == nullptr){
			return true;
		}
		//���Ӻ���compare��ݹ���
		return compare(root->left, root->right);
	}
};


class Solution {
public:
	bool compare(TreeNode*left, TreeNode*right){
		//����������Ϊ��return true;
		if (left == nullptr&&right == nullptr){
			return true;
			//������������һ��Ϊ��return false;
		}
		else if (left == nullptr || right == nullptr){
			return false;
			//������������Ϊ�յ���ֵ�����return false;
		}
		else if (left->val != right->val){
			return false;
		}
		//��ʱ�ߵ��⣬������������Ϊ����ֵ��ȣ����Կ�ʼ�ݹ�
		//�ݹ��ж����
		bool outside = compare(left->left, right->right);
		//�ݹ��ж��ڲ�
		bool inside = compare(left->right, right->left);
		bool issame = outside&&inside;
		return issame;

	}
	bool isSymmetric(TreeNode* root) {
		//�����ȿ������������root==nullptrֱ��return true;
		if (root == nullptr){
			return true;
		}
		//���Ӻ���compare��ݹ���
		return compare(root->left, root->right);
	}
};