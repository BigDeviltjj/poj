#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
const int VAL = 1234567;
int a[100001][6];
vector<int> hash_table[VAL];
bool isSame(int x, int y) {
	for (int i = 0; i < 6; ++i) {
		if ((a[x][0] == a[y][i] &&
			a[x][1] == a[y][(i + 1) % 6] &&
			a[x][2] == a[y][(i + 2) % 6] &&
			a[x][3] == a[y][(i + 3) % 6] &&
			a[x][4] == a[y][(i + 4) % 6] &&
			a[x][5] == a[y][(i + 5) % 6]) ||(a[x][0] == a[y][i%6] &&
			a[x][1] == a[y][(i + 5) % 6] &&
			a[x][2] == a[y][(i + 4) % 6] &&
			a[x][3] == a[y][(i + 3) % 6] &&
			a[x][4] == a[y][(i + 2) % 6] &&
			a[x][5] == a[y][(i + 1) % 6])) {
			return true;
		}
	}
	return false;
}
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		int sum = 0;
		for (int j = 0; j < 6; ++j) {
			scanf("%d", &a[i][j]);
                        sum += a[i][j];
		}
		int key = sum % VAL;	
		for (int j = 0; j < hash_table[key].size(); ++j) {
			if (isSame(hash_table[key][j], i)) {
				printf("%s\n", "Twin snowflakes found.");
				return 0;
			}
		}
		hash_table[key].push_back(i);
	}
	printf("%s\n", "No two snowflakes are alike.");
}
