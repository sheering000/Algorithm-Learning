// 两个链表相加
#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode():val(0),next(nullptr){};
    ListNode(int x):val(x),next(nullptr){};
    ListNode(int x,ListNode *next):val(x),next(next){};
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    if(!l1) return l2;
    if(!l2) return l1;

    ListNode *head = new ListNode(0);
    ListNode *cur = head;
    int carry = 0,sum = 0;

    while(l1||l2||carry){
        cur->next = new ListNode(0);
        cur = cur->next;
        if(l1){
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2){
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum/10;
        cur->val += sum%10;
        sum = carry;
    }

    return head->next;
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
    int num1[7] = {9,9,9,9,9,9,9};
    int num2[4] = {9,9,9,9};

    ListNode *l1 = newList(num1,7);
    ListNode *l2 = newList(num2,4);

    ListNode *head = addTwoNumbers(l1,l2);

    ListNode *cur = head;
    while(cur){
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << '\n';

    system("pause");
    return 0;
}