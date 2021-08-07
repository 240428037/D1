class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        if(root==nullptr){
            return{};
        }
        vector<int>v;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int levelsize=q.size();
            for(int i=0;i<levelsize;i++){
                TreeNode*front=q.front();
                v.push_back(front->val);
                q.pop();
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
        }
        return v;
    }
};


class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            if(pRoot==nullptr){
                return{};
            }
            vector<vector<int>>vv;
            queue<TreeNode*>q;
            q.push(pRoot);
            while(!q.empty()){
                vector<int>v;
                int levelsize=q.size();
                for(int i=0;i<levelsize;i++){
                    TreeNode*front=q.front();
                    v.push_back(front->val);
                    q.pop();
                    if(front->left){
                        q.push(front->left);
                    }
                    if(front->right){
                        q.push(front->right);
                    }
                }
                vv.push_back(v);
            }
            return vv;
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



class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>v;
        stack<TreeNode*>st;
        TreeNode*cur=root;
        TreeNode*prev=nullptr;
        while(!st.empty()||cur!=nullptr){
            while(cur!=nullptr){
                st.push(cur);
                cur=cur->left;
            }
            TreeNode*top=st.top();
            if(top->right==nullptr||prev==top->right){
                st.pop();
                v.push_back(top->val);
                prev=top;
            }else{
                cur=top->right;
            }
        }
        return v;
    }
};