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
#define INF 0x3f3f3f3f
using namespace std;
int n, r, cnt, stamp;
int head[2050], low[2050], dfn[2050],degree[2050];
struct List {
	List(){}
	List(int v_, int cost_, int nex_):v(v_),cost(cost_),nex(nex_){
	}
	int v, cost, nex;
}l[4050];
void addEdge(int u, int v, int cost) {
	l[cnt] = List(v, cost, head[u]);
	head[u] = cnt++;
}
void dfs(int u, int fa) {
	low[u] = dfn[u] = ++stamp;
	for (int i = head[u]; i != -1; i = l[i].nex) {
		int v = l[i].v;
		if (!dfn[v]) {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
		}
		else
			if (v != fa)
				low[u] = min(low[u], dfn[v]);
	}
}
int main() {
	scanf("%d %d", &n, &r);
	memset(head, -1, sizeof(head));
	for (int i = 0; i < r; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		addEdge(u, v, 1);
		addEdge(v, u, 1);
	}
	dfs(1, 1);
	for (int u = 1; u <= n; ++u) {
		for (int i = head[u]; i != -1; i = l[i].nex) {
			int v = l[i].v;
			if (low[u] != low[v]) degree[low[u]]++;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) ans += degree[i] == 1 ? 1 : 0;
	printf("%d\n", (ans + 1) / 2);
}
