/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr){
            return nullptr;
        }
        //1.拷贝原链表的每个节点链接到原节点的后面
        //cur copy next1
        Node*cur=head;
        while(cur!=nullptr){
            Node*copy=new Node(cur->val);
            Node*next1=cur->next;
            cur->next=copy;
            copy->next=next1;
            cur=next1;//迭代
        }
        //2.处理拷贝节点的random
        //cur copy
        cur=head;
        while(cur!=nullptr){
            Node*copy=cur->next;
            if(cur->random){
                copy->random=cur->random->next;
            }
            else{
                copy->random=nullptr;
            }
            cur=copy->next;//迭代
        }
        //3.拆解
        //cur copy next1
        cur=head;
        Node*copyhead=cur->next;
        while(cur!=nullptr){
            Node*copy=cur->next;
            Node*next1=copy->next;
            cur->next=next1;
            if(next1){
                copy->next=next1->next;
            }
            else{
                copy->next=nullptr;
            }
            cur=next1;//迭代
        }
        return copyhead;
    }
};


class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        if(pHead==nullptr){
            return nullptr;
        }
        //1.拷贝原链表的每个节点链接到原节点的后面
        //cur copy next
        RandomListNode*cur=pHead;
        while(cur){
            RandomListNode*next=cur->next;
            RandomListNode*copy=new RandomListNode(cur->label);
            cur->next=copy;
            copy->next=next;
            cur=next;
        }
        //2.处理拷贝节点的random
        //cur copy
        cur=pHead;
        while(cur){
            RandomListNode*copy=cur->next;
            if(cur->random){
                copy->random=cur->random->next;
            }else{
                copy->random=nullptr;
            }
            cur=copy->next;
        }
        //3.拆解
        //cur copy next
        cur=pHead;
        RandomListNode*copyhead=cur->next;
        while(cur){
            RandomListNode*copy=cur->next;
            RandomListNode*next=copy->next;
            cur->next=next;
            if(next){
                copy->next=next->next;
            }else{
                copy->next=nullptr;
            }
            cur=next;
        }
        return copyhead;
    }
};


class Solution {
public:
    /*
    *  创建链表头指针和尾指针
    *  中序遍历过程中：
    *  到树的最左边节点即找到头指针所指节点，
    *  而尾指针随着遍历不断进行，尾指针不断右移，
    *  最后遍历到的树节点是尾指针所指节点
    */
    Node *head, *tail;
    void inOrder(Node* root) {
        if (root == nullptr) return; // 递归跳出条件
        inOrder(root->left); // 遍历左子树
        /*
        *  初始head和tail都为空，root代表当前遍历到的树节点。
        *  递归一层一层进去，当达到树最左边的节点时，中序遍历才会开始执行下面代码。
        *  达到最左边的节点时tail任然为空，将head指向该节点，即双向链表的头节点已经找到；
        *  此时tail更新指向当前遍历到的树节点；
        *  递归跳出一层，此时tail已经不为空了，并且指向的是在中序遍历顺序中当前遍历到的树节点的前面一个节点，
        *  （比如当前遍历到的是左子树根节点，则tail指向的就是左子树左孩子节点）
        *  将这两个节点之间进行双向连接，并将tail更新指向当前遍历到的节点。
        *  
        *  这样中序遍历不断进行，tail就从树的最左边节点按着中序遍历的顺序不断移动，
        *  直到最后遍历到树的最右边节点，在这个过程中完成双向链表的构建。
        */
        if (tail == nullptr) {
            head = root;
        } else {
            tail->right = root;
            root->left = tail;
        }
        tail = root;

        inOrder(root->right); // 遍历右子树
    }
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) return nullptr; // 判空
        
        inOrder(root); // 中序遍历二叉搜索树
        
        // 遍历完之后，将双向链表头尾相接即全部完成
        tail->right = head;
        head->left = tail;
        return head;
    }
};
