#include <iostream>
#include <cstdio>
#include <map>
#include <cmath>
using namespace std;
int  a[6][2], ans;
#define MAXN 4000037
int exist[MAXN], num[MAXN];
bool f = 0, used[MAXN];
int locate(int v) {
    int temp = v;
    while (temp <0) temp+= MAXN;
    while (temp >= MAXN) temp-=MAXN;
    while (used[temp] && exist[temp] != v) {
        temp++;
        if (temp == MAXN) temp = 0;
    }
    return temp;
}
int fast_pow(int base, int power) {
    if (power == 0) return 0;
    if (power == 1) return base;
    if (base == 0) return 0;
    if (power % 2 == 1)
        return base * fast_pow(base * base, power / 2);
    else
        return fast_pow(base * base, power / 2);

}
void dfs(int n, int M, int val) {
    int temp = val;
    for (int  i = 1; i <= M; ++i) {
        val = temp + a[n][0] * fast_pow(i, a[n][1]);
        if ((n == 0 && f == 0) || (n == 3 && f == 1)) {

            int idx = locate(-val);
            ans += num[idx];
            
        }
        else 
            dfs(n-1, M, val);
    }
}
int main() {
    int n, M;
    scanf("%d %d", &n, &M);
    for (int i = 0; i < n; ++i) 
        scanf("%d %d", &a[i][0], &a[i][1]);
    if (n <= 3) {
        exist[0] = 1;
        num[0] = 1;
        dfs(n-1, M, 0);
    }
    else {
        f = 1;
        for (int i = 1; i <= M; ++i) 
            for (int j = 1; j <= M; ++j) 
                for (int k = 1; k <= M; ++k) {
                int val = a[0][0]*fast_pow(i, a[0][1]) + a[1][0]*fast_pow(j, a[1][1]) + a[2][0]*fast_pow(k,a[2][1]);
                int idx = locate(val);
                exist[idx] = val;
                used[idx] = 1;
                num[idx]++;
            }

        dfs(n-1, M, 0);
    }
    printf("%d\n", ans);
}



