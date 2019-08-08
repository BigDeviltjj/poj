#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
double a[10005];
int l, r;
int n, k;
int  main() {
    l = 0;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &a[i]);
        r = max(r, int(a[i]*100));
    }
    double best = 0;
    while (l <= r) {
        int mid = (l+r)>>1;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += a[i] / (double(mid)/100);
        }
        if (cnt >=k ) {
            l = mid + 1;
            best = mid;
        }
        else 
        {
            r = mid - 1;
        }
    }
    best /= 100;
    printf("%.2f\n", best);
}
    
