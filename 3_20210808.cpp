class Solution {
public:
    //pre,vin,prei需要传引用！！！
    //pre,vin,prei需要传引用！！！
    //pre,vin,prei需要传引用！！！
    TreeNode*RebuildTree(vector<int>&pre,vector<int>&vin,int&prei,int inbegin,int inend){
        //终止条件
        if(inbegin>inend){
            return nullptr;
        }
        //重建根节点
        TreeNode*root=new TreeNode(pre[prei]);
        
        //划分中序区间
        int rooti=inbegin;
        while(rooti<=inend){
            if(vin[rooti]==pre[prei]){
                break;
            }else{
                rooti++;
            }
        }
        
        //[inbeign,rooti-1],rooti,[rooti+1,inend]
        if(inbegin<=rooti-1){
            root->left=RebuildTree(pre,vin,++prei,inbegin,rooti-1);
        }else{
            root->left=nullptr;
        }
        
        if(rooti+1<=inend){
            root->right=RebuildTree(pre,vin,++prei,rooti+1,inend);
        }else{
            root->right=nullptr;
        }
        
        return root;
    }
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        //前序需要下标，中序需要区间
        int prei=0;
        int inbegin=0;
        int inend=vin.size()-1;
        return RebuildTree(pre,vin,prei,inbegin,inend);
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