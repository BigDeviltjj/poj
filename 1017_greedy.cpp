#include <iostream>
#include <cstdio>
using namespace std;
int two[4] = {0, 5, 3, 1};
int a[7];
int main() {
    while (true) {
        int sum = 0;
        for (int i = 1; i < 7; ++i) {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        if (sum == 0) return 0;
        int ans = 0;
        ans = a[6] + a[5] + a[4] + (a[3]+3)/4;
        int left2 = a[4] * 5 + two[a[3] % 4];
        if (a[2] > left2) {
            ans += (a[2] - left2 + 8) / 9;
        }
        int left1 = ans * 36 - a[6]*36 - a[5] *25 - a[4] *16 - a[3] * 9 - a[2] * 4;
        if (left1 < a[1]) {
            ans += (a[1] - left1 + 35) / 36;
        }
        printf("%d\n", ans);
    }
}

