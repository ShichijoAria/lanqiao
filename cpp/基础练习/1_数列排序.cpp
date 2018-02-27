/*
问题描述
　　给定一个长度为n的数列，将这个数列按从小到大的顺序排列。1<=n<=200
输入格式
　　第一行为一个整数n。
　　第二行包含n个整数，为待排序的数，每个整数的绝对值小于10000。
输出格式
　　输出一行，按从小到大的顺序输出排序后的数列。
样例输入
5
8 3 6 4 9
样例输出
3 4 6 8 9*/

#include <iostream>
#include <algorithm>//头文件<algorithm>定义了专门用于元素范围的函数集合。
using namespace std;

//接受范围中的两个元素作为参数的二元函数，并返回一个可转换为bool的值。
bool comp(int a, int b){
    return a<b;
}

void swap(int &a,int &b){
    int t=a;
    a=b;
    b=t;
}

//复习了下冒泡排序 这里用不到
void bubbleSort(int a[],int n){
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j <n; ++j) {
            int t=a[i];
            if(a[i]>a[j])
                swap(a[i],a[j]);
        }
    }
}

void traverse(int a[],int n){
    for (int i = 0; i < n; ++i) {
        cout<<a[i]<<" ";//这里不输出空格还会判错
    }
}

int main() {
    int *a,n;
    cin>>n;
    a=new int[n];
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    sort(a,a+n,comp);
    traverse(a,n);
    return 0;
}