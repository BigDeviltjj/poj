#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
int n, k;
int ans;
char a[9][9];
bool c[9];
void dfs(int x, int k) {
        if (k == 0) {
                ans++;
                return;
        }
        if (x >= n) return;
        for (int j = 0; j < n; ++j) {
                if (c[j] == 0 && a[x][j] == '#')
                {
                        c[j] = 1;
                        dfs(x+1, k-1);
                        c[j] = 0;
                }
        }
        dfs(x+1,k);
}

int main() {
        while (scanf("%d%d", &n, &k) && n != -1) {
                for (int i = 0; i < n; ++i) {
                        char ch;
                        getchar();
                        for (int j = 0; j < n; ++j) {
                                scanf("%c", &a[i][j]);
                        }
                }
                memset(c, 0, sizeof(c));
                ans = 0;
                dfs(0, k);
                cout<<ans<<endl;
        }
}

