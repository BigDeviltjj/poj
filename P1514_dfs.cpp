#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m;
int a[501][501];
int ll[501][501], rr[501][501], vis[501][501];
int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int count0 = 0;
void dfs(int i, int j) {
    if (i == n-1) count0--;
    vis[i][j] = 1;
    for (int x = 0; x < 4; ++x) {
        int i1 = i+dir[x][0], j1 = j+dir[x][1];
        if ( i1 >= 0 && j1 >= 0 && i1 < n && j1 < m && a[i1][j1] < a[i][j]) {
            if (!vis[i1][j1]) dfs(i1, j1); 
            ll[i][j] = min(ll[i][j], ll[i1][j1]);
            rr[i][j] = max(rr[i][j], rr[i1][j1]);
        }

    }
}
int main() {
    scanf("%d%d", &n, &m);
    memset(ll, 0x3f, sizeof(ll));
    memset(rr, -1, sizeof(rr));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]); 
        }
    for (int j = 0; j < m; ++j) 
        ll[n-1][j] = rr[n-1][j] = j;
    count0 = m;
    for (int i = 0; i < m; ++i) {
        if (!vis[0][i]) dfs(0, i);
    }
   // for (int i = 0; i < n; ++i) {
   //     for (int j = 0; j < m; ++j) {
   //         printf("%d ", ll[i][j]); 
   //     }
   //     cout<<endl;
   // }
   // for (int i = 0; i < n; ++i) {
   //     for (int j = 0; j < m; ++j) {
   //         printf("%d ", rr[i][j]); 
   //     }
   //     cout<<endl;
   // }
    if (count0 != 0) {
        printf("0\n%d\n", count0);
        return 0;
    }

    int left = 0, right = 0, cnt=0;
    while (left < m) {
        for (int i = 0; i < m; ++i) {
            if (ll[0][i] <= left) {
                right = max(right, rr[0][i]);
            }
        }
        cnt++;
        left = right + 1;
    }
    printf("1\n%d\n", cnt);
}
