class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr){
            return nullptr;
        }
        //快慢指针找倒数第k个节点
        ListNode*slow=head;
        ListNode*fast=head;
        //防止n比链表长度还大
        while(n--){
            fast=fast->next;
        }
        //要删除的节点是否为头节点
        if(fast==nullptr){
            return head->next;
        }
        //存储要删除节点的前一个节点
        ListNode*prev=nullptr;
        while(fast){
            fast=fast->next;
            prev=slow;
            slow=slow->next;
        }
        prev->next=slow->next;
        return head;
    }
};


//12345,1
//5
class Solution {
public:
    //解题思路
    //快慢指针
    //快指针先走k步然后快慢指针一起走
    ListNode* FindKthToTail(ListNode*head, int k) {
        if(head==nullptr){
            return nullptr;
        }
        ListNode*slow=head;
        ListNode*fast=head;
        while(k--){
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


//12345,1
//5
class Solution {
public:
    //解题思路
    //快慢指针
    //快指针先走k步然后快慢指针一起走
    ListNode* FindKthToTail(ListNode*head, int k) {
        if(head==nullptr){
            return nullptr;
        }
        ListNode*slow=head;
        ListNode*fast=head;
        while(k--){
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


//12345,1
//5
class Solution {
public:
    //解题思路
    //快慢指针
    //快指针先走k步然后快慢指针一起走
    ListNode* FindKthToTail(ListNode*head, int k) {
        if(head==nullptr){
            return nullptr;
        }
        ListNode*slow=head;
        ListNode*fast=head;
        while(k--){
            if(fast){
                fast=fast->next;
            }else{
                return nullptr;
            }
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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode*cur1=pHead1;
        ListNode*cur2=pHead2;
        int l1=0;
        int l2=0;
        while(cur1){
            l1++;
            cur1=cur1->next;
        }
        while(cur2){
            l2++;
            cur2=cur2->next;
        }
        ListNode*longlist=pHead1;
        ListNode*shortlist=pHead2;
        if(l1<l2){
            longlist=pHead2;
            shortlist=pHead1;
        }
        int gap=abs(l1-l2);
        while(gap--){
            longlist=longlist->next;
        }
        while(longlist){
            if(longlist==shortlist){
                return longlist;
            }
            longlist=longlist->next;
            shortlist=shortlist->next;
        }
        return nullptr;
    }
};



class Solution {
public:
    //解题思路
    //求链表12的长度l1l2
    //gap=abs(l1=l2)
    //让长的链表先走gap步然后长短链表再一起走
    //如果节点相等则这个节点为第一个公共节点
    ListNode* FindFirstCommonNode( ListNode*head1, ListNode*head2) {
        if(head1==nullptr||head2==nullptr){
            return nullptr;
        }
        ListNode*cur1=head1;
        ListNode*cur2=head2;
        int l1=0;
        int l2=0;
        while(cur1){
            l1++;
            cur1=cur1->next;
        }
        while(cur2){
            l2++;
            cur2=cur2->next;
        }
        ListNode*longlist=head1;
        ListNode*shortlist=head2;
        if(l1<l2){
            longlist=head2;
            shortlist=head1;
        }
        int gap=abs(l1-l2);
        while(gap--){
            longlist=longlist->next;
        }
        while(longlist){
            if(longlist==shortlist){
                return longlist;
            }
            longlist=longlist->next;
            shortlist=shortlist->next;
        }
        return nullptr;
    }
};