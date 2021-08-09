class Solution {
public:
    //解题思路
    //1.迭代-三指针翻转
    //2.头插
    ListNode* ReverseList(ListNode* head) {
        /*//1.迭代
        ListNode*n1=nullptr;
        ListNode*n2=head;
        ListNode*n3=head->next;
        while(n2){
            n2->next=n1;
            n1=n2;
            n2=n3;
            if(n3){
                n3=n3->next;
            }
        }
        return n1;*/
        //2.头插
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
};


class Solution {
public:
    //解题思路
    //归并排序思想
    ListNode* Merge(ListNode* head1, ListNode* head2) {
        if(head1==nullptr){
            return head2;
        }
        if(head2==nullptr){
            return head1;
        }
        ListNode*head=nullptr;
        ListNode*tail=nullptr;
        if(head1->val<head2->val){
            head=tail=head1;
            head1=head1->next;
        }else{
            head=tail=head2;
            head2=head2->next;
        }
        while(head1&&head2){
            if(head1->val<head2->val){
                tail->next=head1;
                head1=head1->next;
            }else{
                tail->next=head2;
                head2=head2->next;
            }
            tail=tail->next;
        }
        while(head1){
            tail->next=head1;
            head1=head1->next;
            tail=tail->next;
        }
        while(head2){
            tail->next=head2;
            head2=head2->next;
            tail=tail->next;
        }
        return head;
    }
};



class Solution {
public:
    //解题思路
    //1.迭代-三指针翻转
    //2.头插
    ListNode* ReverseList(ListNode* head) {
        /*//1.迭代
        if(head==nullptr){
            return nullptr;
        }
        ListNode*n1=nullptr;
        ListNode*n2=head;
        ListNode*n3=head->next;
        while(n2){
            n2->next=n1;
            n1=n2;
            n2=n3;
            if(n3){
                n3=n3->next;
            }
        }
        return n1;*/
        //2.头插
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
};



class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr||k<=1){
            return head;
        }
        ListNode*prev=nullptr;
        ListNode*cur=head;
        ListNode*next=cur->next;
        //如果k大于链表长度return head;
        for(int i=0;i<k;i++){
            if(cur==nullptr){
                return head;
            }
            cur=cur->next;
        }
        cur=head;
        for(int i=0;i<k;i++){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        //prev cur next
        //此时k个ListNode翻转完毕，尾(原来的头)指向递归后返回的头
        head->next=reverseKGroup(next,k);
        return prev;//返回新的头
    }
};



//12345
//k=2,21435
//k=3,32145
class Solution {
public:
    //解题思路
    //
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr){
            return nullptr;
        }
        ListNode*n1=nullptr;
        ListNode*n2=head;
        ListNode*n3=head->next;
        //判断k是否大于链表长度
        for(int i=0;i<k;i++){
            if(n2==nullptr){
                return head;
            }
            n2=n2->next;
        }
        n2=head;//判断完后重新初始化n2
        //开始翻转
        for(int i=0;i<k;i++){
            n3=n2->next;
            n2->next=n1;
            n1=n2;
            n2=n3;
        }
        //链接+递归
        //此时k个ListNode翻转完毕
        //尾(原来的头)指向递归后返回的头
        head->next=reverseKGroup(n3,k);
        return n1;
    }
};


class Solution {
public:
    //解题思路
    //快慢指针
    bool hasCycle(ListNode *head) {
        if(head==nullptr||head->next==nullptr){
            return false;
        }
        ListNode*slow=head;
        ListNode*fast=head->next;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return true;
            }
        }
        return false;
    }
};



class Solution {
public:
    //解题思路
    //快慢指针
    ListNode* EntryNodeOfLoop(ListNode* head) {
        if(head==nullptr||head->next==nullptr){
            return nullptr;
        }
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
            //有环一定有入口节点
            if(slow==fast){
                ListNode*meet=fast;
                while(head!=meet){
                    head=head->next;
                    meet=meet->next;
                }
                return meet;
            }
        }
        return nullptr;//无环return nullptr
    }
};