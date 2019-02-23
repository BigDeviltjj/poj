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
	bool matched;
}l[22000];
int head[22000], cnt = 0;
int matched[1000], used[1000];
bool Hungarian(int u) {
	used[u] = 1;

	for (int i = head[u]; i != -1; i = l[i].nex) {
		int v = l[i].v, w = matched[v];
		if (w == -1 || (!used[w] && Hungarian(w))) {
			matched[u] = v;
			matched[v] = u;
			return true;
		}
	}
	return false;
}
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	int r, c;
	memset(head, -1, sizeof(head));
	for (int i = 0; i < k; ++i) {
		scanf("%d %d", &r, &c);
		r--;
		c--;
		c += n;	
		l[cnt] = List(c, 1, head[r]);
		head[r] = cnt++;

		l[cnt] = List(r, 1, head[c]);
		head[c] = cnt++;
	}
	int ans = 0;
	memset(matched, -1, sizeof(matched));
	for (int i = 0; i < n; ++i) {
		if (matched[i] == -1) {
			memset(used, 0, sizeof(used));
			if (Hungarian(i)) ans++;

		}
	}
	printf("%d\n", ans);
	system("pause");
}
