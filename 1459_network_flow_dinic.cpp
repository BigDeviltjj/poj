#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;
struct List {
	List(){}
	List( int v_, int p_, int nex_):v(v_),p(p_),nex(nex_){}
	int  v, p,nex;
}l[22000];
int head[22000], cnt = 0,ss, tt, ans;
int dis[103];
bool bfs() {
	queue<int> q;
	q.push(ss);
	memset(dis, -1, sizeof(dis));
	dis[ss] = 0;
	while (!q.empty()) {
		int u = q.front();
		if (u == tt) return 1;
		q.pop();
		for (int i = head[u]; i != -1; i = l[i].nex) {
			int v = l[i].v;
			if (dis[v] == -1 && l[i].p) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
	return 0;
}
int dfs(int u, int tt, int maxflow) {
	if (u == tt) return maxflow;
	int ret = 0;
	for (int i = head[u]; i != -1; i = l[i].nex) {
		int v = l[i].v, p = l[i].p;
		if (dis[v] == dis[u] + 1 && l[i].p) {
			int f = dfs(v, tt, min(maxflow - ret, p));
			l[i].p -= f;
			l[i ^ 1].p += f;
			ret += f;
			if (ret == maxflow) return ret;
		}
	}
	return ret;

}
int Dinic() {
	while (bfs()) {
		ans += dfs(ss,tt,0x3f3f3f3f);
	}
	return ans;
}
int main() {
	int n, np, nc, m;
	while (~scanf("%d%d%d%d", &n, &np, &nc, &m)) {
		memset(head, -1, sizeof(head));
		ss = 1 + n, tt = n + 2;
		cnt = 0;
		ans = 0;
		for (int i = 0; i < m; ++i) {
			int u, v, z;
			scanf(" (%d,%d)%d", &u, &v, &z);
			l[cnt] = List( v, z, head[u]);
			head[u] = cnt++;

			l[cnt] = List( u, 0, head[v]);
			head[v] = cnt++;

		}
		for (int i = 0; i < np; ++i) {
			int u, z;
			scanf(" (%d)%d", &u,&z);
			l[cnt] = List( u, z, head[ss]);
			head[ss] = cnt++;

			l[cnt] = List( ss, 0, head[u]);
			head[u] = cnt++;

		}
		for (int i = 0; i < nc; ++i) {
			int u, z;
			scanf(" (%d)%d", &u, &z);
			l[cnt] = List( tt, z, head[u]);
			head[u] = cnt++;

			l[cnt] = List( u, 0, head[tt]);
			head[tt] = cnt++;

		}
		printf("%d\n",Dinic());

	}
}
