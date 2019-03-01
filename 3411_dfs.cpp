#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
struct Edge
{
	Edge(){}
	Edge(int a_, int b_, int c_, int p_, int r_):a(a_),b(b_),c(c_),p(p_),r(r_){}
	int a, b, c, p, r;
}e[100];
int N, M, cnt, ans = INF;
int vis[20];
void dfs(int p, int s, int v) {
	if (vis[p] > 5) return;
	s = s | (1 << (p-1));
	if (p == N) {
		ans = min(ans, v);
		return;
	}
	for (int i = 0; i < M; ++i) {
		if (e[i].a != p) continue;
		vis[e[i].b]++;
		if ((s & (1 << (e[i].c - 1)))) dfs(e[i].b, s, v + e[i].p);
		else
			dfs(e[i].b, s, v + e[i].r);
		vis[e[i].b]--;

	}
}
int main() {

	scanf("%d %d", &N, &M);
	int a, b, c, p, r;
	for (int i = 0; i < M; ++i) {
		scanf("%d %d %d %d %d", &a, &b, &c, &p, &r);
		e[cnt++] = Edge(a, b, c, p, r);
	}
	vis[1] = 1;
	dfs(1, 0, 0);
	if (ans == INF) puts("impossible");
	else printf("%d\n", ans);
}
