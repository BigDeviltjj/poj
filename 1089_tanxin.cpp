//
// Created by SENSETIME\tangjiajie on 19-7-26.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <utility>
using namespace std;
pair<int, int> a[50001];
bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &a[i].first, &a[i].second);
    }
    sort(a, a + n, cmp);
    int s = a[0].first, e = a[0].second;
    for (int i = 0; i < n; ++i) {
        if (a[i].first > e) {
            printf("%d %d\n", s, e);
            s = a[i].first;
            e = a[i].second;
        }
        else {
           e = max(e, a[i].second);
        }
    }
    printf("%d %d\n", s, e);
}
