// 划分链表，将链表中的值小于x的节点放在前面，大于等于x的节点放在后面
#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode():val(0),next(nullptr){};
    ListNode(int x):val(x),next(nullptr){};
    ListNode(int x,ListNode *next):val(x),next(next){};
};

ListNode *partitionList(ListNode *head,int x){
    ListNode *lefthead = nullptr,*lefttail = nullptr,
             *righthead = nullptr,*righttail = nullptr;
    
    while(head){
        if(head->val<x){
            if(lefthead==nullptr){
                lefthead = head;
            }else{
                lefttail->next = head;
            }
            lefttail = head;
        }else{
            if(righthead==nullptr){
                righthead = head;
            }else{
                righttail->next = head;
            }
            righttail = head;
        }
        head = head->next;
    }
    if(lefthead==nullptr) return righthead;
    if(righthead==nullptr) return lefthead;
    lefttail->next = righthead;
    righttail->next = nullptr;
    return lefthead;
}

ListNode* newList(int num[],int n){
    if(n==0) return nullptr;

    ListNode *head = new ListNode(num[0]);
    ListNode *cur = head;
    for(int i=1;i<n;i++){
        cur->next = new ListNode(num[i]);
        cur = cur->next;
    }
    cur = nullptr;
    return head;
}

int main(){
    int list[7] = {6,5,3,1,2,4,7};
    ListNode *head = newList(list,7);
    ListNode *head1 = partitionList(head,3);
    ListNode *cur = head1;
    while(cur){
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << '\n';

    system("pause");
    return 0;
}