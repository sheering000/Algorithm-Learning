/// 堆排序
/// 堆结构：一个建立在数组上的二叉树
/// i结点的父亲的下标：(i-1)/2
/// i结点的左孩子：i*2+1
/// i结点的右孩子：i*2+2
#include <bits/stdc++.h>
using namespace std;

/// 大根堆(任意子树的最大值在root位置)
void HeapLarge(vector<int>& arr,int i){
    while(i&&arr[i]>arr[(i-1)>>1]){
        swap(arr[i],arr[(i-1)>>1]);
        i = (i-1)>>1;
    }
}

/// 小根堆(任意子树的最小值在root位置)
void HeapSmall(vector<int>& arr,int i){
    while(i&&arr[i]<arr[(i-1)>>1]){
        swap(arr[i],arr[(i-1)>>1]);
        i = (i-1)>>1;
    }
}

/// 大根堆排序,化为升序数组
void HeapSort(vector<int>& arr,int tail){
    while(tail>0){
        swap(arr[0],arr[tail]);
        int i=0,under_pos;
        while(i*2+1<tail){
            under_pos = (i*2+2<tail&&arr[i*2+2]>arr[i*2+1])?i*2+2:i*2+1;
            if(arr[i]<arr[under_pos]){
                swap(arr[i],arr[under_pos]);
                i = under_pos;
            }else{
                break;
            }
        }
        --tail;
    }
}


/// 随机生成数组
vector<int> randomArr(){
    vector<int> arr;
    random_device rd;
    mt19937_64 e(rd());
    uniform_int_distribution dis(1,100);
    uniform_int_distribution dis_size(1,20);
    int size = dis_size(e);
    for(int i=0;i<=size;++i){
        arr.push_back(dis(e));
    }

    return arr;
}

int main(){
    for(int i=0;i<10;++i){
        vector<int> arr = randomArr();
        int size = arr.size();

        // 先将数组化为大根堆
        for(int j=0;j<size;++j){
            HeapLarge(arr,j);
        }

        // 再调用堆排序
        HeapSort(arr,size-1);


        // 输出排序后的数组
        cout << "[ ";
        auto it = arr.begin();
        for(;it!=arr.end()-1;++it){
            cout << *it << ',';
        }
        cout << *it << " ]\n";
    }

    return 0;
}