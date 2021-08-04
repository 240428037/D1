class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        //从左下角开始找
        //(array.size()-1,0)
        int i=array.size()-1;
        int j=0;
        while(i>=0&&j<array[0].size()){
            if(array[i][j]<target){
                j++;
            }else if(array[i][j]>target){
                i--;
            }else if(array[i][j]==target){
                return true;
            }
        }
        return false;
    }
};


class Solution {
public:
    bool issametree(TreeNode*root1,TreeNode*root2){
        if(root1==nullptr&&root2==nullptr){
            return true;
        }else if(root1!=nullptr&&root2==nullptr){
            return true;
        }else if(root1==nullptr&&root2!=nullptr){
            return false;
        }else if(root1->val!=root2->val){
            return false;
        }
        return issametree(root1->left,root2->left)&&issametree(root1->right,root2->right);
    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        //规定空树不是任意一个树的子结构
        if(pRoot1==nullptr||pRoot2==nullptr){
            return false;
        }
        //2树和1树相同
        if(pRoot1->val==pRoot2->val&&issametree(pRoot1,pRoot2)){
            return true;
        }
        //递归判断1树左子树||1树右子树
        return HasSubtree(pRoot1->left,pRoot2)||HasSubtree(pRoot1->right,pRoot2);
    }
};



class MinStack {
public:
    stack<int>st1;//数据栈
    stack<int>st2;//辅助栈
    MinStack() {
    }
    void push(int x) {
        st1.push(x);
        if(st2.empty()||x<=st2.top()){
            st2.push(x);
        }
    }
    //顺序不能反
    void pop() {
        if(st2.top()==st1.top()){
            st2.pop();
        }
        st1.pop();//先比较再pop;不然st1都pop了，st2和谁比去
    }
    int top() {
        return st1.top();
    }
    int min() {
        return st2.top();
    }
};


class Solution {
public:
    stack<int>st1;
    stack<int>st2;
    void push(int value) {
        st1.push(value);
        if(st2.empty()||value<=st2.top()){
            st2.push(value);
        }
    }
    void pop() {
        if(st2.top()==st1.top()){
            st2.pop();
        }
        st1.pop();
    }
    int top() {
        return st1.top();
    }
    int min() {
        return st2.top();
    }
};