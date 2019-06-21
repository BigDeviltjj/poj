#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge {
    Edge() {}
    Edge(int u_, int v_, int next_) : u(u_), v(v_), next(next_){}
    int u, v, next;
};
int N, cnt, ans, t;
int head[201], vis[101], dfn[101],  low[101], flag[101];
Edge e[200001];
void add_edge(int u, int v) {
    e[cnt] = Edge(u, v, head[u]);
    head[u] = cnt++;
    e[cnt] = Edge(v, u, head[v]);
    head[v] = cnt++;
}
void tarjan(int u, int pre) {
    vis[u] = 1;
    dfn[u] = low[u] = t++;
    int k = 0;
    for (int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if (!vis[v]) {
            k++;
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if ((u == 1 && k == 2) || (u != 1 && low[v] >= dfn[u]))
                flag[u] = 1;
        }
        else low[u] = min(low[u], dfn[v]);
    }
    ans += flag[u];

}
int main() {
    int n;
    while (~scanf("%d", &n) && n) {
        memset(head, -1, sizeof(head));
        cnt = 0;
        ans = 0;
        t = 0;
        memset(vis, 0, sizeof(vis));
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        memset(flag, 0, sizeof(flag));

        int u;
        while (~scanf("%d", &u) && u) {
            int v;
            while (getchar() != '\n') {
                scanf("%d", &v);
                add_edge(u, v);
            }
        }
        tarjan(1, 1);
        printf("%d\n", ans);
    }
}
