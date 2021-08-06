class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode*lesshead,*lesstail;
        ListNode*greaterhead,*greatertail;
        lesshead=lesstail=new ListNode(0);
        greaterhead=greatertail=new ListNode(0);
        ListNode*cur=head;
        while(cur!=nullptr){
            if(cur->val<x){
                lesstail->next=cur;
                lesstail=lesstail->next;
                cur=cur->next;
            }
            else{
                greatertail->next=cur;
                greatertail=greatertail->next;
                cur=cur->next;
            }
        }
        greatertail->next=nullptr;
        lesstail->next=greaterhead->next;
        return lesshead->next;
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

class Singleton{
private:
    static int data;
public:
    int*getInstance(){
        return &data;
    }
}


#include<iostream>
#include<mutex>
using namespace std;
template<class T>
class Singleton{
private:
    volatile static T *data;
    static mutex _mutex;
public:
    T*getInstance(){
        if(data==nullptr){
            _mutex.lock();
            if(data==nullptr){
                data=new T();
            }
            _mutex.unlock();
        }
        return data;
    }
}