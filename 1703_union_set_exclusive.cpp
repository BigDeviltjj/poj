#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#define INF 0x3f3f3f3f
using namespace std;
int N, M;
int fa[200002];
int father(int p) {
	if (fa[p] == p) {
		return p;
	}
	else {		
		return fa[p] = father(fa[p]);
	}
}
void Union(int x, int y) {
	int fx = father(x);
	int fy = father(y);
	fa[fx] = fy;
}
int main(){
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &N, &M);
		for (int j = 1; j <= 2 * N; ++j) {
			fa[j] = j;
		}
		char c;
		int a, b;

		while (M--) {
			scanf(" %c%d%d", &c, &a, &b);
			if (c == 'A') {
				if (father(a) == father(b)) printf("In the same gang.\n");
				else
				{
					if (father(a) == father(b + N)) printf("In different gangs.\n");
					else printf("Not sure yet.\n");
				}
				
			}
			else {
				Union(a, b + N);
				Union(a + N, b);
			}
		}
	}
}
