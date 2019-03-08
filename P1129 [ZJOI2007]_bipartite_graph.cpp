#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<cstdio>
#include<vector>
#include<iostream>
#include<numeric>
#include<algorithm>
#include<cstring>
#include<set>
#include<map>
using namespace std;
int T, N;
int head[80080],cnt,edge[500],ans = 0,vis[500];
struct Node
{
	Node(){}
	Node(int v_, int nex_):v(v_),nex(nex_){}
	int v, nex;
}e[80080];
void addedge(int u, int v) {
	e[cnt] = Node(v, head[u]);
	head[u] = cnt++;
}
bool dfs(int u) {
	vis[u] = 1;
	for (int i = head[u]; i != -1; i = e[i].nex) {
		int v = e[i].v;
		int w = edge[v];
		if (w == 0 || (!vis[w] && dfs(w))) {
			edge[u] = v;
			edge[v] = u;
			return true;
		}
	}
	return false;
}
int main() {
	scanf("%d", &T);
	while (T--) {
		cnt = 0;
		ans = 0;
		scanf("%d", &N);
		memset(edge, 0, sizeof(edge));
		memset(head, -1, sizeof(head));
		for (int i = 1; i<=N;++i)
			for (int j = 1; j <= N; ++j) {
				int x;
				scanf("%d", &x);
				if (x == 1) {
					addedge(i, N + j);
					addedge(N + j, i);
				}
			}
		for (int i = 1; i <= N; ++i) {
			if (edge[i] == 0) {
				memset(vis, 0, sizeof(vis));
				ans += dfs(i);
			}
		}
		if (ans == N) printf("Yes\n");
		else printf("No\n");
	}

}
