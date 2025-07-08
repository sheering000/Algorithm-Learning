// 栈
#include <bits/stdc++.h>
using namespace std;

// 1.用数组实现栈
class ArrayStack {
public:
    int *stk;
    int top = 0;
    ArrayStack(int n) {
        stk = new int[n];
    }

public:
    bool empty() {
        return top == 0;
    }

    int push_top(int x){
        stk[top++] = x;
        return x;
    }

    int get_top(){
        return stk[top-1];
    }

    int pop_top(){
        return stk[--top];
    }
};

// 2.用链表实现栈
class ListStack {
public:
    struct Node{
        int val;
        Node *next;
        Node():val(0),next(nullptr){};
        Node(int x):val(x),next(nullptr){};
        Node(int x,Node *next):val(x),next(next){};
    };

    Node *head = nullptr;

public:
    bool empty(){
        return head == nullptr;
    }

    int push_top(int x){
        Node *p = new Node(x);
        p->next = head;
        head = p;
        return x;
    }

    int get_top(){
        return head->val;
    }

    int pop_top(){
        int x = head->val;
        Node *p = head;
        head = head->next;
        delete p;
        return x;
    }   
};

int main(){
    int arr[5] = {5,4,3,2,1};
    ArrayStack arrstack(5);
    for(int i=0;i<5;i++){
        arrstack.push_top(arr[i]);
    }

    ListStack liststack;
    for(int i=0;i<5;i++){
        liststack.push_top(arr[i]);
    }

    cout << "ArrayStack: ";
    while(!arrstack.empty()){
        cout << arrstack.pop_top() << " ";
    }cout << endl;

    cout << "ListStack: ";
    while(!liststack.empty()){
        cout << liststack.pop_top() << " ";
    }cout << endl;

    system("pause");
    return 0;
}