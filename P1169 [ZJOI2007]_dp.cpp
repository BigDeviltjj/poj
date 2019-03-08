#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<cstdio>
#include<vector>
#include<iostream>
#include<numeric>
#include<algorithm>
#include<cstring>
#include<set>
#define IL inline
#define RI register int

using namespace std;
int N,M, S;
int a[2001][2001],l[2001][2001],r[2001][2001],up[2001][2001],ans1,ans2;
int main() {
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 1; i <= N ; ++i) {
		for (int j = 1; j <= M; ++j) {
			scanf("%d", &a[i][j]);
			l[i][j] = r[i][j] = j;
			up[i][j] = i;
		}
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 2; j <= M; ++j) {
			if (a[i][j] != a[i][j - 1]) l[i][j] = l[i][j - 1];
		}
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = M - 1; j >= 1; --j) {
			if (a[i][j] != a[i][j + 1]) r[i][j] = r[i][j + 1];
		}
	}
	for (RI i = 1; i <= N; i++)
		for (RI j = 1; j <= M; j++)
		{
			if (i>1 && a[i][j] != a[i - 1][j])
			{
				l[i][j] = max(l[i][j], l[i - 1][j]);
				r[i][j] = min(r[i][j], r[i - 1][j]);
				up[i][j] = min(up[i][j], up[i-1][j]);
			}
			int a = r[i][j] - l[i][j] + 1; //横向长度
			int b = i - up[i][j] + 1;
			int c = min(a, b);
			ans1 = max(ans1, c*c);//正方形
			ans2 = max(ans2, a*b);//长方形
		}
	printf("%d\n%d", ans1, ans2);

}P1169 [ZJOI2007]
