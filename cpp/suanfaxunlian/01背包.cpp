//
// Created by aria on 18-3-6.
//

#include<stdio.h>
#include<algorithm>
using namespace std;
int f[1001][1001];
int main()
{
    int T, n,c[10001], v[10001];
    scanf("%d%d", &T, &n);
    for(int i = 1; i <= n; i++)
        scanf("%d%d", &v[i], &c[i]);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= T; j++)
            f[i][j] = f[i-1][j];
        for(int j = 0; j+v[i] <= T; j++)
            f[i][j] = max(f[i][j] + c[i], f[i-1][j+v[i]]);
    }
    int ans = 0;
    for(int i = 0; i <= T; i++)
        ans = max(ans, f[n][i]);
    printf("%d", ans);
    return 0;
}