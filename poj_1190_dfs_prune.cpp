#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
#define MAXN 0x3f3f3f3f
int N, M;
int ans = MAXN;
int miniV[21], miniS[21];
int maxV(int m, int r, int h) {
    int ans = 0;
    while (m--) {
        ans += r*r*h;
    }
    return ans;
}
void dfs(int v, int m, int s, int last_r, int last_h) {
    if (m == 0 && v == 0) {
        ans = s < ans ? s : ans;
        return;
    }
    if (m == 0) return;
    if (s > ans && ans != MAXN) return;
    if (s + miniS[m] >= ans) return;
    if (maxV(m, last_r - 1, last_h - 1) < v) return;
    int temp = v - miniV[m-1];
    for (int r = last_r - 1; r >= m; --r) {
        if (m == M) s = r*r;
        for (int h = min(last_h - 1, temp/r/r); h >= m; --h) {
            if (r*r*h > temp) break;
            //if (r*r*h*m <= v) continue;
            dfs(v - r*r*h, m-1, s+r*2*h,r, h);
        }
    }
}
int main() {
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= M; ++i) {
        miniV[i] = miniV[i-1] + i*i*i;
        miniS[i] = miniS[i-1] + 2 * i * i;
    }
    if (N < miniV[M]) {
        printf("0\n");
    }
    else dfs(N, M, 0, int(sqrt((N - miniV[M-1])/M)), int((N - miniV[M-1])/M/M));
    printf("%d\n", ans == MAXN ? 0 : ans);
}
