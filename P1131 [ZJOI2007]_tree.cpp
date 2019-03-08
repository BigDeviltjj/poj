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
int N, S;
long long head[1000010], cnt, dis[500010], ans = 0, max_dis = 0;
vector<int> leaf;
struct Node
{
	Node(){}
	Node(int v_, int val_, int nex_):v(v_),val(val_),nex(nex_){}
	int v ,val,nex;
}e[1000010];
void addedge(int u, int v,int val) {
	e[cnt] = Node(v, val, head[u]);
	head[u] = cnt++;
}
void dfs(int u,int fa) {
	int cnt = 0;
	for (int i = head[u]; i != -1; i = e[i].nex) {
		int v = e[i].v;
		if (v != fa) {
			cnt++;
			dfs(v,u);
			//dis[u] = max(dis[u], dis[v]);
			if (dis[v] + e[i].val > dis[u]) {
				ans += (cnt - 1) * (dis[v] + e[i].val - dis[u]);
				dis[u] = dis[v] + e[i].val;
			}
			else {
				ans += -dis[v] - e[i].val + dis[u];
			}
		}
	}
}
int main() {
	memset(head, -1, sizeof(head));
	scanf("%d", &N);
	scanf("%d", &S);
	for (int i = 0; i < N - 1; ++i) {
		int a, b, t;
		scanf("%d %d %d", &a, &b, &t);
		addedge(a, b, t);
		addedge(b, a, t);
	}
	dfs(S,S);
	printf("%lld\n", ans);
}
