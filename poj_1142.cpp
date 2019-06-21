#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int getsum(int i) {
    int ret = 0;
    while (i != 0) {
        ret += i % 10;
        i /= 10;
    }
    return ret;
}
int get_prime(int x) {
    int ans = 0;
    int temp = x;
    for (int i = 2; i * i <= temp; ++i) {
        if (x % i == 0) {
            while (x % i == 0) {
                x = x / i;
                ans += getsum(i);
            }
        }
    }
    if (x > 1 && x != temp) ans += getsum(x);
    return ans;
}

int main() {
    int n;
    while (~scanf("%d", &n) && n) {
        for (int i = n + 1;; ++i) {
            int sum = getsum(i);
            if (sum == get_prime(i)) {
                cout<<i<<endl;
                break;
            }
        }
    }
}
