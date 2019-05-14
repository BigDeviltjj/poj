#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
int father[1000005];
int flag[1000005];
int getFather(int x) {
    if (father[x] == -1)
        return x;
    else return father[x] = getFather(father[x]);
}

int Union(int x, int y) {
    int fy = getFather(y);
    int fx = getFather(x);
    if (fy != y) {
        return 1;
    }
    if (fx == fy) {
        return 1;
    }
    father[fy] = fx;
    return 0;
}

int main() {
    int x, y;
    int idx = 0;
    while(true) {
        idx++;
        memset(father, -1, sizeof(father));
        memset(flag, 0, sizeof(flag));
        int k = 0;
        int MAX = 0;
        while (scanf("%d %d", &x, &y) && x > 0 && y > 0) {
            k += Union(x, y);
            MAX = max(max(x,MAX), y);
            flag[x] = flag[y] = 1;
        }
        if (x < 0 && y < 0)
            break;
        int rootNum = 0;
        for (int i = 1; i <= MAX; ++i) {
            if (flag[i] && father[i] == -1) {
                rootNum++;
            }
        }
        if (rootNum > 1 || k != 0 ) {
            printf("Case %d is not a tree.\n", idx);
        }
        else printf("Case %d is a tree.\n", idx);
    }
}
