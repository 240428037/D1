class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        stack<int> a;
        stack<int> b;

        while (l1)
        {
            a.push(l1->val);
            l1 = l1->next;
        }
        while (l2)
        {
            b.push(l2->val);
            l2 = l2->next;
        }

        ListNode * r = NULL;
        int carry = 0;
        while (!a.empty() || !b.empty() || carry)
        {
            int x = !a.empty() ? a.top() : 0;
            if (!a.empty())     a.pop();
            int y = !b.empty() ? b.top() : 0;
            if (!b.empty())     b.pop();
            int cur_val = (x + y + carry) % 10;
            carry = (x + y + carry) / 10;

            ListNode * cur = new ListNode(cur_val);
            cur->next = r;
            r = cur;
        }

        return r;
    }
};



class Solution {
public:
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        stack<int>st1;
        stack<int>st2;
        while(head1){
            st1.push(head1->val);
            head1=head1->next;
        }
        while(head2){
            st2.push(head2->val);
            head2=head2->next;
        }
        ListNode*head=new ListNode(-1);
        int carry=0;
        while(!st1.empty()||!st2.empty()||carry){
            int x=!st1.empty()?st1.top():0;
            if(st1.empty()){
                st1.pop();
            }
            int y=!st2.empty()?st2.top():0;
            if(st2.empty()){
                st2.pop();
            }
            int z=(x+y+carry)%10;
            carry=(x+y+carry)/10;
            ListNode*cur=new ListNode(z);
            cur->next=head;
            head=cur;
        }
        return head;
    }
};



public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.size() == 0)
            return nullptr;
        ListNode* head = nullptr;
        for(int i = 0; i < lists.size(); ++i){
            head = connectList(head, lists[i]);
        }
        return head;
    }

    ListNode* connectList(ListNode* p1, ListNode* p2){ //两两比较
        if(p1 == nullptr || p2 == nullptr)
            return p1 == nullptr ? p2 : p1;
        if(p1->val < p2->val){
            p1->next = connectList(p1->next, p2);
            return p1;
        }
        else{
            p2->next = connectList(p1, p2->next);
            return p2;
        }
    }
};


class Solution {
public:
    ListNode*connectlist(ListNode*l1,ListNode*l2){
        if(l1==nullptr||l2==nullptr){
            return l1==nullptr?l2:l1;
        }
        if(l1->val<l2->val){
            l1->next=connectlist(l1->next,l2);
            return l1;
        }else{
            l2->next=connectlist(l1,l2->next);
            return l2;
        }
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.size()==0){
            return nullptr;
        }
        ListNode*head=nullptr;
        for(int i=0;i<lists.size();i++){
            head=connectlist(head,lists[i]);
        }
        return head;
    }
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> nums;
        ListNode *p = head;

        while(p) {
            nums.push_back(p->val);
            p = p->next;
        }
        sort(nums.begin(), nums.end());

        p = head;
        int i = 0;
        while(p) {
            p->val = nums[i++];
            p = p->next;
        }
        return head;
    }
};
class Solution {
public:
    /**
     * 
     * @param head ListNode类 the head node
     * @return ListNode类
     */
    ListNode* sortInList(ListNode* head) {
        vector<int> vec;
        ListNode* cur = head;
        // 1.构建vector
        while(cur) {
            vec.push_back(cur->val);
            cur = cur->next;
        }
        // 2.vector排序
        sort(vec.begin(), vec.end());
        // 3.构建链表
        ListNode* dummy = new ListNode(0);
        ListNode* res = new ListNode(0);
        dummy->next = res;
        for(int i : vec) {
            res->next = new ListNode(i);
            res = res->next;
        }
        res->next = nullptr;
        return dummy->next->next;
    }
};



class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        ListNode*lesshead,*lesstail;
        ListNode*greaterhead,*greatertail;
        //用哨兵位的头节点初始化
        lesshead=lesstail=new ListNode(0);
        greaterhead=greatertail=new ListNode(0);
        //分割
        ListNode*cur=pHead;
        while(cur){
            if(cur->val<x){
                lesstail->next=cur;
                cur=cur->next;
                lesstail=lesstail->next;
            }else{
                greatertail->next=cur;
                cur=cur->next;
                greatertail=greatertail->next;
            }
        }
        greatertail->next=nullptr;//置空防止成环
        lesstail->next=greaterhead->next;//链接
        return lesshead->next;
    }
};
