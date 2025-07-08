// 环形队列
#include <bits/stdc++.h>
using namespace std;

// 用数组实现环形队列
class ArrCirQueue {
public:
    int *arr;
    int head = 0;
    int tail = 0;
    int size = 0;
    int limit = 0;
    ArrCirQueue(int limit) {
        arr = new int[limit];
        this->limit = limit;
    }

public:
    bool empty() {
        return size==0;
    }

    int push_back(int x){
        if(size==limit) return -1;
        arr[tail++] = x;
        tail %= limit;
        size++;
        return x;
    }

    int get_back(){
        if(size==0) return -1;
        return arr[(tail+limit-1)%limit];
    }

    int pop_head(){
        if(size==0) return -1;
        int x = arr[head];
        head = (head+1)%limit;
        size--;
        return x;
    }

    int get_head(){
        if(size==0) return -1;
        return arr[head];
    }
};

int main(){
    int arr[5] = {1,2,3,4,5};
    ArrCirQueue que(5);
    for(int i=0;i<5;i++){
        cout << que.push_back(arr[i]) << '\n';
    }
    
    que.pop_head();
    que.pop_head();

    que.push_back(6);

    while(!que.empty()){
        cout << que.pop_head() << " ";
    }
    cout << '\n';
    system("pause");
    return 0;
}