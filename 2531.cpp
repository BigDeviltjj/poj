#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int max_val = 0;
int C[21][21];
int flag[21];
int N;
int cnt = 0;
int curr = 0;

int update(int val, int x) {
    for (int i = 0; i < N; ++i) {
        if (flag[i] == 1) { val -= C[x][i];}
        else { val += C[x][i];}
    }
    return val;
}

void dfs(int n, int pos, int val) {
    if (n == 0) {
        if (val > max_val) max_val = val;
        return;
    }
    for (int i = pos; i < N;++i) {
        int val1 = update(val, i);
        flag[i] = 1;
        dfs(n - 1, i + 1, val1);
        flag[i] = 0;
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            scanf("%d", &C[i][j]);
        } 
    for (int i = 1; i <= N/2; ++i) {
        dfs(i, 0, 0);
    }
    cout<<max_val<<endl;
}

