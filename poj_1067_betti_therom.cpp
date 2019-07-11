#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <fstream>
using namespace std;
#define MAXN 1000000001
#define k (sqrt(5)+1)/2.0
bool used[MAXN];

int main() {
    long a, b;
    while (~scanf("%ld %ld", &a, &b)) {
        if (a > b) {
            a = a+b;
            b = a-b;
            a = a-b;
        }
        printf("%d\n", a  != int(k*(b-a)));
    }
}
