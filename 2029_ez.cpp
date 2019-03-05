#define _CRT_SECURE_NO_WARNINGS

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
int N, W, H,S,T;
int grid[101][101],sum[101][101];
void integration() {
	for (int i = 1; i <= W;++i)
		for (int j = 1; j <= H; ++j) {
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + grid[i][j];
		}
}
int solve(int w, int h) {
	int ans = 0;
	for (int i = w; i<=W;++i)
		for (int j = h; j <= H; ++j) {
			int tmp = sum[i][j] - sum[i - w][j] - sum[i][j - h] + sum[i - w][j - h];
			ans = max(tmp, ans);
			
		}
	return ans;
}
int main() {
	while (~scanf("%d", &N) && N) {
		memset(grid, 0, sizeof(grid));
		scanf("%d %d", &W, &H);
		for (int i = 0; i < N; ++i) {
			int x, y;
			scanf("%d %d", &x, &y);
			grid[x][y] = 1;
		}
		integration();
		scanf("%d %d", &S, &T);
		int tmp1 = solve(S, T);
		printf("%d\n", tmp1);
	}
}
