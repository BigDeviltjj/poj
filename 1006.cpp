#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int cnt = 0;
    int a,b,c,d;
    while(cin>>a>>b>>c>>d) {
        if (a == -1 && b == -1 && c == -1 && d == -1) return 0;
        a %= 23; b %= 28; c %= 33;
        int d28 = (c - b) * 13;
        int d33 = (c - b) * 11;
        int common_bc = 28 * d28 + b;
        common_bc %= 924;
        while (common_bc <= d) common_bc += 924;
        while (true) {
            if ((common_bc - a) % 23 == 0) {
                printf("Case %d: the next triple peak occurs in %d days.\n", ++cnt, common_bc - d);
                break;
            }
            else common_bc += 924;
        
        
        }

        
    }
}
