#include <vector>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
int m, n;
int position[101], vis[101], dis[101];
struct Edge {
    Edge() {}
    Edge(int u, int v, int w, int next):u(u), v(v), w(w), next(next){}
    int u, v, w, next;
};
Edge e[10001];
int head[101], cnt;
int spfa(int start, int min_pos) {
    queue<int> q;
    q.push(start);
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f3f3f3f, sizeof(vis));
    vis[0] = 1;
    dis[0] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i != -1; i = e[i].next) {
            int v = e[i].v, w = e[i].w;
            if (position[v] >= min_pos && position[v] <= min_pos+m && dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return dis[1];
}
int main() {
    memset(head, -1, sizeof(head));
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; ++i) {
        int pri, pos, num;
        scanf("%d%d%d",  &pri, &pos, &num);
        position[i] = pos;
        
        e[cnt] = Edge(0, i, pri, head[0]);
        head[0] = cnt++;
        for (int j = 0; j < num; ++j) {
            int u, val;
            scanf("%d%d", &u, &val);
            e[cnt] = Edge(u, i, val, head[u]);
            head[u] = cnt++;
        }
    }
    position[0] = position[1];
    int ans = 0x3f3f3f3f;
    for (int i = max(0, position[1] - m); i <= position[1]; ++i) {
        ans = min(ans, spfa(0, i));
    }
    printf("%d\n", ans);
}

