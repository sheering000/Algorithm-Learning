// 队列
#include <bits/stdc++.h>
using namespace std;

const int int_M = 0x3f3f3f3f;

// 1.用数组实现队列
class ArrayQueue {
public:
    int *queue;
    int head = 0;
    int tail = 0;
    int limit = 0;

    ArrayQueue(int n){
        queue = new int[n];
        limit = n;
    }

public:
    bool empty(){
        return head == tail;
    }

    // 添加队列尾的元素并返回
    int push_back(int x){
        if(tail==limit){
            return -1;
        }        
        queue[tail++] = x;
        return x;
    }

    // 返回队列尾的元素
    int get_back(){
        return queue[tail-1];
    }

    // 返回队列头元素并删除
    int pop_head(){
        if(empty()) return -1;
        return queue[head++];
    }

    // 返回队列头的元素但不弹出
    int get_head(){
        if(empty()) return -1;
        return queue[head];
    }

};

// 2.用链表实现队列
class ListQueue {
public:
    struct Node{
        int val;
        Node *next;
        Node():val(0),next(nullptr){};
        Node(int x):val(x),next(nullptr){};
        Node(int x,Node *next):val(x),next(next){};
    };

    Node *head = nullptr;
    Node *tail = nullptr;

public:
    ListQueue():head(nullptr),tail(nullptr){};
    ListQueue(int (&arr)[],int n){
        head = new Node(arr[0]);
        tail = head;
        for(int i=1;i<n;i++){
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
    }

public:
    bool empty(){
        return head == nullptr;
    }

    // 添加队列尾的元素并返回
    int push_back(int x){
        Node *p = new Node(x);
        if(head == nullptr) head = p;
        else tail->next = p;
        tail = p;
        return x;
    }

    // 返回队列尾的元素
    int get_back(){
        if(empty()) return -1;
        return tail->val;
    }

    // 返回队列头元素并删除
    int pop_head(){
        if(empty()) return -1;
        int x = head->val;
        Node *p = head;
        head = head->next;
        delete p;
        return x;
    }

    // 返回队列头的元素但不弹出
    int get_head(){
        if(empty()) return -1;
        return head->val;
    }
};

int main(){
    int arr[5] = {5,4,3,2,1};
    ListQueue que(arr,5);
    while(!que.empty()){
        cout << que.pop_head() << " ";
    }
    cout << que.pop_head();
    cout << '\n';

    int arr2[7] = {1,2,3,4,5,6,7};
    ArrayQueue que2(7);
    for(int i=0;i<7;i++){
        que2.push_back(arr2[i]);
    }
    que2.pop_head();
    que2.push_back(8);
    while(!que2.empty()){
        cout << que2.pop_head() << " ";
    }
    cout << '\n';

    system("pause");
    return 0;
}