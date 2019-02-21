#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
char str[2010][8];
int father[2010];
struct Side {
	Side() {}
	Side(int x_, int y_, int v_) :x(x_), y(y_), v(v_) {}
	int x, y, v;
	bool operator<(Side const& rhs) const {
		return v < rhs.v;
	}
};
int dis(char *x, char *y) {
	int ret = 0;
	for (int i = 0; i < 7; ++i) {
		if (*(x + i) != *(y + i)) ret++;
	}
	return ret;
}
int find(int x) {
	if (father[x] == x) {
		return x;
	}
	else {
		return father[x] = find(father[x]);
	}
}
int main() {
	int n;
	while (~scanf("%d", &n) && n)
	{
		memset(str, 0, sizeof(str));
		for (int i = 0; i < n; ++i) father[i] = i;
		vector<Side> l;
		for (int cnt = 0; cnt<n;++cnt)
		{
			scanf("%s", str[cnt]);
			for (int i = 0; i < cnt; ++i) {
				l.push_back(Side(i, cnt, dis(str[i], str[cnt])));
			}

		}
		sort(l.begin(), l.end());
		int num = 0, ans = 0, tot = 0;
		//while (tot < n - 1) {
		while(tot < n -1)	{

			int u = l[num].x, v = l[num].y;
			int fu = find(u), fv = find(v);
			if (fu != fv) {
				father[fu] = fv;
				ans += l[num].v;
				tot++;
			}
			num++;
		}
		printf("The highest possible quality is 1/%d.\n", ans);
	}
}
