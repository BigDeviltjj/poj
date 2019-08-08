#include <algorithm>
#include <cstring>
#include <queue>
#include <utility>
#include <cstdio>
#include <iostream>
using namespace std;
int w, h; int a[77][77]; int dist[77][77], vis[77][77];
int dir[4][2] = {{-1,0}, {0,-1}, {1,0}, {0,1}};
struct st {
    st() {}
    st(int x, int y, int dir) : x(x), y(y), dir(dir) {}
    int x, y, dir;
};
bool check(int x, int y) {
    if (x>=0 && x<= h+1 && y >= 0 && y <= w+1 && a[x][y] == 0 && vis[x][y] == 0) return 1;
    return 0;
}
int bfs(int x0, int y0, int x1, int y1) {
    queue<st> q;
    q.push(st(x0, y0, 0));
    vis[x0][y0] = 0;
    while (!q.empty()) {
        st u = q.front();
        q.pop();
        if (u.x == x1 && u.y == y1) return vis[u.x][u.y];
        for (int i = 0; i < 4; ++i) {
            st v = u;
            while (check(v.x + dir[i][0], v.y + dir[i][1])) {
                v.x += dir[i][0];
                v.y += dir[i][1];
                vis[v.x][v.y] = vis[u.x][u.y]+1;
                q.push(v);
            }
        }
    }
    return -1;
}
int main() {
	int t = 1;
    while (scanf("%d%d", &w, &h) && w != 0 && h != 0) {
		printf("Board #%d:\n", t++);
        memset(a, 0, sizeof(a));
        for (int i = 1; i <=h; ++i) {
            getchar();
            for (int j = 1; j <= w; ++j) {
                char c;
                scanf("%c", &c);
                if (c == 'X') a[i][j] = 1;
            }
        }
        int cnt = 0;
        while (true && ++cnt) {
            int x0, y0, x1, y1;
            scanf("%d%d%d%d", &y0, &x0, &y1, &x1);
            if (y0 == 0 && y1 == 0 && x0 == 0 && x1 == 0) {
                break;
            }
            memset(vis, 0, sizeof(vis));
            a[x1][y1] = 0;
            int ans = bfs(x0, y0, x1, y1);
            a[x1][y1] = 1;
			if (ans == -1) {
				printf("Pair %d: impossible.\n", cnt);
			}
			else {
				printf("Pair %d: %d segments.\n", cnt, ans);
			}
        }
	    printf("\n");
    }
}

