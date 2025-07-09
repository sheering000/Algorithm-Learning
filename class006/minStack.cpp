// 最小栈
#include <bits/stdc++.h>
using namespace std;

// 1.用链表实现
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

    void pop(){
        if(empty()) return;
        
        Node *p = head;
        head = head->next;
        delete p;
        p = nullptr;
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

class MinStack1{
public:
    Stack data,minVal;

public:
    bool empty(){
        return data.empty();
    }

    void push(int x){
        data.push(x);
        if(minVal.empty()){
            minVal.push(x);
            return;
        }
        minVal.push(min(minVal.top(),x));
    }

    void pop(){
        data.pop();
        minVal.pop();
    }

    int top(){
        return data.top();
    }

    int getMin(){
        return minVal.top();
    }

    int size(){
        return data.size();
    }
};


// 2.用数组实现
class MinStack2{
private:
    vector<int> data;
    vector<int> minVal;
public:
    bool empty(){
        return data.empty();
    }

    void push(int x){
        data.push_back(x);
        if(minVal.empty()){
            minVal.push_back(x);
            return;
        }
        minVal.push_back(min(minVal.back(),x));
    }

    void pop(){
        if(empty()) return;      
        data.pop_back();
        minVal.pop_back();
    }

    int top(){
        if(empty()) return -1;
        return data.back();
    }

    int getMin(){
        if(empty()) return -1;
        return minVal.back();
    }

    int size(){
        return data.size();
    }
};