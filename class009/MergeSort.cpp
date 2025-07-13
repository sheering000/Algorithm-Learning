// 归并排序
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int *arr;
    Solution(int arr[]):arr(arr){}
public:
    // 递归解法，额外空间复杂度O(n) 时间复杂度O(n*logn)
    int* RecursionSort(int l,int r){
        if(l==r) return arr+l;
        int mid = l+((r-l)>>1);
        int size_l = mid-l+1;
        int size_r = r-mid+1;
        int *part = new int[r-l+1];
        int *part_l = RecursionSort(l,mid);
        int *part_r = RecursionSort(mid+1,r);
        
        // 合并两个有序数组过程
        int lpos=0,rpos=0,pos=0;
        while(lpos<size_l&&rpos<size_r){
            if(part_l[lpos]<part_r[rpos]){
                part[pos] = part_l[lpos++];
            }else{
                part[pos] = part_r[rpos++];
            }
            pos++;
        }
        if(lpos<size_l){
            while(lpos<size_l) part[pos++] = part_l[lpos++];
        }
        if(rpos<size_r){
            while(rpos<size_r) part[pos++] = part_r[rpos++];
        }
        return part;
    }

    // 非递归解法
    int* nonRecursionSort(int l,int r){
        int lpos,rpos,pos;
        int *part = nullptr;
        for(int step=1;step<r-l+1;step*=2){
            for(int i=0;l+step*i*2<=r;++i){
                lpos = l+step*i*2;
                rpos = l+step*(i*2+1);
                pos = 0;
                part = new int[step*2];
                while(lpos<l+step*(i*2+1)&&rpos<l+step*(i+1)*2&&rpos<=r){
                    if(arr[lpos]<arr[rpos]){
                        part[pos++] = arr[lpos++];
                    }else{
                        part[pos++] = arr[rpos++];
                    }
                }
                if(lpos<l+step*(i*2+1)){
                    while(lpos<l+step*(i*2+1)&&lpos<=r) part[pos++] = arr[lpos++];
                }
                if(rpos<l+step*(i+1)*2){
                    while(rpos<l+step*(i+1)*2&&rpos<=r) part[pos++] = arr[rpos++];
                }
                for(int j=0;j<pos;++j){
                    arr[l+step*i*2+j] = part[j];
                }
                delete[] part;
                part = nullptr;
            }

        }
        return arr;
    }
};

void example1(){
    int arr[6] = {4,2,6,4,3,9};
    Solution q1(arr);
    int *ans1 = q1.RecursionSort(0,5);
    for(int i=0;i<6;++i){
        cout << *ans1++ << " ";
    }
    cout << '\n';

    Solution q2(arr);
    int *ans2 = q2.nonRecursionSort(0,5);
    for(int i=0;i<6;++i){
        cout << *ans2++ << " ";
    }
    cout << '\n';
}

int main(){
    example1();
    return 0;
}