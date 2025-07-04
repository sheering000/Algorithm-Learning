// 任意进制整数转换为二进制
#include <iostream>
using namespace std;
const int M_bit = 8;

// 将任意进制整数转换为二进制输出
void IntToBinary(int x){
    if(x>255 || x<-256){
        cout << "数字越界" << '\n';
        return;
    }
    
    int b_x[M_bit];
    for(int i=0;i<M_bit;i++){
        b_x[i] = (int)(bool)(x&(1<<i));
    }
    cout << "整数" << x << "的二进制表示为：" << "0b";
    for(int i=M_bit-1;i>=0;i--){
        cout << b_x[i];
    }cout << '\n';
}

int main(){
    system("chcp 65001");

    IntToBinary(3);
    IntToBinary(0x1f);
    IntToBinary(0b00001111);

    system("pause");
    return 0;
}