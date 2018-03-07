//
// Created by aria on 18-3-4.
//

/*问题描述
　　回形取数就是沿矩阵的边取数，若当前方向上无数可取或已经取过，则左转90度。一开始位于矩阵左上角，方向向下。
输入格式
　　输入第一行是两个不超过200的正整数m, n，表示矩阵的行和列。接下来m行每行n个整数，表示这个矩阵。
输出格式
　　输出只有一行，共mn个数，为输入矩阵回形取数得到的结果。数之间用一个空格分隔，行末不要有多余的空格。
样例输入
3 3
1 2 3
4 5 6
7 8 9
样例输出
1 4 7 8 9 6 3 2 5
样例输入
3 2
1 2
3 4
5 6
样例输出
1 3 5 6 4 2*/

#include <iostream>
using namespace std;

int **arr;
int m, n;
int times=0;

void down();
void right();
void up();
void left();

void down() {
    if(times==m-times)
        return;
    for (int i = times; i < m-times; ++i) {
        cout << arr[i][times]<<" ";
    }
    right();
}

void right(){
    if(times+1==n-times)
        return;
    for (int i =times+1; i < n-times; ++i) {
        cout<<arr[m-times-1][i]<<' ';
    }
    up();
}

void up(){
    if(m-2-times==times-1)
        return;
    for (int i = m-2-times; i >=times; --i) {
        cout<<arr[i][n-times-1]<<" ";
    }
    left();
}

void left(){
    if(n-times-2==times)
        return;
    for (int i = n-times-2; i >times; --i) {
        cout<<arr[times][i]<<" ";
    }
    times++;
    down();
}

void traverse(int **arr,int m,int n){
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout<<arr[i][j]<<" ";
        }
    }
}

int main() {

    cin >> m >> n;
    arr = new int *[m];
    for (int i = 0; i < m; ++i) {
        arr[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }
    down();
    return 0;
}