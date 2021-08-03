class Solution {
public:
    //使用map,遍历一遍数组，当第一次出现重复的值时，此时map值大于1，直接return
    int duplicate(vector<int>& numbers) {
        if(numbers.empty()){
            return -1;
        }
        unordered_map<int,int>map;
        for(int i=0;i<numbers.size();i++){
            map[numbers[i]]++;
            if(map[numbers[i]]>1){
                return numbers[i];
            }
        }
        return -1;
    }
};


class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int>v;
        int left=0;
        int right=array.size()-1;
        while(left<right){
            if(array[left]+array[right]==sum){
                v.push_back(array[left]);
                v.push_back(array[right]);
                return v;
            }else if(array[left]+array[right]<sum){
                left++;
            }else if(array[left]+array[right]>sum){
                right--;
            }
        }
        return v;
    }
};


class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) {
                ret++;
            }
        }
        return ret;
    }
};


class Solution {
public:
     int  NumberOf1(int n) {
         int count=0;
         for(int i=0;i<32;i++){
             if(n&(1<<i)){
                 count++;
             }
         }
         return count;
     }
};


class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int>v;
        stack<int>st;
        while(head!=nullptr){
            st.push(head->val);
            head=head->next;
        }
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        return v;
    }
};


typedef struct ListNode ListNode;
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    //定义两个整形变量la,lb分别表示headA和headB链表的长度
    //为了不改变headA和headB
    //定义两个节点curA,curB让他们去遍历
    ListNode*curA=headA;
    int la=0;
    while(curA)
    {
        la++;
        curA=curA->next;
    }
    ListNode*curB=headB;
    int lb=0;
    while(curB)
    {
        lb++;
        curB=curB->next;
    }
    //开始先假定headA比headB长，如果不是，后面加个if再改
    ListNode*longlist=headA;
    ListNode*shortlist=headB;
    if(lb>la)
    {
        longlist=headB;
        shortlist=headA;
    }
    //abs是库函数，返回的是两个数相减的绝对值
    int gap=abs(lb-la);
    //让长的先走gap步，保证两个链表在走完之后长度相等，再进行比较
    while(gap--)
    {
        longlist=longlist->next;
    }
    //此时两个链表长度一样长，while里放longlist还是shortlist效果一样
    while(longlist)
    {
        //如果两个链表节点相同,就随便返回一个，over
        if(longlist==shortlist)
            return longlist;
        //如果if循环没进去，那两个链表接着往后走一步
        longlist=longlist->next;
        shortlist=shortlist->next;
    }
    //走到这里，说明没有return
    //那么这两个链表可能没有相交，return NULL;
    return NULL;
}



/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
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