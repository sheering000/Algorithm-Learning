// 3种简单排序算法——选择排序
#include <bits/stdc++.h>
using namespace std;

// 选择排序，从小到大
// 时间复杂度：O(n^2)，空间复杂度：O(1)
// 选择排序的思路是：每次从未排序的部分中选择最小（或最大）的元素，将其放到已排序部分的末尾
void selectionSort(int (&arr)[],int l,int r){
    for(int i=l;i<r;i++){
        int minIndex = i;
        for(int j=i+1;j<=r;j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i],arr[minIndex]);
    }
}

int main(){
    int arr[5] = {64, 25, 12, 22, 11};
    selectionSort(arr,0,4);
    for(int i=0;i<5;i++){
        cout << arr[i] << " ";
    }cout << endl;

    system("pause");
    return 0;
}