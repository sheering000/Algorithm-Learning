// 递归求数组的最大值
#include <bits/stdc++.h>
using namespace std;

int findMaxValue(int (&arr)[],int l,int r){
    if(l==r) return arr[l];
    return max(arr[r],findMaxValue(arr,l,r-1));
}

int main(){
    int arr[5] = {8,5,7,9,1};
    cout << "Max Value in arr is:" << findMaxValue(arr,0,4) << '\n';
    return 0;
}