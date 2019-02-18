#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
using namespace std;
int head[10001];
int next[10001];
int node[10001];
int father[10001];
int color[10001];
int T, N, pos, x, y;

int get_father(int x) {
    if (x == father[x]) return x;
    else return father[x] = get_father(father[x]);
}

void dfs(int u) {
    father[u] = u;
    for (int i = head[u]; i != -1; i = next[i]) {
        dfs(node[i]);
        father[node[i]] = u;
    }
    color[u] = 1;
    if (color[x] == 1 && color[y] == 1) {
        printf("%d\n",get_father(x));
    }
}

int main() {
    scanf("%d", &T);
    while (T--) {
        memset(head, -1, sizeof(head));
        memset(next, -1, sizeof(next));
        memset(node, -1, sizeof(node));
        memset(father, -1, sizeof(father));
        memset(color, -1, sizeof(color));
        vector<int> is_head(10001,1);
        scanf("%d", &N);
        for (int i = 0; i < N - 1; ++i) {
            int s, e;
            scanf("%d %d", &s, &e);
            node[pos] = e;
            next[s] = head[s];
            head[s] = pos++;
            is_head[e] = 0;
        }
        scanf("%d %d", &x, &y);
        for (int i = 1; i < N; ++i) 
            if (is_head[i] == 1) { dfs(i); break;}
    }
    return 0;
}

        

        

