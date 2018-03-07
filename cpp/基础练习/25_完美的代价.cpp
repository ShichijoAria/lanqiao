//
// Created by aria on 18-3-4.
//

/*问题描述
　　回文串，是一种特殊的字符串，它从左往右读和从右往左读是一样的。小龙龙认为回文串才是完美的。现在给你一个串，它不一定是回文的，请你计算最少的交换次数使得该串变成一个完美的回文串。
　　交换的定义是：交换两个相邻的字符
　　例如mamad
　　第一次交换 ad : mamda
　　第二次交换 md : madma
　　第三次交换 ma : madam (回文！完美！)
输入格式
　　第一行是一个整数N，表示接下来的字符串的长度(N <= 8000)
　　第二行是一个字符串，长度为N.只包含小写字母
输出格式
　　如果可能，输出最少的交换次数。
　　否则输出Impossible
样例输入
5
mamad
样例输出
3*/


#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int j = n - 1;
    int cnt = 0;//cnt用来统计交换的次数
    int flag = 0;//flag判断是否已经有一个单独的奇个数的字符了
    for(int i = 0; i < j; i++) {//i指针从头遍历到倒数第二个字符
        for(int k = j; k >= i; k--) {//k指针从后面往前一直到i寻找和s[i]相同的s[k]
            if(k == i) {//如果找不到相同的
                if(n % 2 == 0 || flag == 1) {//impossible的两种情况
                    cout << "Impossible";
                    return 0;
                }
                flag = 1;
                cnt += n / 2 - i;
            } else if(s[k] == s[i]) {
                for(int l = k; l < j; l++) {
                    swap(s[l], s[l+1]);//把s[k]换到s[j]处
                    cnt++;//统计交换次数
                }
                j--;
                break;
            }
        }
    }
    cout << cnt;
    return 0;
}