#include <iostream>
#include <cstdio>
using namespace std;
int dp[11][11][11][31];
int l1, l2, l3, d;
void dfs(int I, int J, int K, int L) {
    for (int l = 1; l <= L; ++l) {
        for (int i = 0; i <= I; ++i) {
            for (int j = 0; j <= J;++j)
                for (int k = 0; k <= K; ++k) {
                    for (int k1 = 1; k1 <= k; ++k1)
                        dp[i][j][k][l] = (dp[i][j][k][l] + (dp[0][0][k1-1][l-1] * dp[i][j][k-k1][l] % 11380))%11380;
                    for (int k1 = 0; k1 <= k; ++k1)
                        for (int j1 = 1;j1 <= j; ++j1)
                            dp[i][j][k][l] = (dp[i][j][k][l] + (dp[0][j1-1][k1][l-1] * dp[i][j-j1][k-k1][l]%11380))%11380;
                    for (int k1 = 0; k1 <= k; ++k1)
                        for (int j1 = 0;j1 <= j; ++j1)
                            for (int i1 = 1; i1 <=i; ++i1)
                                dp[i][j][k][l] = (dp[i][j][k][l] + (dp[i1-1][j1][k1][l-1] * dp[i-i1][j-j1][k-k1][l]%11380))%11380;
                }
        }
    }
}
int main() {
    scanf("%d %d %d %d", &l1, &l2, &l3, &d);
    for (int i = 0; i <= d; ++i) dp[0][0][0][i] = 1;
    dfs(l1, l2, l3, d);
    printf("%d\n", ((dp[l1][l2][l3][d] - dp[l1][l2][l3][d-1])%11380 + 11380) %11380);
}

