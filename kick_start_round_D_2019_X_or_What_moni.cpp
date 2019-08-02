#include <iostream>
#include <set>
#include <cstdio>
#include <vector>
using namespace std;
int Count(int val)
{
    int num = 0;
    while(val)
    {
        val &= (val -1);
        ++num;
    }
    return num;
}

int main() {
    int T;
    int cnt = 0;
    scanf("%d", &T);
    while (T--) {
        printf("Case #%d: ", ++cnt);
        int N, Q;
        scanf("%d%d", &N, &Q);
        vector<int> a;
        set<int> idx;
        for (int i = 0; i < N; ++i) {
            int x;
            scanf("%d", &x);
            a.push_back(x);
            if (Count(x) % 2 == 1) idx.insert(i);
        }
        for (int i = 0; i < Q; ++i) {
            int p, v;
            scanf("%d%d", &p, &v);
            if (Count(a[p]) % 2 != Count(v) % 2) {
                if (Count(a[p]) % 2 == 0) {
                    idx.insert(p);
                } else {
                    idx.erase(p);
                }
                a[p] = v;
            }
            if (idx.empty()) {
                printf("%d", N);
                if (i == Q - 1) printf("\n");
                else printf(" ");
                continue;
            }
            set<int>::iterator it = idx.end();
            it--;
            int ans = max(N - *idx.begin() - 1, *(it));
            if (idx.size() % 2 == 0) ans = N;
            printf("%d", ans);
            if (i == Q - 1) printf("\n");
            else printf(" ");
        }
    }
}
