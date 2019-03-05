#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <utility>
#include <cstring>
#include <map>
#include <string>
#include <utility>
using namespace std;	
int N, M;
string str;
pair<int, int> cost[300];
int dp[2001][2001];
int main() {
	cin >> N >> M;
	cin >> str;
	getchar();
	for (int i = 0; i < N; ++i) {
		int a, b;
		char c;
		cin >> c >> a >> b;
		cost[c] = make_pair(a, b);
	}
	for (int i = 1; i < M; ++i) {
		for (int j = 0; j < M; ++j) {
			if (i + j >= M) continue;
			int tmp1 = min(cost[str[j]].first, cost[str[j]].second), tmp2 = min(cost[str[i + j]].first, cost[str[i + j]].second);
			if (str[i + j] == str[j]) dp[j][i + j] = i == 1 ? 0 : dp[j + 1][i + j - 1];
			else
			{
				dp[j][i + j] = min(dp[j + 1][i + j] + tmp1, dp[j][i + j - 1] + tmp2);

			}

		}
	}
	printf("%d\n", dp[0][M - 1]);
	system("pause");
}
