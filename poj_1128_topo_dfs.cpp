#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
struct Box {
    Box() : t(31), b(-1), l(31), r(-1) {}
    int t,b,l,r;
}b[26];
int h, w;
char m[31][31];
bool map[31][31];
int pre[26], cnt;
string ans;
void dfs(int pos) {
    if (pos == cnt) {
        cout<<ans<<endl;
        return;
    }
    for (int i = 0; i < 26; ++i) {
        if (pre[i] == 0) {
            pre[i] = -1;
            ans[pos] = i + 'A';
            for (int j = 0; j < 26; ++j) {
                if (map[i][j])
                    pre[j]--;
            }
            dfs(pos+1);
            pre[i] = 0;
            for (int j = 0; j < 26; ++j) {
                if (map[i][j])
                    pre[j]++;
            }
        }
    }
}
int main() {

    while (scanf("%d%d", &h, &w) == 2) {
        memset(pre, -1, sizeof(pre));
        memset(map, 0, sizeof(map));
        cnt = 0;
        for (int i = 0; i < 26; ++i) b[i] = Box();
        char c;
        for (int i = 0; i < h; ++i) {
            scanf("%s", &m[i]);
            for (int j = 0; j < w; ++j) {
                m[i][j] -= 'A';
                c = m[i][j];
                if (c >= 0 && c <  26) {
                    b[c].t = min(b[c].t, i);
                    b[c].b = max(b[c].b, i);
                    b[c].l = min(b[c].l, j);
                    b[c].r = max(b[c].r, j);
                    pre[c] = 0;
                }
            }
        }

        for (int i = 0; i < 26; ++i) {
            if (pre[i] == -1) 
                continue;
            cnt++;
            for (int j = b[i].t; j <= b[i].b; ++j)
                for (int k = b[i].l; k <= b[i].r; ++k) {
                    if (j > b[i].t && j < b[i].b && k > b[i].l && k < b[i].r) continue;
                    if (i != m[j][k] && !map[i][m[j][k]]) {
                        map[i][m[j][k]] = 1;
                        pre[m[j][k]]++;
                    }
                }
        }
        ans = string(cnt, '\0');
        dfs(0);
    }
}
