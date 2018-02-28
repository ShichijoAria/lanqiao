//
// Created by aria on 18-2-27.
//
/*
 * 问题描述
　　从键盘输入一个不超过8位的正的十六进制数字符串，将它转换为正的十进制数后输出。
　　注：十六进制数中的10~15分别用大写的英文字母A、B、C、D、E、F表示。
样例输入
FFFF
样例输出
65535
*/

#include <iostream>
using namespace std;

long getDigit(char hexadecimal){
    if(hexadecimal>'9')
        return hexadecimal-'A'+10;
    else
        return hexadecimal-'0';
}

int main() {
    string octonary;
    long long sum=0;
    cin>>octonary;
    for (int i =0; i <octonary.length() ; ++i) {
        sum*=16;
        sum+=getDigit(octonary[i]);
    }
    cout<<sum;
    return 0;
}

/*
unsigned   int   0～4294967295
int   -2147483648～2147483647
unsigned long 0～4294967295
long   -2147483648～2147483647
long long的最大值：9223372036854775807
long long的最小值：-9223372036854775808
unsigned long long的最大值：1844674407370955161

__int64的最大值：9223372036854775807
__int64的最小值：-9223372036854775808
unsigned __int64的最大值：18446744073709551615*/
