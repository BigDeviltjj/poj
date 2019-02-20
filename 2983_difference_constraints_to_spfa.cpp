#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
struct List
{
	int val, point,nex;
}l[200000];
int head[1000];
queue<int> q;
bool flag[1000];
int dis[1000];
int cnt[1000];

bool spfa(int n, int m) {
	memset(flag, 0, sizeof(flag));
	memset(dis, 0, sizeof(dis));
	memset(cnt, 0, sizeof(cnt));

	for (int i = 0; i < n; ++i) q.push(i), flag[i] = 1;
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		flag[p] = 0;
		for (int i = head[p]; i != -1; i = l[i].nex) {
			if (dis[p] + l[i].val > dis[l[i].point]) {
				dis[l[i].point] = dis[p] + l[i].val;
				if (!flag[l[i].point]) {
					cnt[l[i].point]++;
					if (cnt[l[i].point] == n) return false;
					q.push(l[i].point);
					flag[l[i].point] = 1;
				}
			}
		}

	}
	return true;
}
int main()
{
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF) {
		int cnt = 0;
		memset(head, -1, sizeof(head));
		memset(l, 0, sizeof(l));

		for (int i = 0; i < m; ++i) {
			char c;
			int x, y,v;
			scanf("%c", &c);

			scanf("%c", &c);
			if (c == 'P') {
				scanf("%d %d %d", &x, &y, &v);
				x--; y--;
				l[cnt].nex = head[x];
				l[cnt].val = v;
				l[cnt].point = y;
				head[x] = cnt++;

				l[cnt].nex = head[y];
				l[cnt].val = -v;
				l[cnt].point = x;
				head[y] = cnt++;
			}
			else
			{
				scanf("%d %d", &x, &y);
				x--; y--;
				l[cnt].nex = head[x];
				l[cnt].val = 1;
				l[cnt].point = y;
				head[x] = cnt++;

			}

		}
		if (spfa(n,m)) printf("Reliable\n");
		else printf("Unreliable\n");
	}
}
