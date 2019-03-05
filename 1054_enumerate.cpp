#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <utility>
#include <cstring>
#include <map>
#include <string>
#include <utility>
using namespace std;	
int R, C, N;
bool grid[5001][5001];
vector<pair<int, int> > pts;
bool cmp(pair<int, int> &a, pair<int, int> &b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}
int main() {
	scanf_s("%d %d", &R, &C);
	scanf_s("%d", &N);
	int x, y;
	for (int i = 0; i < N; ++i) {
		scanf_s("%d %d", &x, &y);
		pts.push_back(make_pair(x, y));
		grid[x][y] = 1;
	}
	sort(pts.begin(), pts.end(), cmp);
	int ans = 0;
	for (int i = 0; i < pts.size(); ++i) {
		for (int j = i + 1; j < pts.size(); ++j) {
			int disX = pts[j].first - pts[i].first;
			int disY = pts[j].second - pts[i].second;
			if (pts[i].first - disX >= 1 && pts[i].first - disX <= R && pts[i].second - disY >= 1 && pts[i].second - disY <= C) continue;

			int num = 0,flag = 0;
			int tmpx = pts[i].first, tmpy = pts[i].second;
			while (tmpx <= R && tmpy <= C && tmpx>=1 && tmpy>= 1) {
				if (!grid[tmpx][tmpy]) { flag = 1; break; }
				num++;
				tmpx += disX;
				tmpy += disY;
			}
			if (num < 3) num = 0;
			ans = flag == 0 ? max(ans, num) : ans;
		}
	}
	printf("%d\n", ans);
	system("pause");
}
