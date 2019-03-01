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
int N, Q;
int a[50000], maximum[50000][20], minimum[50000][20];
int main(){
	scanf("%d %d", &N, &Q);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &maximum[i][0]);
		minimum[i][0] = maximum[i][0];
	}
	for (int i = 1; i <= int(log2(N)); ++i)
		for (int j = 0; j < N - (1<< (i - 1));++j) {
			minimum[j][i] = min(minimum[j][i - 1], minimum[j + (1 << (i - 1))][i - 1]);
			maximum[j][i] = max(maximum[j][i - 1], maximum[j + (1 << (i - 1))][i - 1]);
	}
	for (int i = 0; i < Q; ++i) {
		int l, r;
		scanf("%d %d", &l, &r);
		l--, r--;
		int j = log2(r - l + 1);
		int big = max(maximum[l][j], maximum[r - (1 << j) + 1][j]), small = min(minimum[l][j], minimum[r - (1 << j) + 1][j]);
		printf("%d\n", big - small);
	}
}
