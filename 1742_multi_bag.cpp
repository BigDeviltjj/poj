#include <vector>
#include <cstring>
#include <cstdio>
#include <map>
using namespace std;
int n, m;
int dp[100001], sum[100001];
int c[101], a[101];
void zero_one_pack(int cost, int weight) {
    for (int j = m; j >= cost; --j) {
        dp[j] |= dp[j-cost];
    }
}
int main() {
    while (scanf("%d%d", &n, &m) && n != 0 && m!=0) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &c[i]);
        }
        int cnt = 0;
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            memset(sum, 0, sizeof(sum));
            for (int j = a[i]; j <= m; ++j) {
                if (!dp[j] && dp[j-a[i]] && sum[j-a[i]] < c[i]) {
                    dp[j] = 1;
                    sum[j] = sum[j-a[i]]+1;
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);
    }
}
