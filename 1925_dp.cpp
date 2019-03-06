#define _CRT_SECURE_NO_WARNINGS
#define INF 0x3f3f3f3f
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <utility>
#include <cstring>
#include <map>
#include <string>
#include <utility>
#include <cmath>
#include <queue>
using namespace std;
int K, N;
long long  a[5001][2];
int dp[1000005];
int main() {
	scanf_s("%d", &K);
	while (K--) {
		scanf_s("%d", &N);
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < N; ++i) {
			scanf_s("%lld %lld", &a[i][0], &a[i][1]);
		}
		dp[a[0][0]] = 0;
		for (int i = 1; i < N; ++i) {
			int tmp = sqrt(double(a[i][1] * a[i][1] - (a[i][1] - a[0][1])*(a[i][1] - a[0][1])));
			for (int j = 1; j <= tmp; ++j) {
				if (a[i][0] - j < a[0][0]) break;
				if (dp[a[i][0] - j] == -1) continue;
				int tmp = min(a[N - 1][0], a[i][0] + j);
				if (dp[tmp] == -1) dp[tmp] = dp[a[i][0] - j] + 1;
				else dp[tmp] = min(dp[tmp], dp[a[i][0] - j] + 1);
			}
		}
		printf("%d\n",dp[a[N-1][0]]);
	}
}
