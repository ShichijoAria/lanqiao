/*
问题描述
        给定圆的半径r，求圆的面积。
输入格式
        输入包含一个整数r，表示圆的半径。
输出格式
        输出一行，包含一个实数，四舍五入保留小数点后7位，表示圆的面积。


*/

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
    double PI=atan(1.0)*4;
    double r;
    cin>>r;
    cout<<setiosflags(ios::fixed)<<setprecision(7)<<PI*r*r;//需要头文件#include <iomanip>
}