#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<map>
#include<string>
using namespace std;
string mesg;
int L, W;
string dict[600];
int dp[300];
int main() {
	cin >> W >> L;
	cin >> mesg;
	for (int i = 0; i < W; ++i) {
		cin >> dict[i];
	}
	for (int i = L - 1; i >= 0; --i) {
		dp[i] = dp[i + 1] + 1;
		for (int j = 0; j < W; ++j) {
			if (dict[j][0] == mesg[i] && L - i >= dict[j].length()) {
				int pm = i, pd = 0;
				while (pm < L) {
					if (dict[j][pd] == mesg[pm]) {
						pm++, pd++;
					}
					else
					{
						pm++;
					}
					if (pd == dict[j].length()) {
						dp[i] = min(dp[i], dp[pm] + pm - i - pd);
						break;
					}
				}
			}
		}
	}
	cout << dp[0] << endl;
	system("pause");
} 
