#define _CRT_SECURE_NO_WARNINGS
#define cal(x) (i##x * i##x * i##x  *a[x])
#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<map>
using namespace std;
int hashtable[1100000];

int main() {
	int a[5];
	for (int i = 0; i < 5; ++i) {
		scanf("%d", &a[i]);
	}
	int ans = 0;
	int cnt = 0;
	for (int i0 = -50;i0<=50;++i0)
		for (int i1 = -50; i1 <= 50; ++i1)
			for (int i2 = -50; i2 <= 50; ++i2)
			{
				if (i1 != 0 && i2 != 0 && i0 != 0) {
					hashtable[cnt++] = cal(0) + cal(1) + cal(2);
				}
			}
	sort(hashtable, hashtable + cnt);
	for (int i3 = -50;i3<=50;++i3)
		for (int i4 = -50; i4 <= 50; ++i4) {
			if (i4 == 0 || i3 == 0) continue;
			int tmp = -cal(3) - cal(4);
			ans += upper_bound(hashtable, hashtable + cnt, tmp) - lower_bound(hashtable, hashtable + cnt, tmp);
		}
	printf("%d\n", ans);
	system("pause");
} 
