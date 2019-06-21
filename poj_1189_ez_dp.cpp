#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
long long ball[51][51];
bool map[51][51];
LL GCD(LL x,LL y)
{
    if(y==0)
        return x;
    return GCD(y,x%y);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    ball[0][1] = (LL)1<<n;
    for (int i = 1; i <= n; ++i) {
        char c;
        for (int j = 1; j <=i; ++j) {
            while (~scanf("%c", &c) && (c != '*' && c != '.'));
            map[i][j] = (c == '*');
        }
    }
    for (int i = 1; i<=n; ++i)
        for (int j = 1; j <=n; ++j) {
            if (map[i][j] == 1) {
                ball[i][j] += ball[i-1][j]/2;
                ball[i][j+1] += ball[i-1][j]/2;
                //cout<<ball[i][j]<<" "<<ball[i][j+1]<<endl;
            }
            else {
                ball[i+1][j+1] = ball[i-1][j];
                //cout<<ball[i+1][j+1]<<endl;
            }
        }
    long long ans = ball[n][m+1], fenmu = (LL)1<<n;
    LL gcd = GCD(fenmu, ans);
    if (ans == 0) {
        printf("0/1\n");
    }
    else printf("%lld/%lld\n", ans/gcd, fenmu/gcd);
}

