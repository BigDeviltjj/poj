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
int M, N;
int a[13][13];
vector<int> pos[13];
int cnt;
int num[13];
long long valid[13][500];
long long state[13];
long long dp[13][500];
void init() {
	long long  tot = 1 << (N);

	for (int i = 0; i < M; ++i) {
		for (long long  j = 0; j < tot; ++j) {
			if ((j & (j >> 1)) == 0 && (j & state[i]) == 0) {
				valid[i][num[i]++] = j;
				if (i == 0) dp[i][num[i] - 1] = 1;
			}
		}
	}
}
int main() {
	scanf("%d %d", &M, &N);
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < N; ++j) {
			scanf("%d", &a[i][j]);
			a[i][j] = 1 - a[i][j];
			state[i] |= (a[i][j] << j);
		}
	init();
	for (int i = 1; i < M; ++i) {
		for (int j = 0; j < num[i]; ++j) {
			long long  s = valid[i][j];
			for (int k = 0; k < num[i - 1]; ++k) {
				long long  t = valid[i - 1][k];
				if ((t & s) == 0) {
					dp[i][j] = (dp[i][j] + dp[i - 1][k]) % 100000000;
				}
			}
		}
	}
	long ans = 0;
	for (int i = 0; i < num[M - 1]; ++i)
		ans = (ans + dp[M - 1][i]) % 100000000;
	printf("%d\n", ans);
}
