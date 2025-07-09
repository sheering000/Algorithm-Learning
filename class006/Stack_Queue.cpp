// 栈和队列互相实现
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *next;
    Node():val(0),next(nullptr){};
    Node(int x):val(x),next(nullptr){};
    Node(int x,Node *next):val(x),next(next){};
};

// 栈的实现
class Stack{
private:
    Node *head;

public:
    Stack():head(nullptr){};

    bool empty(){
        return head == nullptr;
    }

    void push(int x){
        Node *p = new Node(x);
        p->next = head;
        head = p;
    }

    int pop(){
        if(empty()) return -1;
        
        int x = head->val;
        Node *p = head;
        head = head->next;
        delete p;
        p = nullptr;
        return x;
    }

    int top(){
        return (empty())?-1:head->val;
    }

    int size(){
        Node *p = head;
        int cnt = 0;
        while(p){
            cnt++;
            p = p->next;
        }
        return cnt;
    }
};

// 队列的实现
class Queue{
private:
    Node *head,*tail;

public:
    Queue():head(nullptr),tail(nullptr){};

    bool empty(){
        if(head==nullptr){
            delete head;
            tail = nullptr;
            return true;
        }
        return false;
    }

    void push(int x){
        if(empty()){
            tail = new Node(x);
            head = tail;           
            return;
        }
        tail->next = new Node(x);
        tail = tail->next;
    }

    int pop(){
        if(empty()) return -1;
        int x = head->val;
        Node *p = head;
        head = head->next;
        delete p;
        p = nullptr;
        return x;
    }

    int top(){
        return (empty())?-1:head->val;
    }

    int size(){
        Node *p = head;
        int cnt = 0;
        while(p){
            cnt++;
            p = p->next;
        }
        return cnt;
    }
};

// 用栈实现队列
class sQueue{
private:
    Stack in,out;

    // O(1)
    void InToOut(){
        if(out.empty()){
            while(!in.empty()){
                out.push(in.pop());
            }
        }
    }

public:
    sQueue():in(),out(){};
    bool empty(){
        return in.empty() && out.empty();
    }
    
    // O(1)
    void push(int x){
        in.push(x);
        InToOut();
    }
    
    // O(1)
    int pop(){
        InToOut();
        return out.pop();
    }

    // O(1)
    int top(){
        InToOut();
        return out.top();
    }

    int size(){
        return in.size() + out.size();
    }
};

// 用队列实现栈
class qStack{
private:
    Queue que;

    // O(n)
    void HeadToTail(){
        for(int i=0;i<que.size()-1;i++){
            que.push(que.pop());
        }
    }

public:
    qStack():que(){};

    bool empty(){
        return que.empty();
    }

    // O(n)
    void push(int x){
        que.push(x);
        HeadToTail();
    }

    // O(1)
    int pop(){
        return que.pop();
    }

    // O(1)
    int top(){
        return que.top();
    }

    int size(){
        return que.size();
    }
};

void StackToQueue(){
    int arr1[5] = {1,2,3,4,5};
    int arr2[3] = {6,7,8};

    sQueue que1;
    for(int i=0;i<5;i++){
        que1.push(arr1[i]);
    }

    cout << "pop1:" << que1.pop() << '\n';
    cout << "pop2:" << que1.pop() << '\n';

    for(int i=0;i<3;i++){
        que1.push(arr2[i]);
    }

    while(!que1.empty()){
        cout << que1.pop() << " ";
    }
    cout << '\n';
}

void QueueToStack(){
    int arr1[5] = {1,2,3,4,5};
    int arr2[3] = {6,7,8};

    qStack stk1;
    for(int i=0;i<5;i++){
        stk1.push(arr1[i]);
    }

    cout << "pop1:" << stk1.pop() << '\n';
    cout << "pop2:" << stk1.pop() << '\n';

    for(int i=0;i<3;i++){
        stk1.push(arr2[i]);
    }

    while(!stk1.empty()){
        cout << stk1.pop() << " ";
    }
    cout << '\n';
}

void buildQueue(){
    int arr[5] = {1,2,3,4,5};
    Queue que;
    for(int i=0;i<5;i++){
        que.push(arr[i]);
    }

    while(!que.empty()){
        cout << que.pop() << " ";
    }
    cout << '\n';
}

int main(){
    StackToQueue();
    
    QueueToStack();

    //buildQueue();

    system("pause");
    return 0;
}