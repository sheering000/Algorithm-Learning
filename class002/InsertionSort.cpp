// 插入排序
#include <iostream>
using namespace std;

// 插入排序，从小到大
// 时间复杂度：O(n^2)，空间复杂度：O(1)
// 插入排序的思路是：将未排序的元素插入到已排序的部分中，保持已排序部分的有序性
void InsertionSort(int (&arr)[],int l,int r){
    for(int i=l+1;i<=r;i++){
        int j = i;
        while(arr[j]<arr[j-1]&&j>l){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
}

int main(){
    int arr[5] = {64, 25, 12, 22, 11};
    InsertionSort(arr,0,4);
    for(int i=0;i<5;i++){
        cout << arr[i] << " ";
    }cout << endl;

    system("pause");
    return 0;
}