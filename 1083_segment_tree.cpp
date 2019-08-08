#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int n, t;
int add[10000], num[10000];
int ans;
void popdown(int i) {
    if (add[i] != 0) {
        num[i*2] += add[i];
        num[i*2+1] += add[i];
        add[i*2] += add[i];
        add[i*2+1] += add[i];
        add[i] = 0;
    }
}
void update(int i, int ql, int qr, int l, int r) {
    if (ql <= l && qr >= r) {
        add[i]++;
        num[i]++;
        return;
    }
    popdown(i);
    int mid = (l+r)>>1;
    if (ql <= mid) update(i*2, ql, qr, l, mid);
    if (qr > mid) update(i*2+1,ql, qr, mid+1, r);
    num[i] = max(num[i*2], num[i*2+1]);
    ans = max(ans, num[i]);
}
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        memset(num, 0, sizeof(num));
        memset(add, 0, sizeof(add));
        ans = 0;
        for (int i = 0; i < n; ++i) {
            int l, r;
            scanf("%d %d", &l, &r);
            l = (l+1)/2;
            r = (r+1)/2;
            if (l > r)
                swap(l, r);
            update(1, l, r, 1, 400);
        }
        printf("%d\n", ans * 10);
    }
}

