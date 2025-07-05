// 对数器——用于验证算法的正确性
// 通过随机数据组在暴力解算法和高效解算法之间进行对比，验证高效解算法的正确性
// 以插入排序算法为例
#include <iostream>
#include <random>
// #include <ctime>
using namespace std;

#define ArraySize(arr) (arr[0]+1)
const int MAX_SIZE = 10;

// 插入排序解
int* InsertionSort(int arr[],int size){
    int l = 1;
    int r = size - 1;
    for(int i=l+1;i<=r;i++){
        int j = i;
        while(arr[j]<arr[j-1]&&j>l){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
    return arr;
}

// 暴力解
int* ViolentSort(int arr[],int size){
    int l = 1;
    int r = size - 1;
    for(int i=l;i<r;i++){
        for(int j=i+1;j<=r;j++){
            if(arr[j]<arr[i]){
                swap(arr[i],arr[j]);
            }
        }
    }
    return arr;
}

// 随机数组生成器
int* RandomArray(int min,int max){
    random_device rd;
    // 使用随机数引擎生成随机数
    mt19937_64 e(rd());
    uniform_int_distribution<int> dis(min, max);
    uniform_int_distribution<int> dis_size(1, MAX_SIZE);

    int size = (dis_size(e) % MAX_SIZE) + 1; // 生成随机大小，确保至少有一个元素
    int* arr = new int[size+1]; // 动态分配数组
    arr[0] = size;
    for(int i = 1; i <= size; i++){
        arr[i] = dis(e); // 生成随机数
    }
    return arr;
}

int main(){
    int testCount = 10;
    int flag_all = 1;
    for(int i=0;i<testCount;i++){
        int* arr = RandomArray(0,(int)1e6+10);
        int arr1[ArraySize(arr)],arr2[ArraySize(arr)];
        for(int j=0;j<ArraySize(arr);j++){
            arr1[j] = arr[j];
            arr2[j] = arr[j];
        }
        
        int *ans1 = ViolentSort(arr1, ArraySize(arr1));
        int *ans2 = InsertionSort(arr2, ArraySize(arr2));

        int flag_each = 1;
        for(int j=1;j<ArraySize(arr);j++){
            if(ans1[j] != ans2[j]){
                flag_each = 0;
                break;
            }
        }

        if(!flag_each){
            cout << "Test failed at iteration " << i+1 << '\n';
            flag_all = 0;
            cout << "The wrong example is:\n";
            for(int j=1;j<ArraySize(arr);j++){
                cout << arr[j] << " ";
            }cout << '\n';

            cout << "Violent Sort Result:\n";
            for(int j=1;j<ArraySize(ans1);j++){
                cout << ans1[j] << " ";
            }cout << '\n';

            cout << "Insertion Sort Result:\n";
            for(int j=1;j<ArraySize(ans2);j++){
                cout << ans2[j] << " ";
            }cout << '\n';
        }
        delete[] arr;
        arr = NULL;
    }

    if(flag_all) cout << "All tests passed successfully!\n";


    system("pause");
    return 0;
}