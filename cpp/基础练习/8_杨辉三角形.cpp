//
// Created by aria on 18-2-28.
//

/*
问题描述
        杨辉三角形又称Pascal三角形，它的第i+1行是(a+b)i的展开式的系数。

　　
它的一个重要性质是：三角形中的每个数字等于它两肩上的数字相加。

　　
下面给出了杨辉三角形的前4行：

　　
1

　　
1 1

　　
1 2 1

　　
1 3 3 1

　　
给出n，输出它的前n行。

输入格式
        输入包含一个数n。

输出格式
        输出杨辉三角形的前n行。每一行从这一行的第一个数开始依次输出，中间使用一个空格分隔。请不要在前面输出多余的空格。
样例输入
4
样例输出
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1
数据规模与约定
1 <= n <= 34。
*/

#include <iostream>
using namespace std;

int main(){
    int n,**arr;
    cin>>n;
    arr=new int*[n];
    for (int i = 0; i < n; ++i) {
        arr[i]=new int[i+1];
        for (int j = 0; j < i+1; ++j) {
            if(j==i||j==0)
                arr[i][j]=1;
            else
                arr[i][j]=arr[i-1][j]+arr[i-1][j-1];
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i <= k; ++i) {
            cout<<arr[k][i]<<' ';
        }
        cout<<endl;
    }
    return 0;
}