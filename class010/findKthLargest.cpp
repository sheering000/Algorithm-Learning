// 寻找数组中第K大的数
#include <bits/stdc++.h>
using namespace std;

vector<int> nums = {2,1,8,74,9,6,2,3,0,11};
static int head,tail;
int findVal(int l,int r,int target){
    random_device rd;
    mt19937_64 e(rd());
    uniform_int_distribution dis(l,r);

    int x = nums[dis(e)];

    int i=l;
    head=l;tail=r;
    while(i<=tail){
        if(nums[i]>x) swap(nums[i++],nums[head++]);
        else if(nums[i]<x) swap(nums[i],nums[tail--]);
        else ++i;
    }
    if(target-1>=head&&target-1<=tail) return x;
    else if(target-1<head) return findVal(l,head-1,target);
    else return findVal(tail+1,r,target);
}

int main(){
    cout << findVal(0,9,2) << '\n';
    return 0;
}