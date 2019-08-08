#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
int prime[1001], check[1001];
int main() {
    int n, c;
    memset(check, 0, sizeof(check));
    for (int i = 2; i <=  1000; ++i) {
        if (check[i] == 1) continue;
        for (int j = 2;; ++j) {
            if (i * j > 1000) break;
            check[i * j] = 1;
        }
    }
    int cnt = 0;
    prime[cnt++] = 1;
    for (int i = 2; i <= 1000; ++i) {
        if (!check[i]) prime[cnt++] = i;
    }
    while (~scanf("%d%d", &n, &c)) {
        int end = upper_bound(prime, prime + cnt, n) - prime;
        printf("%d %d:", n, c);
        if (end % 2 == 0) {
            int s = max(0, end / 2 - c), e = min(end, end / 2 + c);
            for (int i = s; i < e; ++i) {
                printf(" %d", prime[i]);
            }
        }
        else {
            int s = max(0, end / 2 - c + 1), e = min(end, end / 2 + c);
            for (int i = s; i < e; ++i) {
                printf(" %d", prime[i]);
            }
        }
        printf("\n\n");
    }
}
