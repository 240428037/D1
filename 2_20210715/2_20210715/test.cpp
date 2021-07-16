class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		//����
		while (root){
			if (p->val<root->val&&q->val<root->val){
				root = root->left;//root����
			}
			else if (p->val>root->val&&q->val>root->val){
				root = root->right;//root����
			}
			else{
				return root;//һ��һ��/p==root/q==root������������Ⱦ���root
			}
		}
		//��û�ҵ�return nullptr;
		return nullptr;
	}
};



class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		// �ݹ鷵��������
		// 1��rootΪ�սڵ�
		// 2��root��q��p������ȵ����
		if (root == NULL) return NULL;
		if (root->val == p->val || root->val == q->val) return root;
		if (root->val < p->val && root->val < q->val) {
			// q��p�����ڵ�ǰ���ڵ�
			// ȥ��������Ѱ��
			return lowestCommonAncestor(root->right, p, q);
		}
		else if (root->val > p->val && root->val > q->val) {
			// q��p��С�ڵ�ǰ���ڵ�
			// ȥ��������Ѱ��
			return lowestCommonAncestor(root->left, p, q);
		}
		else {
			// ����q��p�ڵ�ǰ���ڵ������
			// ��ǰ���ڵ㼴Ϊ�����������
			return root;
		}
	}
};