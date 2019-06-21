#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;
int a[5001], d[5001], c[5001], num[5001];
int ans1 = 0, ans2 = 0;
int main() {
    int n;
    scanf("%d", &n);
    for (int i =0; i < n; ++i) d[i] = c[i] = 1;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        for (int j = i - 1; j >= 0; --j) {
            if (a[i] < a[j]) {
                if (d[i] < d[j] + 1) {
                    d[i] = d[j] + 1;
                    c[i] = c[j];
                }
                else 
                    if (d[i] == d[j] + 1) {
                        c[i] += c[j];     
                    }
            }
            else if (a[i] == a[j]) {
                if (d[i] == 1) c[i] = 0;
                break;
            }
        }
        if (d[i] > ans1) {
            ans1 = d[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        if (d[i] == ans1) ans2 += c[i];
    }
    printf("%d %d\n", ans1, ans2);
}
