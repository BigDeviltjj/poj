#include <cstdio>
#include <bitset>
#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <utility>
#include <cmath>
using namespace std;
const int MAXN = 1148576;
int dis[MAXN];
int n, m, dst;
struct Patch {
    int time;
    string s,e;
};
Patch p[101];
struct Node {
    Node(int t, int s):t(t), s(s) {}
    int t, s;
    Patch pa;
    bool operator<(const Node &rhs) const {
        return t > rhs.t;
    }
};
bool check(int curState, int ind, int &dstState) {
    for (int i = 0; i < n; ++i) {
        if (p[ind].s[i] == '-' && ((curState & (1 <<i)) == 0)) return false;
        if (p[ind].s[i] == '+' && ((curState & (1 <<i)) > 0)) return false;
    }
    dstState = 0;


    dstState = curState;
    for (int i = 0; i < p[ind].e.size(); ++i) {
        if (p[ind].e[i] == '+') 
            dstState &= (dst - (1<<i));
        if (p[ind].e[i] == '-')
            dstState |= (1<<i);
    }
    return true;
}


void bfs(int ca) {
    priority_queue<Node> q;
    q.push(Node(0, 0));
    dis[0] = 1;
    int ans=10000000;
    while (!q.empty()) {
        Node cur = q.top();
        q.pop();
        if (cur.t > ans) break;
        if (cur.s == dst) {
            printf("Product %d\nFastest sequence takes %d seconds.\n\n", ca, cur.t);
            return;
        }
        for (int i = 0; i < m; ++i) {
            int s;
            if (check(cur.s, i, s)) {
//			  if (Check(i, cur.s, s)) {
                if (!dis[s] || cur.t + p[i].time < dis[s]) {
                    q.push(Node(cur.t + p[i].time, s));
                    dis[s] = cur.t + p[i].time;
                }
            }
        }
    }
    printf("Product %d\nBugs cannot be fixed.\n\n", ca);
}

int main() {
    int ca = 1;
    while(cin>>n>>m) {
        if (n == 0 && m == 0)
            break;
        dst = (1<<n) - 1;
        memset(dis, 0, sizeof(dis));
        for (int i = 0; i < m; ++i) {
            cin>>p[i].time>>p[i].s>>p[i].e;
        }
        bfs(ca++);
    }
}

