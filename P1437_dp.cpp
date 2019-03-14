#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include<cstdio>
#include<cstring>
#include <algorithm>
using namespace std;
int a[101][101];
int dp[51][51][2550];
int tot[101][101];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n - i + 1; ++j) {
			scanf("%d", &a[i][j]);

		}

	}
	memset(dp, -127, sizeof(dp));
	dp[n + 1][0][0] = 0;
	for (int j = n; j >= 1; --j) {
		for (int i = 0,sum = 0; i <= n - j + 1; ++i,sum+=a[i][j]) {
			for (int k = i; k <= m; ++k) {
				for (int p = max(0, i - 1); p <= n - j; ++p)
					dp[j][i][k] = max(dp[j][i][k], dp[j + 1][p][k - i] + sum);
			}
		}
	}
	int ans;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n - i + 1; ++j) {
			ans = max(ans, dp[i][j][m]);
		}
	}
	printf("%d\n", ans);
}P1437 
