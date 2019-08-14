#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;
int n, m;
int a[30];
int dp[20001];
int vis[30];
int ret;
void dpfunc() {
    memset(dp, 0, sizeof(dp));
    int sum = 0;
    int ans = 0;
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        if (vis[i] == 1) continue;
        for (int j = sum; j>= 0; j--) {

            if (dp[j] == 1 && !dp[j+a[i]]) {
                ans++;
                dp[j+a[i]] = 1;
            }
        }
        sum += a[i];
    }
    ret = max(ret, ans);
}
void dfs(int i, int num) {
    if (num == m) {
        dpfunc(); return;
    }
    if (i >= n) return;
    dfs(i+1,num);
    vis[i] = 1;
    dfs(i+1, num+1);
    vis[i] = 0;
}
int main() {
    scanf("%d%d", &n, &m);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    dfs(0, 0);
    printf("%d\n", ret);
}
