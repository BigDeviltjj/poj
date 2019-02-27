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
#include<stack>
#define INF 0x3f3f3f3f
using namespace std;
stack<int> s;

int n, r, cnt, stamp,scc;
int head[10050], low[10050], dfn[10050],degree[10050], be[10050],num[10050];
bool mark[10050];
struct List {
	List(){}
	List(int v_, int cost_, int nex_):v(v_),cost(cost_),nex(nex_){
	}
	int v, cost, nex;
}l[50050];
void addEdge(int u, int v, int cost) {
	l[cnt] = List(v, cost, head[u]);
	head[u] = cnt++;
}
void dfs(int u, int fa) {
	low[u] = dfn[u] = ++stamp;
	s.push(u);
	mark[u] = 1;
	for (int i = head[u]; i != -1; i = l[i].nex) {
		int v = l[i].v;
		if (!dfn[v]) {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
		}
		else
			if (mark[v])
				low[u] = min(low[u], dfn[v]);
	}
	if (low[u] == dfn[u]) {
		int v;
		scc++;

		do
		{
			v = s.top();
			be[v] = scc;
			s.pop();
			mark[v] = 0;
			num[scc]++;
		} while (v != u);
	}
}
int main() {
	scanf("%d %d", &n, &r);
	memset(head, -1, sizeof(head));
	for (int i = 0; i < r; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		addEdge(u, v, 1);
	}
	for (int i = 1; i <= n;++i)
		if (!dfn[i]) dfs(i, i);

	for (int u = 1; u <= n; ++u) {
		for (int i = head[u]; i != -1; i = l[i].nex) {
			int v = l[i].v;
			if (be[u] != be[v]) degree[be[u]]++;
		}
	}
	int  flag = 0, ans = 0;
	for (int i = 1; i <= scc; ++i) {
		if (degree[i] == 0)
		{
			if (flag == 0) {
				flag = 1;
				ans = num[i];
			}
			else {
					ans = 0;
					break;
				}

		}
	}
	printf("%d\n", ans);
}
