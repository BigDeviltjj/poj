#include <vector>
#include <iostream>
#include <map>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int rel[101][101];
int color[101], cl[2];
int connect[101];
int cnt, n;
int dp[101][202];
vector<int> son[101][2];
map<int, vector<int> > pre;
bool dfs(int x, int c) {
    color[x] = c;
    cl[c]++;
    son[cnt][c].push_back(x);
    for (int i = 1; i <= n; ++i) {
        if (i == x) continue;
        if (rel[x][i] == 0 || rel[i][x] == 0) {
            if (color[i] == c) return 0;
            if (color[i] == 1-c) continue;
            if (!dfs(i, 1-c)) return 0;
        }
    }
    return 1;
}
int main() {
    scanf("%d", &n);
    memset(color, -1, sizeof(color));
    for (int i = 1; i <= n; ++i) {
        int x;
        while (scanf("%d", &x) && x != 0) {
            rel[i][x] = 1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (color[i] == -1) {
            cl[0] = cl[1] = 0;
            if (!dfs(i, 1)) {
                printf("No solution\n");
                return 0;
            }
            connect[cnt++] = cl[0] - cl[1];
        }
    }
    dp[0][n] = 1;
    for (int i = 1; i <= cnt; ++i) {
        for (int j = 0; j <= 2 * n; ++j) {
            if (dp[i-1][ j] == 1) {
                dp[i][ j + connect[i-1]] = 1;
                dp[i][ j - connect[i-1]] = 1;
            }
        }
    }
    int ans = 0;
    for (int j = n; j <= 2 * n; ++j) {
        if (dp[cnt][j] == 1) {
            int i = cnt;
            int temp = j;
            vector<int> s0, s1;
            while (i> 0) {
                if (dp[i-1][temp - connect[i-1]] == 1) {
                    temp -= connect[i-1];
                    s0.insert(s0.end(), son[i-1][0].begin(), son[i-1][0].end()); 
                    s1.insert(s1.end(), son[i-1][1].begin(), son[i-1][1].end()); 
                } 
                else {
                    temp += connect[i-1];
                    s1.insert(s1.end(), son[i-1][0].begin(), son[i-1][0].end()); 
                    s0.insert(s0.end(), son[i-1][1].begin(), son[i-1][1].end()); 
                }
                i--;
            }
            printf("%d", s0.size());
            for (int i = 0; i < s0.size(); ++i) {
                printf(" %d", s0[i]);
            }
            printf("\n");
            printf("%d", s1.size());
            for (int i = 0; i < s1.size(); ++i) {
                printf(" %d", s1[i]);
            }
            printf("\n");
            break;

        }
    }
}

