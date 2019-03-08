#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<cstdio>
#include<vector>
#include<iostream>
#include<numeric>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
int st[500050], ed[500050];
int abs_min = 0x3f3f3f3f, sort_min = 0x3f3f3f3f,N,M;
vector<int> s;
multiset<int> full, delta;
void update(int val) {
	multiset<int>::iterator it = full.lower_bound(val);
	if (it != full.end()) {
		sort_min = min(sort_min, abs(*it - val));
		if (it != full.begin()) sort_min = min(sort_min, abs(val - *(--it)));
	}
	full.insert(val);
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; ++i) {
		int x;
		scanf("%d", &x);
		st[i] = ed[i] = x;
	}
	for (int i = 1; i <= N; ++i) {
		update(st[i]);
	}
	for (int i = 1; i < N; ++i) {
		delta.insert(abs(st[i + 1] - ed[i]));
	}
	for (int i = 1; i <= M; ++i) {
		char str[20];
		scanf("%s", str);
		if (str[0] == 'I') {
			int pos, val;
			scanf("%d %d", &pos, &val);
			update(val);
			if (pos != N) {
				delta.erase(delta.find(abs(st[pos + 1] - ed[pos])));
				delta.insert(abs(st[pos + 1] - val));
			}
			delta.insert(abs(val - ed[pos]));
			ed[pos] = val;
		}
		else {
			if (str[4] == 'S') printf("%d\n", sort_min);
			else printf("%d\n", *delta.begin());
		}
	}
}
