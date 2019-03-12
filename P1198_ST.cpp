#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#define INF 0x3f3f3f3f
const long long MOD = pow(10,9) + 7;
using namespace std;
long long st[200000][20];
long long a[200000];
int M, cnt = 0;
long long D;
void update(int val) {
    int j = 0;
    while ( 1 + cnt >= (1<<j)) {
        if (j == 0)
            st[1 + cnt - (1<<j)][j] = val;
        else
            st[1 + cnt - (1<<j)][j] = max(st[1+cnt-(1<<(j-1))][j-1],st[1 + cnt - (1<<j)][j-1]);
        j++;
    }
    cnt++;
}
int main() {
    scanf("%d %lld", &M, &D);
    char c;
    long long n;
    long long ret = 0;
    for (int i = 0; i <  M; ++i) {
        scanf(" %c %lld", &c, &n);
        if (c == 'A') {
            n = (ret + n) %  D;
            update(n);
        }
        else {
           int j = log(n) / log(2);
           ret = max(st[cnt - (1<<j)][j],st[cnt - n][j]);
           printf("%lld\n",ret);
        }
    }
}
