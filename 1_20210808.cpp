class Solution {
public:
    //解题思路
    //二叉树的层序遍历分层打印
    //借助队列来实现
    //上一层节点出队列带下一层节点入队列
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int>>vv;
        if(root==nullptr){
            return vv;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>v;
            int levelsize=q.size();
            for(int i=0;i<levelsize;i++){
                TreeNode*cur=q.front();
                v.push_back(cur->val);
                q.pop();
                if(cur->left){
                    q.push(cur->left);
                }
                if(cur->right){
                    q.push(cur->right);
                }
            }
            vv.push_back(v);
        }
        return vv;
    }
};


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



//前序-根左右
//中序-左根右
//后序-左右根
class Solution {
public:
    //迭代
    vector<int>preorder(TreeNode*root){
        vector<int>v;
        if(root==nullptr){
            return v;
        }
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
    vector<int>inorder(TreeNode*root){
        vector<int>v;
        if(root==nullptr){
            return v;
        }
        stack<TreeNode*>st;
        TreeNode*cur=root;
        while(!st.empty()||cur){
            while(cur){
                st.push(cur);
                cur=cur->left;
            }
            cur=st.top();
            v.push_back(cur->val);
            st.pop();
            cur=cur->right;
        }
        return v;
    }
    vector<int>postorder(TreeNode*root){
        vector<int>v;
        if(root==nullptr){
            return v;
        }
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            TreeNode*cur=st.top();
            v.push_back(cur->val);
            st.pop();
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
    /////////////////////////////////////////////
    //递归
    /////////////////////////////////////////////
    void preorder11(TreeNode*root,vector<int>&v){
        if(root==nullptr){
            return;
        }
        v.push_back(root->val);
        preorder11(root->left,v);
        preorder11(root->right,v);
    }
    vector<int>preorder1(TreeNode*root){
        vector<int>v;
        preorder11(root,v);
        return v;
    }
    void inorder11(TreeNode*root,vector<int>&v){
        if(root==nullptr){
            return;
        }
        inorder11(root->left,v);
        v.push_back(root->val);
        inorder11(root->right,v);
    }
    vector<int>inorder1(TreeNode*root){
        vector<int>v;
        inorder11(root,v);
        return v;
    }
    void postorder11(TreeNode*root,vector<int>&v){
        if(root==nullptr){
            return;
        }
        postorder11(root->left,v);
        postorder11(root->right,v);
        v.push_back(root->val);
    }
    vector<int>postorder1(TreeNode*root){
        vector<int>v;
        postorder11(root,v);
        return v;
    }
    vector<vector<int> > threeOrders(TreeNode* root) {
        vector<vector<int>>vv;
        vv.push_back(preorder(root));
        vv.push_back(inorder(root));
        vv.push_back(postorder(root));
        return vv;
    }
};