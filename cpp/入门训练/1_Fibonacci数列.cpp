/*
问题描述
        Fibonacci数列的递推公式为：Fn=Fn-1+Fn-2，其中F1=F2=1。

当n比较大时，Fn也非常大，现在我们想知道，Fn除以10007的余数是多少。

输入格式
        输入包含一个整数n。
输出格式
        输出一行，包含一个整数，表示Fn除以10007的余数。*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int f1=1,f2=1;
    if(n<3)
    {
        cout << 1;
        return 0;
    }
    else
    {
        for (int i = 2; i < n; ++i)
        {
            int t = f2;
            f2 = (f2+f1);
            f1 = t;
            f1%=10007;
            f2%=10007;
        }
        cout<<f2;
    }
    return 0;
}
