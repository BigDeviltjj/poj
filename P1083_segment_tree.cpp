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
#include <fstream>
#include <utility>
#include <cmath>
#include <queue>
using namespace std;
int n, m,k,x,y,flag;
int   a[1000005], tree[1000005*2], neg[1000005*2];
void build(int l, int r, int p) {
	if (l == r) tree[p] = a[l];
	else {
		int mid = (l + r) >> 1;
		build(l, mid, p + p);
		build(mid + 1, r, p + p + 1);
		tree[p] = min(tree[p + p], tree[p + p + 1]);
	}
}
void push(int p) {
	tree[p + p] -= neg[p];
	tree[p + p + 1] -= neg[p];
	if (tree[p + p] < 0 || tree[p + p + 1] < 0) flag = 0;
	neg[p + p] += neg[p];
	neg[p + p + 1] += neg[p];
	neg[p] = 0;
}

void update( int l, int r, int p) {
	if (!flag) return;
	if (l >= x && r <= y) {
		neg[p] += k;
		tree[p] -= k;
		if (tree[p] < 0) flag = 0;
		return;
	}
	push(p);

	int mid = (l + r) >> 1;
	if (x <= mid) {
		update( l, mid, p +p );
	}
	if (y >= mid + 1)
		update( mid + 1, r, p +p + 1);

	tree[p] = min(tree[p+p], tree[p+p + 1]);
}


int main() {
	/*ifstream  fin;
	fin.open("testdata.in", ios::in);
	fin >> n >> m;
	*/
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		//fin >> a[i];
		scanf("%d", &a[i]);
	}
	build(1, n, 1);

	for (int i = 1; i <= m; ++i) {
		flag = 1;
		//fin >> k >> x >> y;		//d = get(); s = get(); t = get();
		scanf("%d %d %d", &k, &x, &y);
		update( 1, n, 1);
		if (!flag) {
			printf("-1\n%d\n", i);
			return 0;
		}
	}
	printf("0\n");
}
