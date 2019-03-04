#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <utility>
#include <cstring>
using namespace std;	
int k,N,s;
int mod[101][10],flag[101][10001];
char n[101],  m[101];
void init() {
	for (int i = 0; i <= 100; ++i) {
		for (int j = 1; j <= 9; ++j) {
			if (i == 0)
				mod[i][j] = j % k;
			else
			{
				mod[i][j] = (mod[i - 1][j] * 10) % k;

			}

		}
	}
}
bool dfs(int pos, int num, int s){
	if (s == 0)	 return 1;
	if (pos == N) return 0;
	if (num == 0) return 0;
	if (num <= flag[pos][s]) return 0;
	for (int j = 0; j <= 9; ++j) {
		if (pos == 0 && j == 0) continue;
		if (j < n[pos]) {
			int tmp = n[pos];
			n[pos] = j;
			if (dfs(pos + 1, num - 1, (s - mod[N - 1 - pos][tmp - j] + k) % k)) return 1;
			n[pos] = tmp;
		}
		else
		{
			if (j > n[pos]) {
				int tmp = n[pos];
				n[pos] = j;
				if (dfs(pos + 1, num - 1, (s + mod[N - 1 - pos][j - tmp]) % k)) return 1;
				n[pos] = tmp;

			}
			else
			{
				if (dfs(pos + 1, num, s)) return 1;
			}
		}
	}
	flag[pos][s] = max(flag[pos][s], num);
	return 0;
}
int main() {
	while (cin>>n>>k) {
		N = strlen(n);
		init();
		for (int i = 0; i < N; ++i) {
			n[i] = n[i] - '0';
		}
		s = 0;
		for (int i = 0; i < N; ++i) {
			s = (s + mod[N - i - 1][n[i]]) % k;
		}
		memset(m, 0, sizeof(m));
		memset(flag, 0, sizeof(flag));
		for (int i = 0; i <= N; ++i) {
			if (dfs(0, i, s)) break;
		}
		for (int i = 0; i < N; ++i) {
			printf("%d", n[i]);
		}
		printf("\n");
	}
}
