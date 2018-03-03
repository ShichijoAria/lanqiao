//
// Created by aria on 18-3-2.
//

/*
问题描述
　　给定一个n*n的棋盘，棋盘中有一些位置不能放皇后。现在要向棋盘中放入n个黑皇后和n个白皇后，使任意的两个黑皇后都不在同一行、同一列或同一条对角线上，任意的两个白皇后都不在同一行、同一列或同一条对角线上。问总共有多少种放法？n小于等于8。
输入格式
　　输入的第一行为一个整数n，表示棋盘的大小。
　　接下来n行，每行n个0或1的整数，如果一个整数为1，表示对应的位置可以放皇后，如果一个整数为0，表示对应的位置不可以放皇后。
输出格式
　　输出一个整数，表示总共有多少种放法。
样例输入
4
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
样例输出
2
样例输入
4
1 0 1 1
1 1 1 1
1 1 1 1
1 1 1 1
样例输出
0*/


//vector效率太低会造成时间超时，尽量避免使用
//vector计算2 7皇后用了156ms 而使用动态数组计算2 8皇后只用了31ms
#include <iostream>
#include <cmath>
using namespace std;
int sum = 0;

bool isSafe(int *coordinates,int row){
    for(int i = 0; i < row; i++) {
        if(coordinates[i] == coordinates[row] || abs(i - row) == abs(coordinates[i] - coordinates[row]))
            return false;
    }
    return true;
}

void blackDfs(int **blackChessboard,int *blackCoordinates,int n,int blackRow){
    if(blackRow == n) {
        sum++;
        return;
    }
    for(blackCoordinates[blackRow] = 0; blackCoordinates[blackRow] < n; blackCoordinates[blackRow]++) {
        if(blackChessboard[blackRow][blackCoordinates[blackRow]] == 1 && isSafe(blackCoordinates, blackRow)) {
            blackDfs(blackChessboard, blackCoordinates, n, blackRow + 1);
        }
    }
}

void dfs(int **chessboard,int *coordinates,int n,int row){
    if(row == n) {
        int **blackChessboard=new int*[n];
        int *blackCoordinates=new int[n];
        for(int i = 0; i < n; i++) {
            blackChessboard[i]=new int[n];
            for(int j = 0; j < n; j++) {
                blackChessboard[i][j]= chessboard[i][j];
            }
        }

        for(int i = 0; i < n; i++) {
            blackChessboard[i][coordinates[i]] = 0;
        }
        blackDfs(blackChessboard, blackCoordinates, n, 0);
        return;
    }
    for(coordinates[row] = 0; coordinates[row] < n; coordinates[row]++) {
        if(chessboard[row][coordinates[row]] == 1 && isSafe(coordinates, row)) {
            dfs(chessboard, coordinates, n, row + 1);
        }
    }
}

void traverse(int **chessboard,int n){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout<<chessboard[i][j];
        }
    }
}

int main() {
    int n;
    cin >> n;
    int **chessboard=new int*[n];
    int *coordinates=new int[n];
    for(int i = 0; i < n; i++) {
        chessboard[i]=new int[n];
        for(int j = 0; j < n; j++) {
            cin >> chessboard[i][j];
        }
    }
    dfs(chessboard, coordinates, n, 0);
    cout<<sum;
    return 0;
}
