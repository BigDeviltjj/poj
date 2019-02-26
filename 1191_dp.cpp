#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;
int chess[8][8] = { 0 };
int dp[15][8][8][8][8] = { 0 };
int N = 0;
int get_sum2(int x0, int y0, int x1, int y1) {
	int ret = 0;
	for (int i = x0; i <= x1; ++i) {
		for (int j = y0; j <= y1; ++j)
			ret += chess[i][j];
	}
	return ret * ret;
}
int search(int step, int x0, int y0, int x1, int y1) {
	if (dp[step][x0][y0][x1][y1] >= 0) return dp[step][x0][y0][x1][y1];
	if (step == 0) {
		dp[step][x0][y0][x1][y1] = get_sum2(x0, y0, x1, y1);
		return dp[step][x0][y0][x1][y1];
	}
	int min = 1000000000;
	for (int i = x0; i <= x1-1; ++i) {
		int tmp1 = search(0, x0, y0, i, y1) + search(step - 1, i+1, y0, x1, y1);
		int tmp2 = search(step - 1, x0, y0, i, y1) + search(0 , i+1, y0, x1, y1);
		int min1 = (tmp1 > tmp2) ?  tmp2 : tmp1;
		if (min1 < min) min = min1;
	}
	for (int i = y0; i <= y1 - 1; ++i) {
		int tmp1 = search(0, x0, y0, x1, i) + search(step - 1, x0, i+1, x1, y1);
		int tmp2 = search(step - 1, x0, y0, x1, i) + search(0, x0, i+1, x1, y1);
		int min1 = (tmp1 > tmp2) ? tmp2 : tmp1;
		if (min1 < min) min = min1;
	}
	dp[step][x0][y0][x1][y1] = min;
	return min;
}
int main() {
	memset(dp, -1, sizeof(dp));
	cin >> N;
	int sum = 0;
	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j) {
			cin >> chess[i][j];
			sum += chess[i][j];
		}
	double x_mean = sum * 1./ N;
	x_mean = x_mean * x_mean * N;
	int val = search(N - 1, 0, 0, 7, 7);
	double ret = sqrt((val * 1.- x_mean) / (1. * N));
	printf("%.3f\n", ret);
	return 0;
}
