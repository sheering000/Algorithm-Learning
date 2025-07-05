// 利用二分搜索，找无序且相邻元素不相等的数组中的峰值点
#include <bits/stdc++.h>
using namespace std;

#define mid(l,r) (int)(l+((r-l)>>1))

// 寻找数组中的一个峰值点
int FindOneMaxinum(const int (&arr)[],int l,int r){
    if(l==r) return arr[l];
    if(l+1==r) return max(arr[l], arr[r]);
    
    int mid = mid(l, r);
    if(arr[l+1]<arr[l]){
        return arr[l];
    }else if(arr[r-1]<arr[r]){
        return arr[r];
    }else if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
        return arr[mid];
    }else if(arr[mid]>arr[mid-1]){
        return FindOneMaxinum(arr,mid+1,r);
    }else return FindOneMaxinum(arr,l,mid-1);
}


int main(){
    int arr[6] = {1,4,5,3,6,1};
    cout << "Maxinum: " << FindOneMaxinum(arr,0,5) << endl;
    
    system("pause");
    return 0;
}