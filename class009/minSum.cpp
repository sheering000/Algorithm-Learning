// 归并分治--数组小和问题
// ∑n(i=1) fi (fi的定义是第 i 个数的左侧小于等于si的数的和)
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution{
public:
    vector<int> arr;
    Solution():arr(vector<int> {}){};
    Solution(vector<int>& arr):arr(arr){}
public:
    ll Merge(int l,int m,int r);
    ll R_minSum();
    ll R_minSum(int l,int r);

    // 暴力解法，做对数器
    ll Violent();
    ll Violent(int l,int r);
};

ll Solution::Merge(int l,int m,int r){
    ll ans = 0;
    for(int j=m+1,i=l,sum=0;j<=r;++j){
        while(i<=m&&arr[i]<=arr[j]){
            sum += arr[i++];
        }
        ans += sum;
    }
    return ans;
}

ll Solution::R_minSum(){
    int l=0;
    int r=arr.size()-1;
    return R_minSum(l,r);
}

ll Solution::R_minSum(int l,int r){
    if(l==r) return 0;
    int mid = l+((r-l)>>1);
    return R_minSum(l,mid)+R_minSum(mid+1,r)+Merge(l,mid,r);
}

ll Solution::Violent(){
    int l=0;
    int r=arr.size()-1;
    return Violent(l,r);
}

ll Solution::Violent(int l,int r){
    ll ans = 0;
    for(int i=l;i<=r;++i){
        for(int j=l;j<i;++j){
            if(arr[j]<=arr[i]){
                ans+=arr[j];
            }
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {4,5,7,1,5,9};
    Solution s(arr);
    cout << "Violent ans: " << s.Violent() << '\n';
    cout << "Recursion ans: " << s.R_minSum() << '\n';
    return 0;
}