#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
int main() {
    long long k;
    scanf("%lld", &k);
    long long ks = k*k+1;
    int a, b;
    int ans = 0x3f3f3f3f;
    for (int i = int(sqrt(ks-1)); i >= 1; --i)
    {
        if (ks % i == 0) 
        {
            a = i;
            b = ks / a;
            ans = a+b+k+k > ans ? ans : a+b+k+k;
            std::cout<<a<<" "<<b<<std::endl;
            printf("%d\n", ans);
            break;
        }
    }
}



