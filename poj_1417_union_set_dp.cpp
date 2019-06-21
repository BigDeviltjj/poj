#include <iostream>
#include <map>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
int n, p1, p2;
int father[1001], r[1001];
int u[1001], v[1001];
int cnt;
int bag[1001][2];
char s[1001][4];
char yes[4] = "yes";
map<int, int> mp;
int dp[1001][301];
int get_father(int x) {
    if (father[x] == -1)
        return x;
    int temp = get_father(father[x]);
    r[x] = (r[x] + r[father[x]]) % 2;
    return father[x] = temp;
}

void Union(int x, int y, int same) {
    if (x == y) return;
    int fx = get_father(x), fy = get_father(y);
    if (fx == fy)
        return;
    else {
        r[fy] = (r[x] + r[y] + same) % 2;
        father[fy] = fx;
    }
}
int main() {
    while (~scanf("%d %d %d", &n, &p1, &p2)) {
        if(n==0&&p1==0&&p2==0)break;
        cnt = 0;
        mp.clear();
        int tribes = p1 + p2;
        memset(r, 0, sizeof(r));
        memset(father, -1, sizeof(father));
        memset(bag, 0, sizeof(bag));
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            //int a, b;
            //char str[10];
            scanf("%d %d %s", &u[i], &v[i], s[i]);
            if (s[i][0] == 'y') {
                Union(u[i], v[i], 0);
            }
            else 
            {
                Union(u[i], v[i], 1);
            }
        }


        for (int i = 1; i <= tribes; ++i) {
            if (mp.count(get_father(i)) == 0) 
                mp[get_father(i)] = ++cnt;
            bag[mp[get_father(i)]][r[i]]++;
        }

        dp[0][0] = 1;
        for (int i = 1; i <= cnt; ++i) {
            for (int j = 0; j <= p1; ++j) {
                dp[i][j] = (j - bag[i][0] >= 0 ? dp[i-1][j-bag[i][0]] : 0) + (j - bag[i][1] >= 0 ? dp[i-1][j-bag[i][1]] : 0);
            //    printf("%d %d %d\n", i, j, dp[i][j]);
            }
        }

        if (dp[cnt][p1] == 1) {
            int res[1001];
	        memset(res, -1, sizeof(res));
            int j = p1;
            for (int i = cnt; i>=1; --i) {
                if (dp[i-1][j-bag[i][0]] == dp[i][j]) 
                    res[i] = 0, j = j - bag[i][0];
                else if (dp[i-1][j-bag[i][1]] == dp[i][j])
                    res[i] = 1, j = j - bag[i][1];
            }
            for (int i = 1; i<=tribes; ++i) {
                //printf("%d\n", m[get_father(i)]);
                if (res[mp[get_father(i)]] == r[i]) printf("%d\n", i);
            }
	        printf("end\n");
        }
        else printf("no\n");
    }
}

