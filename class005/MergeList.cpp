// 合并两个有序链表
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *pre = NULL;
    Node *next = NULL;
    Node(int data = 0):data(data){}
};

// 创建一个链表
Node* newList(int num[],int n){
    if(n==0) return NULL;
    
    Node *head = new Node(num[0]);
    Node *cur = head;
    for(int i=1;i<n;i++){
        cur->next = new Node(num[i]);
        cur->next->pre = cur;
        cur = cur->next;
    }
    cur = NULL;
    return head;
}

Node* mergeList(Node *head1,Node *head2){
    if(head1 == NULL && head2 == NULL) return NULL;
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;
    
    Node *cur1 = head1;
    Node *cur2 = head2;
    Node *head;
    if(cur1->data<=cur2->data){
        head = cur1;
        cur1 = cur1->next;
    }else{
        head = cur2;
        cur2 = cur2->next;
    }

    Node *cur = head;
    while(cur1 != NULL && cur2 != NULL){
        if(cur1->data<=cur2->data){
            cur->next = cur1;
            cur1->pre = cur;
            cur1 = cur1->next;
        }else{
            cur->next = cur2;
            cur2->pre = cur;
            cur2 = cur2->next;
        }
        cur = cur->next;
    }

    if(cur1 != NULL){
        cur->next = cur1;
        cur1->pre = cur;
    }else{
        cur->next = cur2;
        cur2->pre = cur;
    }
    return head;
}

int main(){
    int num1[4] = {1,2,3,4};
    int num2[3] = {2,5,6};

    Node *head1 = newList(num1,4);
    Node *head2 = newList(num2,3);

    Node *head = mergeList(head1,head2);

    Node *cur = head;
    while(cur != NULL){
        cout << cur->data << " ";
        cur = cur->next;
    }


    system("pause");
    return 0;
}