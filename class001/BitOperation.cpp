// 二进制位运算
// 二进制（以4位为例）：
//   正数：从右到左，2的0次方、2的1次方、2的2次方……，最高位为0
//   负数：从右到左，2的0次方、2的1次方、2的2次方……，最高位为1
#include <iostream>
using namespace std;

bool returnTrue() {cout << "Func returnTrue run" << '\n';return true;}
bool returnFalse() {cout << "Func returnFalse run" << '\n';return false;}

int main(){
    system("chcp 65001");
    int x = 9;
    // 十六进制
    cout << "十六进制x = " << hex << x << dec << '\n';
    
    // 任意进制下，任意整数的相反数=原数取反+1
    cout << "x的取反为" << ~x << '\n';
    cout << "x的相反数为" << (~x + 1) << '\n';
    
    int g = 0b00001100;
    int h = 0b00001010;
    // |（或）运算符：有1为1
    cout << (g|h) << '\n';

    // &（与）运算符：有0为0
    cout << (g&h) << '\n';

    // ^（异或）运算符：相反为1，相同为0
    cout << (g^h) << '\n';


    // 按位运算与逻辑运算的区别
    // 位运算时，两项都进行计算
    cout << (bool)(returnTrue()|returnFalse()) << '\n';
    cout << (bool)(returnTrue()&returnFalse()) << '\n';
    cout << (bool)(returnFalse()&returnTrue()) << '\n';
    // 逻辑运算时，从左向右，若能够确定结果，则不再计算后续项
    cout << (bool)(returnTrue()||returnFalse()) << '\n';    // returnTrue()返回true，returnFalse()不再执行
    cout << (bool)(returnTrue()&&returnFalse()) << '\n';    // returnTrue()和returnFalse()都执行
    cout << (bool)(returnFalse()&&returnTrue()) << '\n';    // returnFalse()返回false，returnTrue()不再执行


    // 左移和右移
    cout << (g<<1) << '\n';  // 非负数，左移1位，相当于乘以2^1
    cout << (g<<2) << '\n';  // 非负数，左移2位，相当于乘以2^2

    cout << (g>>1) << '\n';  // 非负数右移1位，相当于除以2^1
    int i = -g;
    cout << i << '\n';  // 输出负数
    cout << (i>>1) << '\n';  // 负数右移时，符号位不变（即最高位仍为1）


    system("pause");
    return 0;
}