class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        //快慢指针判环
        ListNode*slow=pHead;
        ListNode*fast=pHead;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
            //有环再找入口点
            if(slow==fast){
                //meet相遇点
                ListNode*meet=fast;
                //head和meet一起走，相遇跳出循环return
                while(pHead!=meet){
                    pHead=pHead->next;
                    meet=meet->next;
                }
                return meet;
            }
        }
        //无环return nullptr;
        return nullptr;
    }
};



class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        if(pHead==nullptr||pHead->next==nullptr){
            return nullptr;
        }
        //快慢指针判环
        ListNode*slow=pHead;
        ListNode*fast=pHead;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
            //有环再找入口点
            if(slow==fast){
                //meet相遇点
                ListNode*meet=fast;
                //head和meet一起走，相遇跳出循环return
                while(pHead!=meet){
                    pHead=pHead->next;
                    meet=meet->next;
                }
                return meet;
            }
        }
        //无环return nullptr;
        return nullptr;
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


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //1.快慢指针找中间节点
        ListNode*slow=head,*fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        //反转后半段链表
        ListNode*cur=slow;
        ListNode*newhead=nullptr;
        while(cur!=nullptr){
            ListNode*next=cur->next;
            cur->next=newhead;
            newhead=cur;
            cur=next;
        }
        //判断回文
        //&&任意一个头节点走到空就结束
        while(newhead!=nullptr&&head!=nullptr){
            if(newhead->val!=head->val){
                return false;
            }
            newhead=newhead->next;
            head=head->next;
        }
        return true;
    }
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //建立双指针
    ListNode * first = head;
    ListNode * second = head;
    //建立虚拟头结点并与头结点连接
   ListNode * vhead =new ListNode (0);
    vhead->next = head;
    ListNode * pre =vhead;
    //先让first指针走n步
   while(n>0)
{
    first = first ->next;
    n--;
}
//再让双指针同时走找出要删除的结点，用pre记录要删除结点的前一个结点
while(first)
{
    first=first->next;
    pre=second;
    second= second->next;
}
//将要删除的节点的前一结点与其后一结点连接
pre->next =second->next;
return vhead->next;
    }
};


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* head0=new ListNode(0);
    head0->next=head;
    ListNode* slow=head0;
    ListNode* fast=head0;
    for(int i=0;i<=n;i++)
    {fast=fast->next;}
    while(fast)
    {slow=slow->next;
     fast=fast->next;
    }
    ListNode* temp=slow->next;
    slow->next=temp->next;
    delete temp;
    return head0->next;

    }
};



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



class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode* evenHead = head->next;
        ListNode* odd = head;
        ListNode* even = evenHead;
        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};

class Solution {
public:
    //奇数odd-短的是奇数
    //偶数even-长的是偶数
    //123456
    //135 246
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr){
            return nullptr;
        }
        ListNode*evenhead=head->next;//偶数链表头节点
        ListNode*odd=head;//奇数
        ListNode*even=head->next;//偶数
        //odd even odd
        while(even&&even->next){
            odd->next=even->next;
            odd=odd->next;//奇数迭代
            even->next=odd->next;
            even=even->next;//偶数迭代
        }
        odd->next=evenhead;//奇数链表链接偶数链表节点
        return head;
    }
};