class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int>v;
        if(head==nullptr){
            return v;
        }
        stack<int>st;
        ListNode*cur=head;
        while(cur){
            st.push(cur->val);
            cur=cur->next;
        }
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        return v;
    }
};



class Solution {
public:
    //1 2 3 4 5 k=1
    //5
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        if(pHead==nullptr){
            return nullptr;
        }
        ListNode*slow=pHead;
        ListNode*fast=pHead;
        while(k--){
            //如果该链表长度小于k，请返回一个长度为0的链表。
            if(fast==nullptr){
                return nullptr;
            }
            fast=fast->next;
        }
        while(fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};


class Solution {
public:
    //1 2 3 4 5 k=1
    //5
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        if(pHead==nullptr){
            return nullptr;
        }
        ListNode*slow=pHead;
        ListNode*fast=pHead;
        while(k--){
            //如果该链表长度小于k，请返回一个长度为0的链表。
            if(fast==nullptr){
                return nullptr;
            }
            fast=fast->next;
        }
        while(fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};


class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead==nullptr){
            return nullptr;
        }
        ListNode*n1=nullptr;
        ListNode*n2=pHead;
        ListNode*n3=pHead->next;
        while(n2){
            n2->next=n1;
            n1=n2;
            n2=n3;
            //if！！！
            if(n3){
                n3=n3->next;
            }
        }
        return n1;
    }
};


class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead==nullptr){
            return nullptr;
        }
        ListNode*cur=pHead;//工作指针
        ListNode*newhead=nullptr;//新的头节点
        while(cur){
            ListNode*next=cur->next;//保存位置
            cur->next=newhead;//头插
            newhead=cur;//赋值
            cur=next;//迭代
        }
        return newhead;
    }
};



class Solution {
public:
    //12345
    //123/54
    //15243
    ListNode*reverselist(ListNode*head){
        if(head==nullptr){
            return nullptr;
        }
        ListNode*cur=head;
        ListNode*newhead=nullptr;
        while(cur){
            ListNode*next=cur->next;
            cur->next=newhead;
            newhead=cur;
            cur=next;
        }
        return newhead;
    }
    void reorderList(ListNode *head) {
        if(head==nullptr||head->next==nullptr){
            return;
        }
        //寻找链表的中间节点
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        //从中间节点将链表断开并翻转后半段链表
        ListNode*tmp=slow->next;
        slow->next=nullptr;
        ListNode*newhead=reverselist(tmp);
        //合并链表
        //head-123
        //newhead-54
        //15243
        ListNode*cur=head;
        int k=0;
        while(cur&&newhead){
            if(k%2==0){
                ListNode*next=cur->next;
                cur->next=newhead;
                cur=next;
            }else{
                ListNode*next=newhead->next;
                newhead->next=cur;
                newhead=next;
            }
            k++;
        }
        return;
    }
};