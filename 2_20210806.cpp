class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head==nullptr||head->next==nullptr){
            return head;
        }
        ListNode*sorthead=head;
        ListNode*cur=head->next;
        sorthead->next=nullptr;//置空-防止链表成环
        while(cur!=nullptr){
            ListNode*next=cur->next;
            //头插
            //1
            //2->
            if(cur->val<=sorthead->val){
                cur->next=sorthead;
                sorthead=cur;
            }
            else{
                ListNode*sortprev=sorthead;
                ListNode*sortcur=sorthead->next;
                //中间插
                while(sortcur){
                    //3
                    //2->4
                    if(cur->val<=sortcur->val){
                        sortprev->next=cur;
                        cur->next=sortcur;
                        break;//跳出第二个while循环-迭代后再次进入第一个while循环
                    }
                    //4
                    //2->3->5
                    else{
                        sortprev=sortcur;
                        sortcur=sortcur->next;
                    }
                }
                //尾插
                if(sortcur==nullptr){
                    sortprev->next=cur;
                    cur->next=nullptr;//置空-防止链表成环
                }
            }
            cur=next;//迭代
        }
        return sorthead;
    }
};




class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        if(pHead1==nullptr||pHead2==nullptr){
            return pHead1==nullptr?pHead2:pHead1;
        }
        ListNode*head;
        ListNode*tail;
        //1.对head和tail初始化
        if(pHead1->val<pHead2->val){
            head=tail=pHead1;
            pHead1=pHead1->next;
        }else{
            head=tail=pHead2;
            pHead2=pHead2->next;
        }
        //2.开始合并，循环控制条件为&&，有一个链表走完就结束
        while(pHead1&&pHead2){
            if(pHead1->val<pHead2->val){
                tail->next=pHead1;
                pHead1=pHead1->next;
            }else{
                tail->next=pHead2;
                pHead2=pHead2->next;
            }
            tail=tail->next;
        }
        //3.将剩下没走完的那个链表拿下来
        while(pHead1){
            tail->next=pHead1;
            pHead1=pHead1->next;
            tail=tail->next;
        }
        while(pHead2){
            tail->next=pHead2;
            pHead2=pHead2->next;
            tail=tail->next;
        }
        return head;
    }
};


class Solution {
public:
    ListNode* sortInList(ListNode* head) {
        if(head==nullptr||head->next==nullptr){
            return head;
        }
        ListNode*sorthead=head;//1
        ListNode*cur=head->next;//2
        sorthead->next=nullptr;//3
        while(cur){
            ListNode*next=cur->next;
            //头插
            if(cur->val<=sorthead->val){
                cur->next=sorthead;
                sorthead=cur;
            }else{
                ListNode*sortprev=sorthead;
                ListNode*sortcur=sorthead->next;
                //中间插
                while(sortcur){
                    if(cur->val<=sortcur->val){
                        sortprev->next=cur;
                        cur->next=sortcur;
                        break;
                    }else{
                        sortprev=sortcur;
                        sortcur=sortcur->next;
                    }
                }
                //尾插
                if(sortcur==nullptr){
                    sortprev->next=cur;
                    cur->next=nullptr;
                }
            }
            cur=next;
        }
        return sorthead;
    }
};

//计数器
int strlen1(const char*str){
    int count=0;
    while(*str){
        count++;
        str++;
    }
    return count;
}
//递归-不创建临时变量
int strlen2(const char*str){
    if(*str=='\0'){
        return 0;
    }else{
        return 1+strlen2(str+1);
    }
}
//指针-指针
int strlen3(const char*str){
    char*start=str;
    char*end=str;
    while(*end!='\0'){
        end++;
    }
    return end-start;
}