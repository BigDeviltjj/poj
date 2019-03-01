#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#define INF 0x3f3f3f3f
using namespace std;
int N, M;
int fa[100001];
int dep[100001];
int father(int p) {
	if (fa[p] == p) {
		return p;
	}
	else {
		int t = fa[p];
		fa[p] = father(fa[p]);
		dep[p] = (dep[p] + dep[t]) % 2;
		return fa[p];
	}
}
void Union(int x, int y) {
	int fx = father(x);
	int fy = father(y);
	fa[fx] = fy;
	dep[fx] = (dep[x] + 1 + dep[y]) % 2;
}
int main(){
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &N, &M);
		for (int j = 1; j <= N; ++j) {
			fa[j] = j;
			dep[j] = 0;
		}
		char c;
		int a, b;

		while (M--) {
			scanf(" %c%d%d", &c, &a, &b);
			if (c == 'A') {
				int father_a = father(a), father_b = father(b);
				if (father_a != father_b)	printf("Not sure yet.\n");
				else {
					if (dep[a] != dep[b]) printf("In different gangs.\n");
					else printf("In the same gang.\n");
				}
			}
			else {
				Union(a, b);
			}
		}
	}
}
