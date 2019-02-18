#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;
int a[65];
bool mask[65];
int num;
bool cmp(int a, int b) {
	return a > b;
}
bool dfs(int n, int l, int sl, int first) {
	if (sl == 0 && n == 0) {
		return true;
	}
	else {
		if (sl == 0) {
			sl = l;
			n -= 1;
		}
		for (int i = first; i < num; ++i) {
			if (!mask[i] && a[i] <= sl) {
				if (i > 0 && a[i] == a[i - 1] && !mask[i - 1]) continue;
				if (sl == l) first = i;
				mask[i] = 1;
				if (dfs( n, l, sl - a[i], first)) return true;
				mask[i] = 0;
                                if (first == i || sl == a[i]) return false;
			}
		}
		return false;

	}
}
int main() {
	scanf("%d",&num);
	while (num != 0) {
		int max = 0, sum = 0;
		for (int i = 0; i < num; ++i) {
			scanf("%d",&a[i]);
			sum += a[i];
			max = max > a[i] ? max : a[i];
		}
		sort(a, a + num, cmp);

		for (int i = max; i <= sum; ++i)
		{
			if (!(sum % i == 0)) continue;
			memset(mask, 0 , sizeof(mask));
			if (dfs(sum / i - 1, i, i, 0)) {
				printf("%d\n", i); break;
			}
			if (i > sum / 2) {
				printf("%d\n", sum); break;
			}
		}
		scanf("%d",&num);
		
	}
}
