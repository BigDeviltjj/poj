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
int N, M;
int lowbit(int x)
{
	return x&(-x);
}
vector<vector<int> > tree(100010);
int b[100010], e[100010],cnt,f[100010],bit[100010];
void dfs(int root, int father) {
	b[root] = cnt;
	for (int i = 0; i < tree[root].size(); ++i) {
		if (tree[root][i] == father) continue;
		cnt++;
		dfs(tree[root][i], root);
	}
	e[root] = cnt;
}
void add(int idx, int val) {
	while (idx <= cnt) {
		bit[idx] += val;
		idx += lowbit(idx);
	}
}
int sum(int idx) {
	int ans = 0;
	while (idx >= 1) {
		ans += bit[idx];
		idx -= lowbit(idx);
	}
	return ans;
}
int main(){
	int a;
	scanf("%d", &N);
	for (int i = 0; i < N - 1; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	cnt = 1;
	dfs(1,-1);
	for (int i = 1; i <= N; ++i) {
		add(i, 1);
		f[i] = 1;
	}
	scanf("%d", &M);
	for (int i = 0; i < M; ++i) {
		char c;
		int idx;
		scanf("%c", &c);
		scanf("%c %d", &c, &idx);
		if (c == 'C') {
			add(b[idx], (f[idx]^1) - f[idx]);
			f[idx] = f[idx] ^ 1;
		}
		else {
			printf("%d\n", sum(e[idx]) - sum(b[idx] - 1));
		}
	}
}
