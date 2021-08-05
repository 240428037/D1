class Solution {
public:
    vector<vector<int>> ret; // 设置全局变量存储所有可能的路径
    void backTracking(TreeNode* root, vector<int>& path, int& target) {
        /*
        *  递归终止条件：
        *  遇到空节点
        */
        if (!root) return;
        /*
        *  前序遍历，
        *  target值减去当前根节点的值，表示将根节点并入一条路径
        *  根节点存入path中
        */
        target -= root->val;
        path.push_back(root->val);
        /*
        *  判断寻找到一条路径的条件：
        *  1、target为0（因为target减去一个节点的值表示将该节点并入当前路径）
        *  2、当前节点的左子树为0
        *  3、当前节点的右子树为0
        *  （因为一条路径是从树的根节点一直到叶节点）
        *  这三个条件缺一不可，所以是&&关系
        *  满足条件，则将当前搜索到的路径存入ret中，即已经寻找到一条满足要求的路径
        */
        if (target == 0 && root->left == nullptr && root->right == nullptr) ret.push_back(path);
        /*
        *  还没有搜到满足要求的路径
        *  则递归调用，先搜左子树，再搜右子树
        */
        backTracking(root->left, path, target);
        backTracking(root->right, path, target);
        /*
        *  回溯：将各个变量还原到此次函数调用最开始的状态
        *  1、将先存入path的节点从path中删除
        *  2、将target的值加回来
        *  这样才能保证后续寻找路径不出错
        *  比如：
        *  一开始递归调用一直沿着左边直到树的最左边叶子结点，
        *  但是发现这条路径不符合要求，
        *  现在要去左叶子结点所在子树的右子树寻找路径，
        *  这时会跳出一次递归，返回上一层递归（也就是搜索左叶子结点所在子树根节点的那次递归）。
        *  若我们没有在跳出这次递归之后还原path和target，
        *  则返回上一层递归时这两个变量的值还是搜索左叶子结点之后的值，
        *  这样的话再去搜索右子树必然不能得到正确的结果。
        */
        path.pop_back();
        target += root->val;
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        if (!root) return {}; // 判空
        vector<int> path; // 存储一条可能的路径
        backTracking(root, path, target); // 回溯 前序遍历
        return ret; // 返回所有可能的路径
    }
};


class Solution {
public:
    vector<vector<int>>vv;
    void backtracking(TreeNode*root,vector<int>&v,int&target){
        if(root==nullptr){
            return;
        }
        target-=root->val;
        v.push_back(root->val);
        if(target==0&&root->left==nullptr&&root->right==nullptr){
            vv.push_back(v);
        }
        backtracking(root->left,v,target);
        backtracking(root->right,v,target);
        v.pop_back();
        target+=root->val;
    }
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root==nullptr){
            return{};
        }
        vector<int>v;
        backtracking(root,v,expectNumber);
        return vv;
    }
};