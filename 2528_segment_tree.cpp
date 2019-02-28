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
int color[80010],num[80010],ans = 0;

int N,C;
void pushdown(int i) {
	if (color[i]) {
		color[i * 2 + 1] = color[i];
		color[i * 2] = color[i];
		color[i] = 0;
	}
}
void update(int x,int  i, int ql, int qr, int l, int r) {
	if (l >= ql && r <= qr) {
		color[i] = x;
		return;
	}
	pushdown(i);
	int mid = (l + r) >> 1;
	if (ql <= mid) update(x, i * 2, ql, qr, l, mid);
	if (qr > mid) update(x, i * 2 + 1, ql, qr, mid + 1, r);
}
void dfs(int i, int l, int r) {
	if (color[i] != 0) {
		num[color[i]]++;
		if (num[color[i]] == 1) ans++;
		return;
	}
	if (l == r) return;
	int mid = (l + r) >> 1;
	dfs(i * 2, l,mid);
	dfs(i * 2 + 1,mid+1,r);
}
int main() {
	scanf("%d", &C);
	for (int c = 0; c < C; ++c) {
		scanf("%d", &N);
		memset(color, 0, sizeof(color));
		memset(num, 0, sizeof(num));
		vector<pair<int,int> > poster;
		vector<int> disc;
		for (int i = 0; i < N; ++i) {
			int l, r;
			scanf("%d %d", &l, &r);
			poster.push_back({ l,r });
			disc.push_back(l);
			disc.push_back(r);
		}
		sort(disc.begin(), disc.end());
		int cnt = unique(disc.begin(), disc.end()) - disc.begin();
		for (int i = 0; i < N; ++i) {
			int l = lower_bound(disc.begin(), disc.begin() + cnt, poster[i].first) - disc.begin();
			int r = lower_bound(disc.begin(), disc.begin() + cnt, poster[i].second) - disc.begin();
			update(i + 1, 1, l, r, 0, cnt - 1);
		}
		ans = 0;
		dfs(1, 0,cnt -1);
		printf("%d\n", ans);
	}
}
