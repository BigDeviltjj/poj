#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<map>
#include<string>
using namespace std;
float a[1000];
int dp[1000][2];

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%f", &a[i]);
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < i; ++j) {
			if (a[i] > a[j]) dp[i][0] = max(dp[i][0],dp[j][0] + 1);
		}
	}
	for (int i = N - 1; i >= 0; --i) {
		for (int j = N-1; j > i; --j) {
			if (a[i] > a[j]) dp[i][1] = max(dp[i][1], dp[j][1] + 1);
		}
	}
	int ans = 0;

	for (int i = 0; i < N; ++i) {
		ans = max(ans, dp[i][0] + dp[i][1] + 1);

		for (int j = i+1; j < N; ++j)
		{
			ans = max(ans, dp[i][0] + dp[j][1] + 2);

		}
	}
	cout << N - ans << endl;
} 
