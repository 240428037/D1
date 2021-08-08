

    vector<int> rightview(TreeNode* root) {
        if(root == nullptr) 
        return {};
        vector<int> vec;
        queue<TreeNode*> que;
        int k = 0;
        que.push(root);
        while(!que.empty()){
            k = que.size();
            while(k--){
                root = que.front();
                que.pop();
                if(k==0)   vec.push_back(root->val);
                if(root->left)  que.push(root->left);
                if(root->right) que.push(root->right);
            }
        }
        return vec;
    }


class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)return {};
        vector<int>ans;
        queue<TreeNode*>que;
        que.push(root);
        while(!que.empty()){
            for(int i=que.size()-1;i>=0;i--){
                TreeNode*tmp=que.front();que.pop();
                if(i==0)ans.push_back(tmp->val);
                if(tmp->left)que.push(tmp->left);
                if(tmp->right)que.push(tmp->right);
            }
        }
        return ans;
    }
};

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
    //解题思路
    //递归
    int maxDepth(TreeNode* root) {
        //递归终止条件
        if(root==nullptr){
            return 0;
        }
        int leftdepth=maxDepth(root->left);
        int rightdepth=maxDepth(root->right);
        return leftdepth>rightdepth?leftdepth+1:rightdepth+1;
    }
};





class Solution {
public:
    //解题思路
    //复用求二叉树最大深度代码
    //递归
    //return abs&&左子树是否为平衡树&&右子树是否为平衡树
    int maxdepth(TreeNode*root){
        if(root==nullptr){
            return 0;
        }
        int leftdepth=maxdepth(root->left);
        int rightdepth=maxdepth(root->right);
        return leftdepth>rightdepth?leftdepth+1:rightdepth+1;
    }
    bool IsBalanced_Solution(TreeNode* root) {
        if(root==nullptr){
            return true;
        }
        int leftdepth=maxdepth(root->left);
        int rightdepth=maxdepth(root->right);
        return abs(leftdepth-rightdepth)<=1
            &&IsBalanced_Solution(root->left)
            &&IsBalanced_Solution(root->right);
    }
};



//前序中序重建二叉树
class Solution {
public:
    //解题思路
    //前序需要下标，中序需要区间
    //递归
    TreeNode*Rebuild(vector<int> pre,vector<int> vin,int&prei,int inbegin,int inend){
        //递归终止条件
        if(inbegin>inend){
            return nullptr;
        }
        //重建根节点
        TreeNode*root=new TreeNode(pre[prei]);
        //划分中序区间然后递归
        int rooti=inbegin;
        while(rooti<=inend){
            if(vin[rooti]==pre[prei]){
                break;
            }else{
                rooti++;
            }
        }
        //[inbegin,rooti-1]rooti[rooti+1,inend]
        //重建左右子树
        if(inbegin<=rooti-1){
            root->left=Rebuild(pre,vin,++prei,inbegin,rooti-1);
        }else{
            root->left=nullptr;
        }
        if(rooti+1<=inend){
            root->right=Rebuild(pre,vin,++prei,rooti+1,inend);
        }else{
            root->right=nullptr;
        }
        return root;
    }
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int prei=0;
        int inbegin=0;
        int inend=vin.size()-1;
        return Rebuild(pre,vin,prei,inbegin,inend);
    }
};


class Solution {
public:
        TreeNode*Rebuild(vector<int> pre,vector<int> vin,int&prei,int inbegin,int inend){
        //递归终止条件
        if(inbegin>inend){
            return nullptr;
        }
        //重建根节点
        TreeNode*root=new TreeNode(pre[prei]);
        //划分中序区间然后递归
        int rooti=inbegin;
        while(rooti<=inend){
            if(vin[rooti]==pre[prei]){
                break;
            }else{
                rooti++;
            }
        }
        //[inbegin,rooti-1]rooti[rooti+1,inend]
        //重建左右子树
        if(inbegin<=rooti-1){
            root->left=Rebuild(pre,vin,++prei,inbegin,rooti-1);
        }else{
            root->left=nullptr;
        }
        if(rooti+1<=inend){
            root->right=Rebuild(pre,vin,++prei,rooti+1,inend);
        }else{
            root->right=nullptr;
        }
        return root;
    }
        vector<int> rightview(TreeNode* root) {
        if(root == nullptr) 
        return {};
        vector<int> vec;
        queue<TreeNode*> que;
        int k = 0;
        que.push(root);
        while(!que.empty()){
            k = que.size();
            while(k--){
                root = que.front();
                que.pop();
                if(k==0)   vec.push_back(root->val);
                if(root->left)  que.push(root->left);
                if(root->right) que.push(root->right);
            }
        }
        return vec;
    }
    vector<int> solve(vector<int>& xianxu, vector<int>& zhongxu) {
        vector<int>v;
        int prei=0;
        int inbegin=0;
        int inend=zhongxu.size()-1;
        return rightview(Rebuild(xianxu,zhongxu,prei,inbegin,inend));
        
    }
};


//根据二叉前序中序重建二叉树
//打印二叉树右视图
class Solution {
public:
    //解题思路
    //前序中序重建二叉树
    //二叉树层序遍历不分层打印-对于插入加限制条件
    TreeNode*Rebuild(vector<int>pre,vector<int>vin,int&prei,int inbegin,int inend){
        //递归终止条件
        if(inbegin>inend){
            return nullptr;
        }
        //重建根节点
        TreeNode*root=new TreeNode(pre[prei]);
        //根据前序去划分中序
        int rooti=inbegin;//!!!
        while(rooti<=inend){
            if(vin[rooti]==pre[prei]){
                break;
            }else{
                rooti++;
            }
        }
        //划分完成后
        //递归重建左右子树
        if(inbegin<=rooti-1){
            root->left=Rebuild(pre,vin,++prei,inbegin,rooti-1);
        }else{
            root->left=nullptr;
        }
        if(rooti+1<=inend){
            root->right=Rebuild(pre,vin,++prei,rooti+1,inend);
        }else{
            root->right=nullptr;
        }
        return root;
    }
    vector<int>Rightview(TreeNode*root){
        vector<int>v;
        if(root==nullptr){
            return v;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            for(int i=q.size()-1;i>=0;i--){
                TreeNode*cur=q.front();
                q.pop();
                if(i==0){
                    v.push_back(cur->val);
                }
                if(cur->left){
                    q.push(cur->left);
                }
                if(cur->right){
                    q.push(cur->right);
                }
            }
        }
        return v;
    }
    vector<int> solve(vector<int>& xianxu, vector<int>& zhongxu) {
        int prei=0;
        int inbegin=0;
        int inend=zhongxu.size()-1;
        TreeNode*root=Rebuild(xianxu,zhongxu,prei,inbegin,inend);
        return Rightview(root);
    }
};