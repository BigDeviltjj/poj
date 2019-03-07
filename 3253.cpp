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
int N, K;
int a[101],head[101],cnt;
int dp[101][302][2];
struct Node {
	Node(){}
	Node(int v_, int nex_):v(v_),nex(nex_){}
	int v, nex;
}e[202];
void addedge(int u, int v) {
	e[cnt] = Node(v, head[u]);
	head[u] = cnt++;
}

void dfs(int u, int fa) {
	for (int i = 0; i <= K; ++i) {
		dp[u][i][0] = dp[u][i][1] = a[u];
	}
	for (int i = head[u]; i != -1; i = e[i].nex) {
		int v = e[i].v;
		if (v == fa) continue;
		dfs(v, u);
		for (int j = K; j >= 0; --j) {

			for (int k = 0; k <= j; ++k) {
				dp[u][j + 2][0] = max(dp[u][j + 2][0], dp[u][j - k][0] + dp[v][k][0]);
				dp[u][j + 1][1] = max(dp[u][j + 1][1], dp[u][j - k][0] + dp[v][k][1]);
				dp[u][j + 2][1] = max(dp[u][j + 2][1], dp[u][j - k][1] + dp[v][k][0]);
			}
		}
	}
}
int main() {
	while (~scanf("%d %d", &N, &K)) {
		memset(head, -1, sizeof(head));
		memset(dp, 0, sizeof(dp));
		memset(e, 0, sizeof(e));
		cnt = 0;
		for (int i = 0; i < N; ++i)
			scanf("%d", &a[i + 1]);
		for (int i = 0; i < N - 1; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			addedge(u, v);
			addedge(v, u);
		}
		dfs(1,1);
		int ans = dp[1][K][1];
		printf("%d\n", ans);
	}
}
