#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int main() {
	int c,n,m;
	while (scanf("%d",&c) && c != 0) {
		scanf("%d %d", &n, &m);
		vector<double> dp(c + 1,0);
		dp[0] = 1;
//		if (m > n || m > c) { printf("%0.3f",0); }
//		if (n == 1 && m == 1 && c > 0) printf("%0.3f", 1);
		if (n > 2000) n = 2000 + n % 2;
		for (int i = 1; i <= n; ++i) {
			vector<double> tmp(dp);
			for (int j = 0; j <= c;++j) {
				dp[j] = ( j > 0 ? tmp[j-1] : 0.) * (c - j + 1) / c + (j < c ? tmp[j+1] : 0.) * (j + 1) / c;
			}	
		}
		if (m <= c) { printf("%0.3f\n", dp[m]); }
		else { printf("%0.3f\n", 0.); }
			
	}
}
