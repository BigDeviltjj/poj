#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
int N;
vector<int> tree[10001];
int tra[20002], pos[10001], dp[20002][15],idx = 0, dep[20002];
void dfs(int root, int depth) {
	tra[idx] = root;
	dep[idx++] = depth;

	if (pos[root] == -1) pos[root] = idx - 1;
	for (int i = 0; i < tree[root].size(); ++i) {
		dfs(tree[root][i], depth +1);
		tra[idx] = root;
		dep[idx++] = depth;

	}
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		memset(tree, 0, sizeof(tree));
		memset(pos, -1, sizeof(pos));
		idx = 0;
		cin >> N;
		vector<bool> flag(10001, 0);
		for (int i = 0; i < N - 1; ++i) {
			int s, e;
			cin >> s >> e;
			tree[s].push_back(e);
			flag[e] = 1;
		}
		for (int i = 1; i <= N; ++i) {
			if (!flag[i]) {
				dfs(i, 0);
				break;
			}
		}
		//cout << "trave:" << endl;
		//for (int i = 0; i < 2 * N - 1; ++i) {
		//	cout << tra[i] << " ";
		//}
		//cout << "pos:" << endl;
		//for (int i = 1; i <= N ; ++i) {
		//	if (pos[i] != -1) {
		//		cout << i << " : " << pos[i] << endl;	
		//	}
		//}
		//cout << "depth:" << endl;
		//for (int i = 0; i < 2 * N - 1; ++i) {
		//	cout << dep[i] << " ";
		//}
		for (int j = 0;(1<<j) < idx; ++j) {
			for (int i = 0; i + (1 <<j) -1 < idx; ++i) {
				if (j == 0) {
					dp[i][j] = dep[i];
				}
				else
				{
					dp[i][j] = dp[i][j - 1] < dp[i + (1<<(j-1))	][j - 1] ? dp[i][j - 1] : dp[i + (1 << (j - 1))][j - 1];
				}
			}
		}


		int x, y;
		cin >> x >> y;
		int k = 0;
		if (pos[x] > pos[y]) {
			swap(x, y);
		}
		while ( + (1 << (k + 1)) <= pos[y] - pos[x] + 1) {
			k++;
		}
		int min_val = min(dp[pos[x]][k], dp[pos[y] - (1 << (k)) + 1][k]);
		for (int i = pos[x]; i <= pos[y]; ++i) {
			if (dep[i] == min_val) {
				cout << tra[i] << endl;
				break;
			}
		}
	}
}
