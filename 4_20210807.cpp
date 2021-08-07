class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur != NULL || !st.empty()) {
            if (cur != NULL) { // 指针来访问节点，访问到最底层
                st.push(cur); // 将访问的节点放进栈
                cur = cur->left;                // 左
            } else {
                cur = st.top(); // 从栈里弹出的数据，就是要处理的数据（放进result数组里的数据）
                st.pop();
                result.push_back(cur->val);     // 中
                cur = cur->right;               // 右
            }
        }
        return result;
    }
};


class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        if (root == NULL) return result;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();                       // 中
            st.pop();
            result.push_back(node->val);
            if (node->right) st.push(node->right);           // 右（空节点不入栈）
            if (node->left) st.push(node->left);             // 左（空节点不入栈）
        }
        return result;
    }
};
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        if (root == NULL) return result;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            result.push_back(node->val);
            if (node->left) st.push(node->left); // 相对于前序遍历，这更改一下入栈顺序 （空节点不入栈）
            if (node->right) st.push(node->right); // 空节点不入栈
        }
        reverse(result.begin(), result.end()); // 将结果反转之后就是左右中的顺序了
        return result;
    }
};



///////////////


class Solution {
public:
    //后序递归
    void postorder22(TreeNode*root,vector<int>&v){
        if(root==nullptr){
            return;
        }
        postorder22(root->left,v);
        postorder22(root->right,v);
        v.push_back(root->val);
        
    }
    vector<int>postorder11(TreeNode*root){
        vector<int>v;
        postorder22(root,v);
        return v;
    }
    
    
    
    
    //前序迭代
    vector<int>preorder1(TreeNode* root){
        vector<int>v;
        stack<TreeNode*>st;
        TreeNode*cur=root;
        while(!st.empty()||cur){
            while(cur){
                st.push(cur);
                v.push_back(cur->val);
                cur=cur->left;
            }
            cur=st.top();
            st.pop();
            cur=cur->right;
        }
        return v;
    }
    
    
    vector<int>preorder2(TreeNode*root){
        vector<int>v;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            TreeNode*cur=st.top();
            st.pop();
            v.push_back(cur->val);
            if(cur->right){
                st.push(cur->right);
            }
            if(cur->left){
                st.push(cur->left);
            }
        }
    }
    //中序迭代
    vector<int>inorder(TreeNode*root){
        vector<int>v;
        stack<TreeNode*>st;
        TreeNode*cur=root;
        while(!st.empty()||cur){
            while(cur){
                st.push(cur);
                cur=cur->left;
            }
            cur=st.top();
            st.pop();
            v.push_back(cur->val);
            cur=cur->right;
        }
        return v;
    }
    //后序迭代
    vector<int>postorder(TreeNode*root){
        vector<int>v;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            TreeNode*cur=st.top();
            st.pop();
            v.push_back(cur->val);
            if(cur->left){
                st.push(cur->left);
            }
            if(cur->right){
                st.push(cur->right);
            }
        }
        reverse(v.begin(),v.end());
        return v;
    }
    vector<vector<int> > threeOrders(TreeNode* root) {
        vector<vector<int>>vv;
        vv.push_back(preorder2(root));
        vv.push_back(inorder(root));
        vv.push_back(postorder(root));
        return vv;
    }
};