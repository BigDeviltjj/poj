#define _CRT_SECURE_NO_WARNINGS
#define INF 0x3f3f3f3f
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
char str[2010][8];
int father[2010];
int Map[2000][2000];
int dis(char *x, char *y) {
	int ret = 0;
	for (int i = 0; i < 7; ++i) {
		if (*(x + i) != *(y + i)) ret++;
	}
	return ret;
}
int prim(int n) {
	vector<int> dist(n, INF);
	vector<bool> used(n, 0);
	int cnt = 0;
	int now = 0;
	dist[0] = 0;
	used[0] = 1;
	int ret = 0;
	while (cnt < n - 1) {
		int min_val = INF, min_idx = 0;

		for (int i = 0; i < n; ++i) {
			if (!used[i]) {
				dist[i] = min(dist[i], Map[now][i]);
				if (dist[i] < min_val) {
					min_idx = i;
					min_val = dist[i];
				}
			}
		}
		now = min_idx;
		ret += min_val;
		used[now] = 1;
		cnt++;
	}
	return ret;
}
int main() {
	int n;
	while (~scanf("%d", &n) && n)
	{
		memset(str, 0, sizeof(str));
		for (int i = 0; i < n; ++i) father[i] = i;
		for (int cnt = 0; cnt<n;++cnt)
		{
			scanf("%s", str[cnt]);
			for (int i = 0; i < cnt; ++i) {
				Map[i][cnt] = Map[cnt][i] = dis(str[i], str[cnt]);
			}

		}

		printf("The highest possible quality is 1/%d.\n", prim(n));
	}
}
