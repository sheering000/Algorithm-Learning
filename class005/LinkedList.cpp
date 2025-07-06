// 初识链表
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *pre = NULL;
    Node *next = NULL;
public:
    Node(int data = 0):data(data){};

    // 在尾部插入
    Node* push_back(int data=0){
        Node *p = new Node(data);
        this->next = p;
        p->pre = this;
        return this;
    }
    
    // 找链表首结点
    Node* head(){
        if(this->pre == NULL) return this;
        return this->pre->head();
    }

    // 提供成员函数反转链表
    Node* reverse(){
        Node *cur = this->head();

        while(cur->next != NULL){
            Node *p = cur->next;
            cur->next = cur->pre;
            cur->pre = p;
            cur = cur->pre;
        }
        // 尾处理
        cur->next = cur->pre;
        cur->pre = NULL;

        return cur;
    }
};

int main(){
    Node *head = new Node();
    Node *cur = head;
    for(int i=1;i<6;i++){
        cur = cur->push_back(i)->next;
    }

    head->next->next->reverse();

    cur = head->head();
    while(cur != NULL){
        cout << cur->data << " ";
        cur = cur->next;
    }


    system("pause");
    return 0;
}