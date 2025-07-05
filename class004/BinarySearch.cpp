// 二分搜索
#include <bits/stdc++.h>
using namespace std;

// #define mid(l,r) (int)((l+r)>>1) 当数组较大时，l+r可能会溢出，导致mid为负数
#define mid(l,r) (int)(l+((r-l)>>1))

// 搜索数字是否在有序数组中
bool FindNum(const int (&arr)[],int l,int r,int num){
    if(l>r) return false;
    int mid = mid(l,r);
    if(arr[mid] == num) return true;
    else if(arr[mid]>num) return FindNum(arr,l,mid-1,num); // num<中点值，说明在左半部分
    else return FindNum(arr,mid+1,r,num); // num>中点值，说明在右半部分
}

// 寻找数组中>=num的最左位置
int FindLeftMost(const int (&arr)[],int l,int r,int num){
    if(l>r) return -1;
    int mid = mid(l,r);
    if(arr[mid]>=num){
        int left = FindLeftMost(arr,l,mid-1,num);
        return left==-1 ? mid : left;
    }else return FindLeftMost(arr,mid+1,r,num);
}

// 寻找数组中<=num的最右位置
int FindRightMost(const int (&arr)[],int l,int r,int num){
    if(l>r) return -1;
    int mid = mid(l,r);
    if(arr[mid]<=num){
        int right = FindRightMost(arr,mid+1,r,num);
        return right==-1 ? mid : right;
    }else return FindRightMost(arr,l,mid-1,num);
}

int main(){
    int arr[6] = {1,4,7,11,58,97};
    int num1 = 45;
    
    if(FindNum(arr,0,5,num1)){
        cout << "Found " << num1 << " in the array." << endl;
    } else {
        cout << "Did not find " << num1 << " in the array." << endl;
    }

    int num2 = 97;
    int pos = FindLeftMost(arr,0,5,num2);
    if(pos!=-1){
        cout << "Found the leftmost position of " << num2 << " in the key " << pos << endl;
    } else {
        cout << "Did not find any position for " << num2 << " in the array." << endl;
    }

    int num3 = 1;
    pos = FindRightMost(arr,0,5,num3);
    if(pos!=-1){
        cout << "Found the rightmost position of " << num3 << " in the key " << pos << endl;
    } else {
        cout << "Did not find any position for " << num3 << " in the array." << endl;
    }

    system("pause");
    return 0;
}