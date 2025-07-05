// 3种简单排序算法——冒泡排序
#include <bits/stdc++.h>
using namespace std;

// 冒泡排序，从小到大
// 时间复杂度：O(n^2)，空间复杂度：O(1)
// 冒泡排序的思路是：每次比较相邻的元素，如果它们的顺序错误就交换它们，直到没有需要交换的元素为止
void BubbleSort(int (&arr)[],int l,int r){
    for(int i=r;i>l;i--){
        for(int j=l;j<i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main(){
    int arr[5] = {64, 25, 12, 22, 11};
    BubbleSort(arr,0,4);
    for(int i=0;i<5;i++){
        cout << arr[i] << " ";
    }cout << endl;

    system("pause");
    return 0;
}