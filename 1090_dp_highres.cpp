//
// Created by SENSETIME\tangjiajie on 19-7-26.
//

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> dp[1001][2];
int a[1001];

vector<int> pow2;

void highResAdd(vector<int>& a, vector<int>& b, vector<int>& c) {
    int i = 0;
    int shi = 0;
    while (i < a.size() || i < b.size()) {
        int temp = (i >= a.size() ? 0 : a[i]) + (i >= b.size() ? 0 : b[i]) + shi;
        shi = temp / 10;
        if (i < c.size()) {
            c[i] = temp % 10;
        }
        else {
            c.push_back(temp % 10);
        }
        i++;
    }
    if (shi == 1) {
        c.push_back(1);
    }
}
void print(const vector<int>& v) {
    int start = 0;
    for (int i = v.size() - 1; i >= 0; --i) {
        if (v[i] == 0 && start == 0) {
            continue;
        }
        else {
            start = 1;
        }
        printf("%d", v[i]);
    }
    if (v.size() == 1 && v[0] == 0) printf("0");
    printf("\n");
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    if (n == 1) {
        printf("%d\n", a[n] == 1);
        return 0;
    }
    dp[1][0] = vector<int>(1, a[1] == 1);
    dp[1][1] = vector<int>(1, a[1] == 0);
    vector<int> pow2 = vector<int>(1, 2);

    for (int i = 2; i <= n; ++i) {
        if (a[i] == 1) {
            dp[i][1] = dp[i-1][0];
            highResAdd(dp[i-1][1], pow2, dp[i][0]);
//            highResAdd(dp[i][0], two, dp[i][0]);
        }
        else {
            dp[i][0] = dp[i-1][0];
            highResAdd(dp[i-1][1], pow2, dp[i][1]);
//            highResAdd(dp[i][1], two, dp[i][1]);
        }
        highResAdd(pow2, pow2, pow2);
    }
    print(dp[n][0]);
}
