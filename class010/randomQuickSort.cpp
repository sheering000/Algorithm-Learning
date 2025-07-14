// 随机快速排序
#include <bits/stdc++.h>
using namespace std;

static int head,tail;
class Solution{
public:
    void randomQuickSort(vector<int>& nums){
        if(nums.empty()) return;
        randomQuickSort(nums,0,nums.size()-1);
    }

    void randomQuickSort(vector<int>& nums,int l,int r){
        if(l>=r) return;
        // 生成随机数
        // 使用随机排序的好处：在数组初始状态接近有序时节省时间
        random_device rd;
        mt19937_64 e(rd());
        uniform_int_distribution dis(l,r);

        // 写法1、2处理方式
        // int mid = partation(nums,l,r,nums[dis(e)]);
        // randomQuickSort(nums,l,mid-1);
        // randomQuickSort(nums,mid+1,r);

        // 写法3处理方式
        partationQuick(nums,l,r,nums[dis(e)]);
        int left = head-1;
        int right = tail+1;
        randomQuickSort(nums,l,left);
        randomQuickSort(nums,right,r);
    }

    int partation(vector<int>& nums,int l,int r,int randomVal){
        // 写法1
        // while(l<r){
        //     if(nums[l]>randomVal){
        //         swap(nums[l],nums[r]);
        //         --r;
        //     }else ++l;
        //     if(nums[r]<randomVal){
        //         swap(nums[l],nums[r]);
        //         ++l;
        //     }else --r;
        // }
        // return min(l,r);

        // 写法2 优点：避免边界检查
        int a=l,xi;
        for(int i=l;i<=r;++i){
            if(nums[i]<=randomVal){
                swap(nums[i],nums[a]);
                if(nums[a]==randomVal){
                    xi = a;
                }
                ++a;
            }
        }
        swap(nums[a-1],nums[xi]);
        return a-1;
    }

    // 写法3 优点：在有多个值=randomVal时节省时间
    void partationQuick(vector<int>& nums,int l,int r,int randomVal){
        head = l;
        tail = r;
        int i = l;
        while(i<=tail){
            if(nums[i]<randomVal){
                swap(nums[i++],nums[head++]);
            }else if(nums[i]>randomVal){
                swap(nums[i],nums[tail--]);
            }else ++i;
        }
    }
};

int main(){
    vector<int> arr = {3,3,1,2,5};
    Solution s;
    s.randomQuickSort(arr);
    for(auto it:arr){
        cout << it << ' ';
    }
    cout << '\n';
    return 0;
}