// 归并分治--翻转对数量问题
// 给定一个数组 nums ，如果 i < j 且 nums[i] > 2*nums[j] 我们就将 (i, j) 称作一个重要翻转对
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution{
public:
    vector<int> arr;
    Solution():arr(vector<int> {}){}
    Solution(vector<int>& arr):arr(arr){}
public:
    int Merge(int l,int m,int r);
    int R_reverseCount();
    int R_reverseCount(int l,int r);

    // 暴力解法
    int Violent();
    int Violent(int l,int r);
};


int Solution::Merge(int l,int m,int r){
    int ans = 0;
    for(int j=m+1,i=l,sum=0;j<=r;++j){
        while(i<=m&&(ll)arr[i]>(ll)arr[j]*2){
            sum++;
            i++;
        }
        ans += sum;
    }
    // 将归并完的部分降序排列
    vector<int> part;
    int lpos=l,rpos=m+1;
    while(lpos<=m&&rpos<=r){
        if(arr[lpos]>arr[rpos]) part.push_back(arr[lpos++]);
        else part.push_back(arr[rpos++]);
    }
    while(lpos<=m) part.push_back(arr[lpos++]);
    while(rpos<=r) part.push_back(arr[rpos++]);
    while(r>=l){
        arr[r--] = part.back();
        part.pop_back();
    }
    return ans;
}

int Solution::R_reverseCount(){
    int l = 0;
    int r = arr.size()-1;
    return R_reverseCount(l,r);
}

int Solution::R_reverseCount(int l,int r){
    if(l==r) return 0;
    int mid = l+((r-l)>>1);
    return R_reverseCount(l,mid)+R_reverseCount(mid+1,r)+Merge(l,mid,r);
}

int Solution::Violent(){
    int l = 0;
    int r = arr.size()-1;
    return Violent(l,r);
}

int Solution::Violent(int l,int r){
    int ans = 0;
    for(int i=l;i<=r;++i){
        for(int j=l;j<i;++j){
            if(arr[j]>arr[i]*2){
                ans++;
                // cout << arr[j] << '\n';
            }
        }
    }
    return ans;
}

vector<int> randomArray(){
    vector<int> arr;
    
    random_device rd;

    mt19937_64 e(rd());
    uniform_int_distribution<int> dis(-0x3f3f3f,0x3f3f3f3f);
    uniform_int_distribution<int> dis_size(1,50000);
    int size = dis_size(e);

    while(size){
        arr.push_back(dis(e));
        size--;
    }
    return arr;
}


vector<vector<int>> Verify(int testnum){
    vector<vector<int>> err;
    for(int i=0;i<testnum;++i){
        vector<int> arr = randomArray();
        Solution s(arr);
        ll ans1 = s.Violent();
        ll ans2 = s.R_reverseCount();
        if(ans1!=ans2){
            err.push_back(arr);
            cout << "Wrong res,times " << err.size() << '\n';

        }
    }
    if(err.empty()){
        cout << "All tests passed successfully!\n";
    }
    return err;
}


int main(){
    // vector<int> arr = {1,3,2,3,1};
    // Solution s(arr);
    // cout << s.Violent() << " " << s.R_reverseCount() << '\n';
    Verify(10);
    return 0;
}