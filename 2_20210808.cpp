//奇数层-正向
//偶数层-反向
class Solution {
public:
    //解题思路
    //使用队列
    //上一层节点出队列带下一层节点入队列
    vector<vector<int> > Print(TreeNode* root) {
        vector<vector<int>>vv;
        if(root==nullptr){
            return vv;
        }
        queue<TreeNode*>q;
        q.push(root);
        int levelcount=0;
        while(!q.empty()){
            vector<int>v;
            int levelsize=q.size();
            levelcount++;
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
            if(levelcount%2==0){
                reverse(v.begin(),v.end());
            }
            vv.push_back(v);
        }
        return vv;
    }
};


class Solution {
public:
    TreeNode*CommonAncestor(TreeNode* root,int o1,int o2){
        //递归终止条件
        //递归到叶子节点或者root=p/q
        if(root==nullptr||root->val==o1||root->val==o2){
            return root;
        }
        TreeNode*left=CommonAncestor(root->left,o1,o2);//返回左侧p/q节点
        TreeNode*right=CommonAncestor(root->right,o1,o2);//返回右侧p/q节点
        //左右都没
        if(left==nullptr&&right==nullptr){
            return nullptr;
        }
        //都在右侧
        if(left==nullptr){
            return right;
        }
        //都在左侧
        if(right==nullptr){
            return left;
        }
        //一左一右
        return root;
    }
    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        return CommonAncestor(root,o1,o2)->val;
    }
};


class Solution {
public:
    //解题思路
    //递归
    //既然递归解决-给定函数返回值为int-需要在子函数内递归
    TreeNode*CommonAncestor(TreeNode* root, int o1, int o2){
        if(root->val==o1||root->val==o2){
            return root;
        }
        TreeNode*left=CommonAncestor(root->left,o1,o2);
        TreeNode*right=CommonAncestor(root->right,o1,o2);
        //pq左右都不在
        if(left==nullptr&&right==nullptr){
            return nullptr;
        }
        //pq都在右
        if(left==nullptr){
            return right;
        }
        //pq都在左
        if(right==nullptr){
            return left;
        }
        //pq一左一右
        return root;
    }
    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        return CommonAncestor(root,o1,o2)->val;
    }
};